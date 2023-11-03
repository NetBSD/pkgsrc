$NetBSD: patch-protoc-c_c__primitive__field.h,v 1.1 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_primitive_field.h.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_primitive_field.h
@@ -82,10 +82,6 @@ class PrimitiveFieldGenerator : public F
   void GenerateDescriptorInitializer(io::Printer* printer) const;
   std::string GetDefaultValue(void) const;
   void GenerateStaticInit(io::Printer* printer) const;
-
- private:
-
-  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(PrimitiveFieldGenerator);
 };
 
 }  // namespace c
