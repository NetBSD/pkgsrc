$NetBSD: patch-protoc-gen-c_c__bytes__field.cc,v 1.1 2026/04/09 07:44:36 wiz Exp $

Fix build with protobuf 34.
https://github.com/protobuf-c/protobuf-c/pull/797

--- protoc-gen-c/c_bytes_field.cc.orig	2025-02-02 04:19:55.000000000 +0000
+++ protoc-gen-c/c_bytes_field.cc
@@ -94,7 +94,7 @@ void BytesFieldGenerator::GenerateStructMembers(google
 
 void BytesFieldGenerator::GenerateStructMembers(google::protobuf::io::Printer* printer) const
 {
-  switch (descriptor_->label()) {
+  switch (FieldLabel(descriptor_)) {
     case google::protobuf::FieldDescriptor::LABEL_REQUIRED:
       printer->Print(variables_, "ProtobufCBinaryData $name$$deprecated$;\n");
       break;
@@ -135,7 +135,7 @@ void BytesFieldGenerator::GenerateStaticInit(google::p
 }
 void BytesFieldGenerator::GenerateStaticInit(google::protobuf::io::Printer* printer) const
 {
-  switch (descriptor_->label()) {
+  switch (FieldLabel(descriptor_)) {
     case google::protobuf::FieldDescriptor::LABEL_REQUIRED:
       printer->Print(variables_, "$default_value$");
       break;
