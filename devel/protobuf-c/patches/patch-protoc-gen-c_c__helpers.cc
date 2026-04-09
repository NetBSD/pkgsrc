$NetBSD: patch-protoc-gen-c_c__helpers.cc,v 1.1 2026/04/09 07:44:36 wiz Exp $

Fix build with protobuf 34.
https://github.com/protobuf-c/protobuf-c/pull/797

--- protoc-gen-c/c_helpers.cc.orig	2025-04-07 01:17:27.000000000 +0000
+++ protoc-gen-c/c_helpers.cc
@@ -338,6 +338,17 @@ std::string GetLabelName(google::protobuf::FieldDescri
   return "bad-label";
 }
 
+google::protobuf::FieldDescriptor::Label FieldLabel(
+    const google::protobuf::FieldDescriptor* field) {
+  if (field->is_repeated()) {
+    return google::protobuf::FieldDescriptor::LABEL_REPEATED;
+  }
+  if (field->is_required()) {
+    return google::protobuf::FieldDescriptor::LABEL_REQUIRED;
+  }
+  return google::protobuf::FieldDescriptor::LABEL_OPTIONAL;
+}
+
 unsigned
 WriteIntRanges(google::protobuf::io::Printer* printer, int n_values, const int *values, compat::StringView name)
 {
