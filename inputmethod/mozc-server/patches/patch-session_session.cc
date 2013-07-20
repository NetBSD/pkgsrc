$NetBSD: patch-session_session.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- session/session.cc.orig	2013-07-17 02:38:03.000000000 +0000
+++ session/session.cc
@@ -1133,7 +1133,7 @@ void Session::UpdateOperationPreferences
   }
 
   // Cascading Window.
-#ifndef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   if (config.has_use_cascading_window()) {
     operation_preferences.use_cascading_window = config.use_cascading_window();
   }
