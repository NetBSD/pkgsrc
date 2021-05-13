$NetBSD: patch-src_google_protobuf_port__def.inc,v 1.2 2021/05/13 12:16:54 adam Exp $

SunOS does not support init_priority.

--- src/google/protobuf/port_def.inc.orig	2021-05-12 23:23:56.000000000 +0000
+++ src/google/protobuf/port_def.inc
@@ -506,7 +506,7 @@
 #ifdef PROTOBUF_ATTRIBUTE_INIT_PRIORITY
 #error PROTOBUF_ATTRIBUTE_INIT_PRIORITY was previously defined
 #endif
-#if PROTOBUF_GNUC_MIN(3, 0)
+#if PROTOBUF_GNUC_MIN(3, 0) && !defined(__sun)
 #define PROTOBUF_ATTRIBUTE_INIT_PRIORITY __attribute__((init_priority((102))))
 #else
 #define PROTOBUF_ATTRIBUTE_INIT_PRIORITY
