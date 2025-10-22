$NetBSD: patch-unittest_gunit_xplugin_xpl_message__helpers.h,v 1.1 2025/10/22 07:21:48 jnemeth Exp $

--- unittest/gunit/xplugin/xpl/message_helpers.h.orig	2025-10-20 07:14:16.269228877 +0000
+++ unittest/gunit/xplugin/xpl/message_helpers.h
@@ -39,9 +39,9 @@ inline std::string msg_to_string(const n
   printer.SetSingleLineMode(true);
   std::string output;
   printer.PrintToString(msg, &output);
-  return msg.GetTypeName() + "{ " + output + "}";
+  return std::string(msg.GetTypeName()) + "{ " + output + "}";
 #else
-  return msg.GetTypeName();
+  return std::string(msg.GetTypeName());
 #endif
 }
 
