$NetBSD: patch-protoc-c_c__generator.h,v 1.1 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_generator.h.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_generator.h
@@ -93,9 +93,6 @@ class PROTOC_C_EXPORT CGenerator : publi
                 const std::string& parameter,
                 OutputDirectory* output_directory,
                 std::string* error) const;
-
- private:
-  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(CGenerator);
 };
 
 }  // namespace c
