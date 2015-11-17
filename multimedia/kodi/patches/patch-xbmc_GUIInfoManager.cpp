$NetBSD: patch-xbmc_GUIInfoManager.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/GUIInfoManager.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/GUIInfoManager.cpp
@@ -2289,7 +2289,7 @@ bool CGUIInfoManager::GetBool(int condit
     bReturn = g_application.IsMusicScanning();
   }
   else if (condition == SYSTEM_PLATFORM_LINUX)
-#if defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
+#if defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
     bReturn = true;
 #else
     bReturn = false;
