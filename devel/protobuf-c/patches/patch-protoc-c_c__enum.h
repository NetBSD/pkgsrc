$NetBSD: patch-protoc-c_c__enum.h,v 1.1 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_enum.h.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_enum.h
@@ -106,8 +106,6 @@ class EnumGenerator {
  private:
   const EnumDescriptor* descriptor_;
   std::string dllexport_decl_;
-
-  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EnumGenerator);
 };
 
 }  // namespace c
