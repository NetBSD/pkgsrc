$NetBSD: patch-protoc-c_c__file.cc,v 1.3 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_file.cc.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_file.cc
@@ -119,7 +119,11 @@ void FileGenerator::GenerateHeader(io::P
 
   int min_header_version = 1000000;
 #if defined(HAVE_PROTO3)
+# if GOOGLE_PROTOBUF_VERSION >= 4023000
+  if (FileDescriptorLegacy(file_).syntax() == FileDescriptorLegacy::SYNTAX_PROTO3) {
+# else
   if (file_->syntax() == FileDescriptor::SYNTAX_PROTO3) {
+#endif
     min_header_version = 1003000;
   }
 #endif
