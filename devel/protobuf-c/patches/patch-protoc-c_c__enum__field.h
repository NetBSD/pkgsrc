$NetBSD: patch-protoc-c_c__enum__field.h,v 1.1 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_enum_field.h.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_enum_field.h
@@ -85,8 +85,6 @@ class EnumFieldGenerator : public FieldG
 
  private:
   std::map<std::string, std::string> variables_;
-
-  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EnumFieldGenerator);
 };
 
 
