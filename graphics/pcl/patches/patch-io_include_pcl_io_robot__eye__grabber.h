$NetBSD: patch-io_include_pcl_io_robot__eye__grabber.h,v 1.1 2025/01/30 22:07:41 wiz Exp $

Prepare for Boost 1.87
https://github.com/PointCloudLibrary/pcl/commit/6f64495840c4e5674d542ccf20df96ed12665687

--- io/include/pcl/io/robot_eye_grabber.h.orig	2024-05-03 12:14:21.000000000 +0000
+++ io/include/pcl/io/robot_eye_grabber.h
@@ -131,7 +131,7 @@ namespace pcl
 
       boost::asio::ip::address sensor_address_;
       boost::asio::ip::udp::endpoint sender_endpoint_;
-      boost::asio::io_service io_service_;
+      boost::asio::io_context io_service_;
       std::shared_ptr<boost::asio::ip::udp::socket> socket_;
       std::shared_ptr<std::thread> socket_thread_;
       std::shared_ptr<std::thread> consumer_thread_;
