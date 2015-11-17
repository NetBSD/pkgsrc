$NetBSD: patch-xbmc_addons_AddonDll.h,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/addons/AddonDll.h.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/addons/AddonDll.h
@@ -99,7 +99,7 @@ CAddonDll<TheDll, TheStruct, TheProps>::
   {
 #if defined(TARGET_ANDROID)
   m_strLibName = CAddonMgr::Get().GetExtValue(ext->configuration, "@library_android");
-#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
+#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
     m_strLibName = CAddonMgr::Get().GetExtValue(ext->configuration, "@library_linux");
 #elif defined(TARGET_WINDOWS) && defined(HAS_DX)
     m_strLibName = CAddonMgr::Get().GetExtValue(ext->configuration, "@library_windx");
