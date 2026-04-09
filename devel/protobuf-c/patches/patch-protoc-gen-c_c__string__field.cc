$NetBSD: patch-protoc-gen-c_c__string__field.cc,v 1.1 2026/04/09 07:44:36 wiz Exp $

Fix build with protobuf 34.
https://github.com/protobuf-c/protobuf-c/pull/797

--- protoc-gen-c/c_string_field.cc.orig	2025-02-02 04:19:55.000000000 +0000
+++ protoc-gen-c/c_string_field.cc
@@ -94,7 +94,7 @@ void StringFieldGenerator::GenerateStructMembers(googl
 {
   const ProtobufCFileOptions opt = descriptor_->file()->options().GetExtension(pb_c_file);
 
-  switch (descriptor_->label()) {
+  switch (FieldLabel(descriptor_)) {
     case google::protobuf::FieldDescriptor::LABEL_REQUIRED:
     case google::protobuf::FieldDescriptor::LABEL_OPTIONAL:
       if (opt.const_strings())
@@ -138,7 +138,7 @@ void StringFieldGenerator::GenerateStaticInit(google::
   } else {
     vars["default"] = "(char *)protobuf_c_empty_string";
   }
-  switch (descriptor_->label()) {
+  switch (FieldLabel(descriptor_)) {
     case google::protobuf::FieldDescriptor::LABEL_REQUIRED:
     case google::protobuf::FieldDescriptor::LABEL_OPTIONAL:
       printer->Print(vars, "$default$");
