$NetBSD: patch-protoc-c_c__helpers.h,v 1.3 2024/04/07 20:53:13 adam Exp $

Chase compatibility issues with Google protobuf 26.0
https://github.com/protobuf-c/protobuf-c/pull/711

--- protoc-c/c_helpers.h.orig	2024-04-07 20:35:11.315221523 +0000
+++ protoc-c/c_helpers.h
@@ -70,10 +70,6 @@
 #include <protobuf-c/protobuf-c.pb.h>
 #include <google/protobuf/io/printer.h>
 
-#if GOOGLE_PROTOBUF_VERSION >= 4023000
-# include <google/protobuf/descriptor_legacy.h>
-#endif
-
 namespace google {
 namespace protobuf {
 namespace compiler {
@@ -173,13 +169,21 @@ struct NameIndex
 int compare_name_indices_by_name(const void*, const void*);
 
 // Return the syntax version of the file containing the field.
-// This wrapper is needed to be able to compile against protobuf2.
 inline int FieldSyntax(const FieldDescriptor* field) {
-#if GOOGLE_PROTOBUF_VERSION >= 4023000
-  return FileDescriptorLegacy(field->file()).syntax() == FileDescriptorLegacy::SYNTAX_PROTO3 ? 3 : 2;
-#else
-  return field->file()->syntax() == FileDescriptor::SYNTAX_PROTO3 ? 3 : 2;
-#endif
+  auto proto = FileDescriptorProto();
+  field->file()->CopyTo(&proto);
+
+  if (proto.has_syntax()) {
+    auto syntax = proto.syntax();
+    assert(syntax == "proto2" || syntax == "proto3");
+    if (syntax == "proto2") {
+      return 2;
+    } else if (syntax == "proto3") {
+      return 3;
+    }
+  }
+
+  return 2;
 }
 
 // Work around changes in protobuf >= 22.x without breaking compilation against
