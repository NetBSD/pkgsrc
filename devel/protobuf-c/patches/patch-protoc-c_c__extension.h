$NetBSD: patch-protoc-c_c__extension.h,v 1.1 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_extension.h.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_extension.h
@@ -98,8 +98,6 @@ class ExtensionGenerator {
   const FieldDescriptor* descriptor_;
   std::string type_traits_;
   std::string dllexport_decl_;
-
-  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(ExtensionGenerator);
 };
 
 }  // namespace c
