$NetBSD: patch-protoc-c_c__field.h,v 1.3 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_field.h.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_field.h
@@ -103,9 +103,6 @@ class FieldGenerator {
                                             const std::string &type_macro,
                                             const std::string &descriptor_addr) const;
   const FieldDescriptor *descriptor_;
-
- private:
-  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FieldGenerator);
 };
 
 // Convenience class which constructs FieldGenerators for a Descriptor.
@@ -121,8 +118,6 @@ class FieldGeneratorMap {
   std::unique_ptr<std::unique_ptr<FieldGenerator>[]> field_generators_;
 
   static FieldGenerator* MakeGenerator(const FieldDescriptor* field);
-
-  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FieldGeneratorMap);
 };
 
 }  // namespace c
