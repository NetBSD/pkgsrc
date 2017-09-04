$NetBSD: patch-3rdparty_protobuf_src_google_protobuf_message__lite.cc,v 1.1 2017/09/04 15:23:49 fhajny Exp $

Needed for INT_MAX.

--- 3rdparty/protobuf/src/google/protobuf/message_lite.cc.orig	2017-08-03 23:58:23.000000000 +0000
+++ 3rdparty/protobuf/src/google/protobuf/message_lite.cc
@@ -38,6 +38,7 @@
 #include <google/protobuf/message_lite.h>
 #include <google/protobuf/repeated_field.h>
 #include <string>
+#include <climits>
 #include <google/protobuf/stubs/logging.h>
 #include <google/protobuf/stubs/common.h>
 #include <google/protobuf/io/coded_stream.h>
