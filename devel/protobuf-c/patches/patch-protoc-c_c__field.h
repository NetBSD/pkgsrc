$NetBSD: patch-protoc-c_c__field.h,v 1.1 2018/08/04 21:36:16 minskim Exp $

https://github.com/protobuf-c/protobuf-c/pull/328

--- protoc-c/c_field.h.orig	2017-08-05 21:41:36.000000000 +0000
+++ protoc-c/c_field.h
@@ -117,7 +117,7 @@ class FieldGeneratorMap {
 
  private:
   const Descriptor* descriptor_;
-  scoped_array<scoped_ptr<FieldGenerator> > field_generators_;
+  std::unique_ptr<std::unique_ptr<FieldGenerator>[] > field_generators_;
 
   static FieldGenerator* MakeGenerator(const FieldDescriptor* field);
 
