$NetBSD: patch-apps_src_openni__organized__compression.cpp,v 1.1 2025/01/30 22:07:41 wiz Exp $

Prepare for Boost 1.87
https://github.com/PointCloudLibrary/pcl/commit/6f64495840c4e5674d542ccf20df96ed12665687

--- apps/src/openni_organized_compression.cpp.orig	2024-05-03 12:14:21.000000000 +0000
+++ apps/src/openni_organized_compression.cpp
@@ -438,7 +438,7 @@ main(int argc, char** argv)
     if (bEnDecode) {
       // ENCODING
       try {
-        boost::asio::io_service io_service;
+        boost::asio::io_context io_service;
         tcp::endpoint endpoint(tcp::v4(), 6666);
         tcp::acceptor acceptor(io_service, endpoint);
 
@@ -446,7 +446,7 @@ main(int argc, char** argv)
 
         std::cout << "Waiting for connection.." << std::endl;
 
-        acceptor.accept(*socketStream.rdbuf());
+        acceptor.accept(socketStream.rdbuf()->socket());
 
         std::cout << "Connected!" << std::endl;
 
