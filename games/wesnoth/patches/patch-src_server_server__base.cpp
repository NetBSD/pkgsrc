$NetBSD: patch-src_server_server__base.cpp,v 1.1 2019/09/02 17:50:33 nia Exp $

Remove redundant std::ref causing problems with Boost 1.70

--- src/server/server_base.cpp.orig	2019-04-12 01:05:54.000000000 +0000
+++ src/server/server_base.cpp
@@ -65,7 +65,7 @@ void server_base::start_server()
 
 void server_base::serve()
 {
-	socket_ptr socket = std::make_shared<boost::asio::ip::tcp::socket>(std::ref(io_service_));
+	socket_ptr socket = std::make_shared<boost::asio::ip::tcp::socket>(io_service_);
 	acceptor_.async_accept(*socket, std::bind(&server_base::accept_connection, this, _1, socket));
 }
 
