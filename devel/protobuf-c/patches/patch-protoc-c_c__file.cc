$NetBSD: patch-protoc-c_c__file.cc,v 1.1 2018/08/04 21:36:16 minskim Exp $

https://github.com/protobuf-c/protobuf-c/pull/328

--- protoc-c/c_file.cc.orig	2017-08-05 21:41:36.000000000 +0000
+++ protoc-c/c_file.cc
@@ -83,13 +83,13 @@ FileGenerator::FileGenerator(const FileD
                              const string& dllexport_decl)
   : file_(file),
     message_generators_(
-      new scoped_ptr<MessageGenerator>[file->message_type_count()]),
+      new std::unique_ptr<MessageGenerator>[file->message_type_count()]),
     enum_generators_(
-      new scoped_ptr<EnumGenerator>[file->enum_type_count()]),
+      new std::unique_ptr<EnumGenerator>[file->enum_type_count()]),
     service_generators_(
-      new scoped_ptr<ServiceGenerator>[file->service_count()]),
+      new std::unique_ptr<ServiceGenerator>[file->service_count()]),
     extension_generators_(
-      new scoped_ptr<ExtensionGenerator>[file->extension_count()]) {
+      new std::unique_ptr<ExtensionGenerator>[file->extension_count()]) {
 
   for (int i = 0; i < file->message_type_count(); i++) {
     message_generators_[i].reset(
