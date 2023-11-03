$NetBSD: patch-protoc-c_c__file.h,v 1.3 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_file.h.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_file.h
@@ -103,8 +103,6 @@ class FileGenerator {
   std::unique_ptr<std::unique_ptr<EnumGenerator>[]> enum_generators_;
   std::unique_ptr<std::unique_ptr<ServiceGenerator>[]> service_generators_;
   std::unique_ptr<std::unique_ptr<ExtensionGenerator>[]> extension_generators_;
-
-  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FileGenerator);
 };
 
 }  // namespace c
