$NetBSD: patch-host_lib_transport_udp_zero_copy.cpp,v 1.1 2018/03/09 11:36:40 mef Exp $

PR pkg/52969
with the boost libs updated to 2.6 there are changes so that socket->native()
is no longer supported. use socket->native_handle() instead

--- lib/transport/udp_zero_copy.cpp.orig
+++ lib/transport/udp_zero_copy.cpp
@@ -190,7 +190,7 @@
         _socket = socket_sptr(new asio::ip::udp::socket(_io_service));
         _socket->open(asio::ip::udp::v4());
         _socket->connect(receiver_endpoint);
-        _sock_fd = _socket->native();
+        _sock_fd = _socket->native_handle();
 
         //allocate re-usable managed receive buffers
         for (size_t i = 0; i < get_num_recv_frames(); i++){
