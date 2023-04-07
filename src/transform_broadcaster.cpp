#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{

    float offsetX = 0;    // Middle
    float offsetY = 0.23; // Front face
    float offsetZ = 0.43; // 17 inches above base

    ros::init(argc, argv, "robot_tf_publisher");
    ros::NodeHandle nh;

    ros::Rate r(100);

    tf::TransformBroadcaster broadcaster;

    while (nh.ok())
    {
        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(offsetX, offsetY, offsetZ)),
                ros::Time::now(), "base_link", "base_lidar"));

        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0, 0, 0)),
                ros::Time::now(), "map","base_link"));

        r.sleep();
    }
}