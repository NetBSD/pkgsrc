$NetBSD: patch-cpp__src_include_xgboost_collective_socket.h,v 1.2 2024/08/04 13:05:59 adam Exp $

NetBSD doesn't provide SO_DOMAIN socket option.

--- cpp_src/include/xgboost/collective/socket.h.orig	2020-02-02 00:00:00.000000000 +0000
+++ cpp_src/include/xgboost/collective/socket.h
@@ -282,7 +282,7 @@ class TCPSocket {
   bool non_blocking_{false};
   // There's reliable no way to extract domain from a socket without first binding that
   // socket on macos.
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
   SockDomain domain_{SockDomain::kV4};
 #endif
 
@@ -316,7 +316,7 @@ class TCPSocket {
         getsockopt(handle_, SOL_SOCKET, SO_PROTOCOL_INFO, reinterpret_cast<char *>(&info), &len),
         0);
     return ret_iafamily(info.iAddressFamily);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__NetBSD__)
     return domain_;
 #elif defined(__unix__)
 #ifndef __PASE__
