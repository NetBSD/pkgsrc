$NetBSD: patch-session_session.cc,v 1.3 2013/09/07 18:42:14 ryoon Exp $

--- session/session.cc.orig	2013-08-28 05:26:12.000000000 +0000
+++ session/session.cc
@@ -1139,7 +1139,7 @@ void Session::UpdateOperationPreferences
   }
 
   // Cascading Window.
-#ifndef OS_LINUX
+#if !defined(OS_LINUX) && !defined(OS_NETBSD)
   if (config.has_use_cascading_window()) {
     operation_preferences.use_cascading_window = config.use_cascading_window();
   }
