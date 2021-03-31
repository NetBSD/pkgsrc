$NetBSD: patch-src_google_protobuf_port__def.inc,v 1.1 2021/03/31 10:18:47 jperkin Exp $

SunOS does not support init_priority.

--- src/google/protobuf/port_def.inc.orig	2021-03-04 21:39:09.000000000 +0000
+++ src/google/protobuf/port_def.inc
@@ -587,7 +587,7 @@
 #define PROTOBUF_ATTRIBUTE_NO_DESTROY
 #endif
 
-#if defined(__GNUC__)
+#if defined(__GNUC__) && !defined(__sun)
 // Protobuf extensions and reflection require registration of the protos linked
 // in the binary. Not until everything is registered does the runtime have a
 // complete view on all protos. When code is using reflection or extensions
