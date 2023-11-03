$NetBSD: patch-protoc-c_c__helpers.h,v 1.1 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_helpers.h.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_helpers.h
@@ -70,6 +70,10 @@
 #include <protobuf-c/protobuf-c.pb.h>
 #include <google/protobuf/io/printer.h>
 
+#if GOOGLE_PROTOBUF_VERSION >= 4023000
+# include <google/protobuf/descriptor_legacy.h>
+#endif
+
 namespace google {
 namespace protobuf {
 namespace compiler {
@@ -172,12 +176,26 @@ int compare_name_indices_by_name(const v
 // This wrapper is needed to be able to compile against protobuf2.
 inline int FieldSyntax(const FieldDescriptor* field) {
 #ifdef HAVE_PROTO3
+# if GOOGLE_PROTOBUF_VERSION >= 4023000
+  return FileDescriptorLegacy(field->file()).syntax() == FileDescriptorLegacy::SYNTAX_PROTO3 ? 3 : 2;
+# else
   return field->file()->syntax() == FileDescriptor::SYNTAX_PROTO3 ? 3 : 2;
+# endif
 #else
   return 2;
 #endif
 }
 
+// Work around changes in protobuf >= 22.x without breaking compilation against
+// older protobuf versions.
+#if GOOGLE_PROTOBUF_VERSION >= 4022000
+# define GOOGLE_ARRAYSIZE	ABSL_ARRAYSIZE
+# define GOOGLE_CHECK_EQ	ABSL_CHECK_EQ
+# define GOOGLE_CHECK_EQ	ABSL_CHECK_EQ
+# define GOOGLE_DCHECK_GE	ABSL_DCHECK_GE
+# define GOOGLE_LOG		ABSL_LOG
+#endif
+
 }  // namespace c
 }  // namespace compiler
 }  // namespace protobuf
