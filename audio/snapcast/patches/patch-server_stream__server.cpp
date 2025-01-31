$NetBSD: patch-server_stream__server.cpp,v 1.1 2025/01/31 16:20:06 wiz Exp $

Fix build with boost 1.87.

--- server/stream_server.cpp.orig	2025-01-31 15:59:00.212634193 +0000
+++ server/stream_server.cpp
@@ -220,7 +220,7 @@ void StreamServer::start()
         {
             LOG(INFO, LOG_TAG) << "Creating stream acceptor for address: " << address << ", port: " << settings_.stream.port << "\n";
             acceptor_.emplace_back(make_unique<tcp::acceptor>(net::make_strand(io_context_.get_executor()),
-                                                              tcp::endpoint(boost::asio::ip::address::from_string(address), settings_.stream.port)));
+                                                              tcp::endpoint(boost::asio::ip::make_address(address), settings_.stream.port)));
         }
         catch (const boost::system::system_error& e)
         {
