$NetBSD: patch-host_lib_transport_udp_simple.cpp,v 1.1 2018/03/09 11:36:40 mef Exp $

PR pkg/52969
with the boost libs updated to 2.6 there are changes so that socket->native()
is no longer supported. use socket->native_handle() instead

--- lib/transport/udp_simple.cpp.orig
+++ lib/transport/udp_simple.cpp
@@ -56,7 +56,7 @@
     }
 
     size_t recv(const asio::mutable_buffer &buff, double timeout){
-        if (not wait_for_recv_ready(_socket->native(), timeout)) return 0;
+        if (not wait_for_recv_ready(_socket->native_handle(), timeout)) return 0;
         return _socket->receive_from(asio::buffer(buff), _recv_endpoint);
     }
