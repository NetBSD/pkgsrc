$NetBSD: patch-xgboost_include_xgboost_collective_socket.h,v 1.1 2023/06/13 17:36:58 adam Exp $

NetBSD doesn't provide SO_DOMAIN socket option.

--- xgboost/include/xgboost/collective/socket.h.orig	2023-06-13 16:57:30.244346651 +0000
+++ xgboost/include/xgboost/collective/socket.h
@@ -250,7 +250,7 @@ class TCPSocket {
   HandleT handle_{InvalidSocket()};
   // There's reliable no way to extract domain from a socket without first binding that
   // socket on macos.
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
   SockDomain domain_{SockDomain::kV4};
 #endif
 
@@ -284,7 +284,7 @@ class TCPSocket {
         getsockopt(handle_, SOL_SOCKET, SO_PROTOCOL_INFO, reinterpret_cast<char *>(&info), &len),
         0);
     return ret_iafamily(info.iAddressFamily);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__NetBSD__)
     return domain_;
 #elif defined(__unix__)
 #ifndef __PASE__
