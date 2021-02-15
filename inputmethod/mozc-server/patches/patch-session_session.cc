$NetBSD: patch-session_session.cc,v 1.6 2021/02/15 14:50:23 ryoon Exp $

* NetBSD support

--- session/session.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ session/session.cc
@@ -230,9 +230,9 @@ void Session::InitContext(ImeContext *co
   context->SetConfig(&context->GetConfig());
 
 #if defined(OS_ANDROID) || defined(OS_IOS) || defined(OS_LINUX) || \
-    defined(OS_WASM)
+    defined(OS_WASM) || defined(OS_NETBSD)
   context->mutable_converter()->set_use_cascading_window(false);
-#endif  // OS_ANDROID || OS_IOS || OS_LINUX || OS_WASM
+#endif  // OS_ANDROID || OS_IOS || OS_LINUX || OS_WASM || OS_NETBSD
 }
 
 void Session::PushUndoContext() {
@@ -964,14 +964,14 @@ void Session::UpdatePreferences(commands
   }
 
 #if defined(OS_ANDROID) || defined(OS_IOS) || defined(OS_LINUX) || \
-    defined(OS_WASM)
+    defined(OS_WASM) || defined(OS_NETBSD)
   context_->mutable_converter()->set_use_cascading_window(false);
-#else   // OS_LINUX || OS_ANDROID || OS_WASM
+#else   // OS_LINUX || OS_ANDROID || OS_WASM || OS_NETBSD
   if (config.has_use_cascading_window()) {
     context_->mutable_converter()->set_use_cascading_window(
         config.use_cascading_window());
   }
-#endif  // OS_ANDROID || OS_IOS || OS_LINUX || OS_WASM
+#endif  // OS_ANDROID || OS_IOS || OS_LINUX || OS_WASM || OS_NETBSD
 }
 
 bool Session::IMEOn(commands::Command *command) {
