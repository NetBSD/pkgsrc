$NetBSD: patch-xbmc_addons_AddonManager.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/addons/AddonManager.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/addons/AddonManager.cpp
@@ -143,7 +143,7 @@ AddonPtr CAddonMgr::Factory(const cp_ext
         std::string tograb;
 #if defined(TARGET_ANDROID)
           tograb = "@library_android";
-#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
+#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
           tograb = "@library_linux";
 #elif defined(TARGET_WINDOWS) && defined(HAS_DX)
           tograb = "@library_windx";
@@ -888,7 +888,7 @@ bool CAddonMgr::PlatformSupportsAddon(co
         return true;
 #if defined(TARGET_ANDROID)
       if (*platform == "android")
-#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
+#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
       if (*platform == "linux")
 #elif defined(TARGET_WINDOWS) && defined(HAS_DX)
       if (*platform == "windx")
