$NetBSD: patch-server_control__server.cpp,v 1.1 2025/01/31 16:20:06 wiz Exp $

Fix build with boost-1.87.
Based on
https://github.com/badaix/snapcast/commit/6ada939adf5c4f7e43d0fbe6ea45492b9564cb8d

--- server/control_server.cpp.orig	2025-01-31 15:55:59.143276181 +0000
+++ server/control_server.cpp
@@ -156,7 +156,7 @@ void ControlServer::start()
             {
                 LOG(INFO, LOG_TAG) << "Creating TCP acceptor for address: " << address << ", port: " << tcp_settings_.port << "\n";
                 acceptor_tcp_.emplace_back(make_unique<tcp::acceptor>(net::make_strand(io_context_.get_executor()),
-                                                                      tcp::endpoint(boost::asio::ip::address::from_string(address), tcp_settings_.port)));
+                                                                      tcp::endpoint(boost::asio::ip::make_address(address), tcp_settings_.port)));
             }
             catch (const boost::system::system_error& e)
             {
@@ -172,7 +172,7 @@ void ControlServer::start()
             {
                 LOG(INFO, LOG_TAG) << "Creating HTTP acceptor for address: " << address << ", port: " << http_settings_.port << "\n";
                 acceptor_http_.emplace_back(make_unique<tcp::acceptor>(net::make_strand(io_context_.get_executor()),
-                                                                       tcp::endpoint(boost::asio::ip::address::from_string(address), http_settings_.port)));
+                                                                       tcp::endpoint(boost::asio::ip::make_address(address), http_settings_.port)));
             }
             catch (const boost::system::system_error& e)
             {
