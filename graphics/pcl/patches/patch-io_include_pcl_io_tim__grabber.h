$NetBSD: patch-io_include_pcl_io_tim__grabber.h,v 1.1 2025/01/30 22:07:41 wiz Exp $

Prepare for Boost 1.87
https://github.com/PointCloudLibrary/pcl/commit/6f64495840c4e5674d542ccf20df96ed12665687

--- io/include/pcl/io/tim_grabber.h.orig	2024-05-03 12:14:21.000000000 +0000
+++ io/include/pcl/io/tim_grabber.h
@@ -128,7 +128,7 @@ class PCL_EXPORTS TimGrabber : public Gr
     std::vector<float> distances_;
 
     boost::asio::ip::tcp::endpoint tcp_endpoint_;
-    boost::asio::io_service tim_io_service_;
+    boost::asio::io_context tim_io_service_;
     boost::asio::ip::tcp::socket tim_socket_;
     //// wait time for receiving data (on the order of milliseconds)
     unsigned int wait_time_milliseconds_ = 0;
