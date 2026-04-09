$NetBSD: patch-protoc-gen-c_c__helpers.h,v 1.1 2026/04/09 07:44:36 wiz Exp $

Fix build with protobuf 34.
https://github.com/protobuf-c/protobuf-c/pull/797

--- protoc-gen-c/c_helpers.h.orig	2025-04-07 01:17:27.000000000 +0000
+++ protoc-gen-c/c_helpers.h
@@ -153,6 +153,11 @@ std::string GetLabelName(google::protobuf::FieldDescri
 // return 'required', 'optional', or 'repeated'
 std::string GetLabelName(google::protobuf::FieldDescriptor::Label label);
 
+// Returns the field label in a way that is compatible with protobuf versions
+// where FieldDescriptor::label() is unavailable.
+google::protobuf::FieldDescriptor::Label FieldLabel(
+  const google::protobuf::FieldDescriptor* field);
+
 // write IntRanges entries for a bunch of sorted values.
 // returns the number of ranges there are to bsearch.
 unsigned WriteIntRanges(google::protobuf::io::Printer* printer, int n_values, const int *values, compat::StringView name);
