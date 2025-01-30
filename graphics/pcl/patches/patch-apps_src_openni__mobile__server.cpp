$NetBSD: patch-apps_src_openni__mobile__server.cpp,v 1.1 2025/01/30 22:07:41 wiz Exp $

Prepare for Boost 1.87
https://github.com/PointCloudLibrary/pcl/commit/6f64495840c4e5674d542ccf20df96ed12665687

--- apps/src/openni_mobile_server.cpp.orig	2024-05-03 12:14:21.000000000 +0000
+++ apps/src/openni_mobile_server.cpp
@@ -157,7 +157,7 @@ public:
 
     viewer_.showCloud(getLatestPointCloud());
 
-    boost::asio::io_service io_service;
+    boost::asio::io_context io_service;
     tcp::endpoint endpoint(tcp::v4(), static_cast<unsigned short>(port_));
     tcp::acceptor acceptor(io_service, endpoint);
     tcp::socket socket(io_service);
