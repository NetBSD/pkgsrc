$NetBSD: patch-include_libnet_libnet-structures.h,v 1.1 2021/01/26 11:20:17 jperkin Exp $

Use portable types.

--- include/libnet/libnet-structures.h.orig	2019-10-08 18:58:28.000000000 +0000
+++ include/libnet/libnet-structures.h
@@ -49,9 +49,9 @@ struct libnet_port_list_chain
 /* libnet statistics structure */
 struct libnet_stats
 {
-    __int64_t packets_sent;               /* packets sent */
-    __int64_t packet_errors;              /* packets errors */
-    __int64_t bytes_written;              /* bytes written */
+    int64_t packets_sent;               /* packets sent */
+    int64_t packet_errors;              /* packets errors */
+    int64_t bytes_written;              /* bytes written */
 };
 
 
