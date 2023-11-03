$NetBSD: patch-protoc-c_c__primitive__field.cc,v 1.1 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_primitive_field.cc.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_primitive_field.cc
@@ -143,7 +143,7 @@ std::string PrimitiveFieldGenerator::Get
     case FieldDescriptor::CPPTYPE_BOOL:
       return descriptor_->default_value_bool() ? "1" : "0";
     default:
-      GOOGLE_LOG(DFATAL) << "unexpected CPPTYPE in c_primitive_field";
+      GOOGLE_LOG(FATAL) << "unexpected CPPTYPE in c_primitive_field";
       return "UNEXPECTED_CPPTYPE";
   }
 }
