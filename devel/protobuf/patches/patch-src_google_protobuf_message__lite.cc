$NetBSD: patch-src_google_protobuf_message__lite.cc,v 1.1 2016/11/23 20:56:45 wiedi Exp $

need limits for INT_MAX

--- src/google/protobuf/message_lite.cc.orig	2016-09-24 01:27:21.000000000 +0000
+++ src/google/protobuf/message_lite.cc
@@ -38,6 +38,7 @@
 #include <google/protobuf/message_lite.h>
 #include <google/protobuf/repeated_field.h>
 #include <string>
+#include <climits>
 #include <google/protobuf/stubs/logging.h>
 #include <google/protobuf/stubs/common.h>
 #include <google/protobuf/io/coded_stream.h>
