$NetBSD: patch-protoc-c_c__message.cc,v 1.3 2023/11/03 13:11:26 wiz Exp $

Support for new Google protobuf 22.x, 23.x releases
https://github.com/protobuf-c/protobuf-c/pull/673

--- protoc-c/c_message.cc.orig	2021-05-19 01:51:00.000000000 +0000
+++ protoc-c/c_message.cc
@@ -499,7 +499,7 @@ GenerateMessageDescriptor(io::Printer* p
 	  // NOTE: not supported by protobuf
 	  vars["maybe_static"] = "";
 	  vars["field_dv_ctype"] = "{ ... }";
-	  GOOGLE_LOG(DFATAL) << "Messages can't have default values!";
+	  GOOGLE_LOG(FATAL) << "Messages can't have default values!";
 	  break;
 	case FieldDescriptor::CPPTYPE_STRING:
 	  if (fd->type() == FieldDescriptor::TYPE_BYTES || opt.string_as_bytes())
@@ -521,7 +521,7 @@ GenerateMessageDescriptor(io::Printer* p
 	    break;
 	  }
 	default:
-	  GOOGLE_LOG(DFATAL) << "Unknown CPPTYPE";
+	  GOOGLE_LOG(FATAL) << "Unknown CPPTYPE";
 	  break;
 	}
 	if (!already_defined)
