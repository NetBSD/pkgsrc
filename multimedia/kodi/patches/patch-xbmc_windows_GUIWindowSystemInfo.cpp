$NetBSD: patch-xbmc_windows_GUIWindowSystemInfo.cpp,v 1.1 2015/11/18 23:27:23 jmcneill Exp $

--- xbmc/windows/GUIWindowSystemInfo.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/windows/GUIWindowSystemInfo.cpp
@@ -157,7 +157,7 @@ void CGUIWindowSystemInfo::FrameMove()
     SET_CONTROL_LABEL(i++, g_sysinfo.GetCPUSerial());
 #endif
     SetControlLabel(i++, "%s %s", 22011, SYSTEM_CPU_TEMPERATURE);
-#if !defined(__arm__) || defined(TARGET_RASPBERRY_PI)
+#if !defined(__arm__) || defined(TARGET_RASPBERRY_PI) || defined(TARGET_NETBSD)
     SetControlLabel(i++, "%s %s", 13284, SYSTEM_CPUFREQUENCY);
 #endif
 #endif
