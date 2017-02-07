$NetBSD: patch-src_google_protobuf_compiler_plugin.pb.h,v 1.1 2017/02/07 14:00:32 wiz Exp $

--- src/google/protobuf/compiler/plugin.pb.h.orig	2017-01-28 02:20:20.000000000 +0000
+++ src/google/protobuf/compiler/plugin.pb.h
@@ -29,6 +29,10 @@
 #include <google/protobuf/extension_set.h>  // IWYU pragma: export
 #include <google/protobuf/unknown_field_set.h>
 #include <google/protobuf/descriptor.pb.h>
+
+#undef major
+#undef minor
+
 // @@protoc_insertion_point(includes)
 namespace google {
 namespace protobuf {
