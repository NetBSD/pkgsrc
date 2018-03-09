$NetBSD: patch-host_lib_transport_tcp_zero_copy.cpp,v 1.1 2018/03/09 11:36:40 mef Exp $

PR pkg/52969
with the boost libs updated to 2.6 there are changes so that socket->native()
is no longer supported. use socket->native_handle() instead

--- lib/transport/tcp_zero_copy.cpp
+++ lib/transport/tcp_zero_copy.cpp.orig
@@ -154,7 +154,7 @@
         //create, open, and connect the socket
         _socket.reset(new asio::ip::tcp::socket(_io_service));
         _socket->connect(receiver_endpoint);
-        _sock_fd = _socket->native();
+        _sock_fd = _socket->native_handle();
 
         //packets go out ASAP
         asio::ip::tcp::no_delay option(true);
