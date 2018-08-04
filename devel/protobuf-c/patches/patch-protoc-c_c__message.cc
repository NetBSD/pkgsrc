$NetBSD: patch-protoc-c_c__message.cc,v 1.1 2018/08/04 21:36:16 minskim Exp $

https://github.com/protobuf-c/protobuf-c/pull/328

--- protoc-c/c_message.cc.orig	2017-08-05 21:41:36.000000000 +0000
+++ protoc-c/c_message.cc
@@ -83,11 +83,11 @@ MessageGenerator::MessageGenerator(const
   : descriptor_(descriptor),
     dllexport_decl_(dllexport_decl),
     field_generators_(descriptor),
-    nested_generators_(new scoped_ptr<MessageGenerator>[
+    nested_generators_(new std::unique_ptr<MessageGenerator>[
       descriptor->nested_type_count()]),
-    enum_generators_(new scoped_ptr<EnumGenerator>[
+    enum_generators_(new std::unique_ptr<EnumGenerator>[
       descriptor->enum_type_count()]),
-    extension_generators_(new scoped_ptr<ExtensionGenerator>[
+    extension_generators_(new std::unique_ptr<ExtensionGenerator>[
       descriptor->extension_count()]) {
 
   for (int i = 0; i < descriptor->nested_type_count(); i++) {
