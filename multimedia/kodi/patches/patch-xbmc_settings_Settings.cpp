$NetBSD: patch-xbmc_settings_Settings.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/settings/Settings.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/settings/Settings.cpp
@@ -468,6 +468,9 @@ bool CSettings::InitializeDefinitions()
 #elif defined(TARGET_FREEBSD)
   if (CFile::Exists(SETTINGS_XML_FOLDER "freebsd.xml") && !Initialize(SETTINGS_XML_FOLDER "freebsd.xml"))
     CLog::Log(LOGFATAL, "Unable to load freebsd-specific settings definitions");
+#elif defined(TARGET_NETBSD)
+  if (CFile::Exists(SETTINGS_XML_FOLDER "netbsd.xml") && !Initialize(SETTINGS_XML_FOLDER "netbsd.xml"))
+    CLog::Log(LOGFATAL, "Unable to load netbsd-specific settings definitions");
 #elif defined(HAS_IMXVPU)
   if (CFile::Exists(SETTINGS_XML_FOLDER "imx6.xml") && !Initialize(SETTINGS_XML_FOLDER "imx6.xml"))
     CLog::Log(LOGFATAL, "Unable to load imx6-specific settings definitions");
