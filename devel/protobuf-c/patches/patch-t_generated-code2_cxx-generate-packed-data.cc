$NetBSD: patch-t_generated-code2_cxx-generate-packed-data.cc,v 1.1 2019/03/27 11:31:21 jperkin Exp $

Upstream fix https://github.com/protobuf-c/protobuf-c/pull/342

--- t/generated-code2/cxx-generate-packed-data.cc.orig	2017-08-05 21:41:36.000000000 +0000
+++ t/generated-code2/cxx-generate-packed-data.cc
@@ -998,7 +998,7 @@ static void dump_test_packed_repeated_en
 static void dump_test_unknown_fields (void)
 {
   EmptyMess mess;
-  const google::protobuf::Message::Reflection *reflection = mess.GetReflection();
+  const google::protobuf::Reflection *reflection = mess.GetReflection();
   google::protobuf::UnknownFieldSet *fs = reflection->MutableUnknownFields(&mess);
 
 #if GOOGLE_PROTOBUF_VERSION >= 2001000
