$NetBSD: patch-protoc-c_c__file.cc,v 1.5 2024/04/07 20:53:13 adam Exp $

Chase compatibility issues with Google protobuf 26.0
https://github.com/protobuf-c/protobuf-c/pull/711

--- protoc-c/c_file.cc.orig	2024-04-07 20:32:42.583909649 +0000
+++ protoc-c/c_file.cc
@@ -117,14 +117,7 @@ FileGenerator::~FileGenerator() {}
 void FileGenerator::GenerateHeader(io::Printer* printer) {
   std::string filename_identifier = FilenameIdentifier(file_->name());
 
-  int min_header_version = 1000000;
-#if GOOGLE_PROTOBUF_VERSION >= 4023000
-  if (FileDescriptorLegacy(file_).syntax() == FileDescriptorLegacy::SYNTAX_PROTO3) {
-#else
-  if (file_->syntax() == FileDescriptor::SYNTAX_PROTO3) {
-#endif
-    min_header_version = 1003000;
-  }
+  const int min_header_version = 1003000;
 
   // Generate top of header.
   printer->Print(
