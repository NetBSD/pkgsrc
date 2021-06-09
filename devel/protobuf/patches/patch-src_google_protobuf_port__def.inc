$NetBSD: patch-src_google_protobuf_port__def.inc,v 1.3 2021/06/09 04:57:10 adam Exp $

SunOS does not support init_priority.

--- src/google/protobuf/port_def.inc.orig	2021-06-08 14:11:11.000000000 +0000
+++ src/google/protobuf/port_def.inc
@@ -541,7 +541,7 @@
 #ifdef PROTOBUF_ATTRIBUTE_INIT_PRIORITY
 #error PROTOBUF_ATTRIBUTE_INIT_PRIORITY was previously defined
 #endif
-#if PROTOBUF_GNUC_MIN(3, 0) && (!defined(__APPLE__) || defined(__clang__))
+#if PROTOBUF_GNUC_MIN(3, 0) && !defined(__sun) && (!defined(__APPLE__) || defined(__clang__))
 #define PROTOBUF_ATTRIBUTE_INIT_PRIORITY __attribute__((init_priority((102))))
 #else
 #define PROTOBUF_ATTRIBUTE_INIT_PRIORITY
