$NetBSD: patch-protoc-gen-c_c__primitive__field.cc,v 1.1 2026/04/09 07:44:36 wiz Exp $

Fix build with protobuf 34.
https://github.com/protobuf-c/protobuf-c/pull/797

--- protoc-gen-c/c_primitive_field.cc.orig	2025-04-07 01:17:27.000000000 +0000
+++ protoc-gen-c/c_primitive_field.cc
@@ -109,7 +109,7 @@ void PrimitiveFieldGenerator::GenerateStructMembers(go
   vars["name"] = FieldName(descriptor_);
   vars["deprecated"] = FieldDeprecated(descriptor_);
 
-  switch (descriptor_->label()) {
+  switch (FieldLabel(descriptor_)) {
     case google::protobuf::FieldDescriptor::LABEL_REQUIRED:
       printer->Print(vars, "$c_type$ $name$$deprecated$;\n");
       break;
@@ -156,7 +156,7 @@ void PrimitiveFieldGenerator::GenerateStaticInit(googl
   } else {
     vars["default_value"] = "0";
   }
-  switch (descriptor_->label()) {
+  switch (FieldLabel(descriptor_)) {
     case google::protobuf::FieldDescriptor::LABEL_REQUIRED:
       printer->Print(vars, "$default_value$");
       break;
