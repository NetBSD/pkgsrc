$NetBSD: patch-protoc-c_c__message.h,v 1.1 2018/08/04 21:36:16 minskim Exp $

https://github.com/protobuf-c/protobuf-c/pull/328

--- protoc-c/c_message.h.orig	2017-08-05 21:41:36.000000000 +0000
+++ protoc-c/c_message.h
@@ -126,9 +126,9 @@ class MessageGenerator {
   const Descriptor* descriptor_;
   string dllexport_decl_;
   FieldGeneratorMap field_generators_;
-  scoped_array<scoped_ptr<MessageGenerator> > nested_generators_;
-  scoped_array<scoped_ptr<EnumGenerator> > enum_generators_;
-  scoped_array<scoped_ptr<ExtensionGenerator> > extension_generators_;
+  std::unique_ptr<std::unique_ptr<MessageGenerator>[] > nested_generators_;
+  std::unique_ptr<std::unique_ptr<EnumGenerator>[] > enum_generators_;
+  std::unique_ptr<std::unique_ptr<ExtensionGenerator>[] > extension_generators_;
 
   GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(MessageGenerator);
 };
