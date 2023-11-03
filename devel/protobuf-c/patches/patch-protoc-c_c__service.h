$NetBSD: patch-protoc-c_c__service.h,v 1.1 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_service.h.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_service.h
@@ -100,8 +100,6 @@ class ServiceGenerator {
 
   const ServiceDescriptor* descriptor_;
   std::map<std::string, std::string> vars_;
-
-  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(ServiceGenerator);
 };
 
 }  // namespace c
