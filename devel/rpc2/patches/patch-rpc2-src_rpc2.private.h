$NetBSD: patch-rpc2-src_rpc2.private.h,v 1.1 2015/01/23 14:31:38 hauke Exp $

SunOS doesn't have u_int*_t

--- rpc2-src/rpc2.private.h.orig	2009-03-13 20:26:35.000000000 +0000
+++ rpc2-src/rpc2.private.h
@@ -65,12 +65,12 @@ struct sockaddr_storage {
 
 #ifndef HAVE_STRUCT_SOCKADDR_IN6
 struct in6_addr {
-    u_int8_t u6_addr[16];
+    uint8_t u6_addr[16];
 };
 struct sockaddr_in6 {
-    u_int16_t sin6_family;
-    u_int16_t sin6_port;
-    u_int32_t sin6_flowinfo;
+    uint16_t sin6_family;
+    uint16_t sin6_port;
+    uint32_t sin6_flowinfo;
     struct in6_addr sin6_addr;
 };
 #endif
