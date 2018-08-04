$NetBSD: patch-protoc-c_c__file.h,v 1.1 2018/08/04 21:36:16 minskim Exp $

https://github.com/protobuf-c/protobuf-c/pull/309
https://github.com/protobuf-c/protobuf-c/pull/328

--- protoc-c/c_file.h.orig	2017-08-05 21:41:36.000000000 +0000
+++ protoc-c/c_file.h
@@ -98,13 +98,13 @@ class FileGenerator {
  private:
   const FileDescriptor* file_;
 
-  scoped_array<scoped_ptr<MessageGenerator> > message_generators_;
-  scoped_array<scoped_ptr<EnumGenerator> > enum_generators_;
-  scoped_array<scoped_ptr<ServiceGenerator> > service_generators_;
-  scoped_array<scoped_ptr<ExtensionGenerator> > extension_generators_;
+  std::unique_ptr<std::unique_ptr<MessageGenerator>[] > message_generators_;
+  std::unique_ptr<std::unique_ptr<EnumGenerator>[] > enum_generators_;
+  std::unique_ptr<std::unique_ptr<ServiceGenerator>[] > service_generators_;
+  std::unique_ptr<std::unique_ptr<ExtensionGenerator>[] > extension_generators_;
 
   // E.g. if the package is foo.bar, package_parts_ is {"foo", "bar"}.
-  vector<string> package_parts_;
+  std::vector<string> package_parts_;
 
   GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FileGenerator);
 };
