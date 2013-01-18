$NetBSD: patch-session_session.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- session/session.cc.orig	2012-08-31 05:36:43.000000000 +0000
+++ session/session.cc
@@ -1091,7 +1091,7 @@ void Session::UpdateOperationPreferences
   }
 
   // Cascading Window.
-#ifndef OS_LINUX
+#if !defined(OS_LINUX) || !defined(OS_NETBSD)
   if (config.has_use_cascading_window()) {
     operation_preferences.use_cascading_window = config.use_cascading_window();
   }
