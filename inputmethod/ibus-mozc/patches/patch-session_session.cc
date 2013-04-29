$NetBSD: patch-session_session.cc,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- session/session.cc.orig	2013-03-29 04:33:25.000000000 +0000
+++ session/session.cc
@@ -1100,7 +1100,7 @@ void Session::UpdateOperationPreferences
   }
 
   // Cascading Window.
-#ifndef OS_LINUX
+#if !defined(OS_LINUX) or !defined(OS_NETBSD)
   if (config.has_use_cascading_window()) {
     operation_preferences.use_cascading_window = config.use_cascading_window();
   }
