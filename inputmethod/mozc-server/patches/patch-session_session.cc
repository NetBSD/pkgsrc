$NetBSD: patch-session_session.cc,v 1.4 2016/05/16 11:51:49 ryoon Exp $

--- session/session.cc.orig	2016-05-15 08:11:12.000000000 +0000
+++ session/session.cc
@@ -232,9 +232,9 @@ void Session::InitContext(ImeContext *co
 
   context->SetConfig(&context->GetConfig());
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
   context->mutable_converter()->set_use_cascading_window(false);
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
 }
 
 
@@ -961,14 +961,14 @@ void Session::UpdatePreferences(commands
         config.selection_shortcut());
   }
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
   context_->mutable_converter()->set_use_cascading_window(false);
-#else  // OS_LINUX || OS_ANDROID || OS_NACL
+#else  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
   if (config.has_use_cascading_window()) {
     context_->mutable_converter()->set_use_cascading_window(
         config.use_cascading_window());
   }
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
 }
 
 bool Session::IMEOn(commands::Command *command) {
