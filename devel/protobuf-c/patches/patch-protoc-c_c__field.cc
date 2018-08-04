$NetBSD: patch-protoc-c_c__field.cc,v 1.1 2018/08/04 21:36:16 minskim Exp $

https://github.com/protobuf-c/protobuf-c/pull/328

--- protoc-c/c_field.cc.orig	2017-08-05 21:41:36.000000000 +0000
+++ protoc-c/c_field.cc
@@ -189,7 +189,7 @@ void FieldGenerator::GenerateDescriptorI
 FieldGeneratorMap::FieldGeneratorMap(const Descriptor* descriptor)
   : descriptor_(descriptor),
     field_generators_(
-      new scoped_ptr<FieldGenerator>[descriptor->field_count()]) {
+      new std::unique_ptr<FieldGenerator>[descriptor->field_count()]) {
   // Construct all the FieldGenerators.
   for (int i = 0; i < descriptor->field_count(); i++) {
     field_generators_[i].reset(MakeGenerator(descriptor->field(i)));
