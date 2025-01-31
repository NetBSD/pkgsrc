$NetBSD: patch-server_streamreader_tcp__stream.cpp,v 1.1 2025/01/31 16:20:06 wiz Exp $

Fix build with boost 1.87.

--- server/streamreader/tcp_stream.cpp.orig	2025-01-31 16:01:18.779914892 +0000
+++ server/streamreader/tcp_stream.cpp
@@ -64,7 +64,7 @@ TcpStream::TcpStream(PcmStream::Listener
 
     LOG(INFO, LOG_TAG) << "TcpStream host: " << host_ << ", port: " << port_ << ", is server: " << is_server_ << "\n";
     if (is_server_)
-        acceptor_ = make_unique<tcp::acceptor>(strand_, tcp::endpoint(boost::asio::ip::address::from_string(host_), port_));
+        acceptor_ = make_unique<tcp::acceptor>(strand_, tcp::endpoint(boost::asio::ip::make_address(host_), port_));
 }
 
 
@@ -91,7 +91,7 @@ void TcpStream::do_connect()
     else
     {
         stream_ = make_unique<tcp::socket>(strand_);
-        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(host_), port_);
+        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address(host_), port_);
         stream_->async_connect(endpoint, [this](const boost::system::error_code& ec) {
             if (!ec)
             {
