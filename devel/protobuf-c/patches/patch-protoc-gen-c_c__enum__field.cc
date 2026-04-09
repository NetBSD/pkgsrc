$NetBSD: patch-protoc-gen-c_c__enum__field.cc,v 1.1 2026/04/09 07:44:36 wiz Exp $

Fix build with protobuf 34.
https://github.com/protobuf-c/protobuf-c/pull/797

--- protoc-gen-c/c_enum_field.cc.orig	2025-04-07 01:17:27.000000000 +0000
+++ protoc-gen-c/c_enum_field.cc
@@ -95,7 +95,7 @@ void EnumFieldGenerator::GenerateStructMembers(google:
 
 void EnumFieldGenerator::GenerateStructMembers(google::protobuf::io::Printer* printer) const
 {
-  switch (descriptor_->label()) {
+  switch (FieldLabel(descriptor_)) {
     case google::protobuf::FieldDescriptor::LABEL_REQUIRED:
       printer->Print(variables_, "$type$ $name$$deprecated$;\n");
       break;
@@ -117,7 +117,7 @@ void EnumFieldGenerator::GenerateStaticInit(google::pr
 }
 void EnumFieldGenerator::GenerateStaticInit(google::protobuf::io::Printer* printer) const
 {
-  switch (descriptor_->label()) {
+  switch (FieldLabel(descriptor_)) {
     case google::protobuf::FieldDescriptor::LABEL_REQUIRED:
       printer->Print(variables_, "$default$");
       break;
