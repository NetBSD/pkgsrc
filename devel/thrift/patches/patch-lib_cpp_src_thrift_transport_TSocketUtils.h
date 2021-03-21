$NetBSD: patch-lib_cpp_src_thrift_transport_TSocketUtils.h,v 1.1 2021/03/21 12:41:11 taca Exp $

* Hack for no AI_V4MAPPED platform.

--- lib/cpp/src/thrift/transport/TSocketUtils.h.orig	2021-02-04 23:07:31.000000000 +0000
+++ lib/cpp/src/thrift/transport/TSocketUtils.h
@@ -33,6 +33,10 @@
 #include <netdb.h>
 #endif
 
+#ifndef AI_V4MAPPED
+#define AI_V4MAPPED	0
+#endif
+
 #include <thrift/transport/PlatformSocket.h>
 
 namespace apache {
