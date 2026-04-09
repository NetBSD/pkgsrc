$NetBSD: patch-protoc-gen-c_c__message__field.cc,v 1.1 2026/04/09 07:44:36 wiz Exp $

Fix build with protobuf 34.
https://github.com/protobuf-c/protobuf-c/pull/797

--- protoc-gen-c/c_message_field.cc.orig	2025-02-02 04:19:55.000000000 +0000
+++ protoc-gen-c/c_message_field.cc
@@ -83,7 +83,7 @@ void MessageFieldGenerator::GenerateStructMembers(goog
   vars["name"] = FieldName(descriptor_);
   vars["type"] = FullNameToC(descriptor_->message_type()->full_name(), descriptor_->message_type()->file());
   vars["deprecated"] = FieldDeprecated(descriptor_);
-  switch (descriptor_->label()) {
+  switch (FieldLabel(descriptor_)) {
     case google::protobuf::FieldDescriptor::LABEL_REQUIRED:
     case google::protobuf::FieldDescriptor::LABEL_OPTIONAL:
       printer->Print(vars, "$type$ *$name$$deprecated$;\n");
@@ -103,7 +103,7 @@ void MessageFieldGenerator::GenerateStaticInit(google:
 }
 void MessageFieldGenerator::GenerateStaticInit(google::protobuf::io::Printer* printer) const
 {
-  switch (descriptor_->label()) {
+  switch (FieldLabel(descriptor_)) {
     case google::protobuf::FieldDescriptor::LABEL_REQUIRED:
     case google::protobuf::FieldDescriptor::LABEL_OPTIONAL:
       printer->Print("NULL");
