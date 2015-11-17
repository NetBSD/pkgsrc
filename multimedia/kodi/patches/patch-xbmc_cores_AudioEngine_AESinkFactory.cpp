$NetBSD: patch-xbmc_cores_AudioEngine_AESinkFactory.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/cores/AudioEngine/AESinkFactory.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/cores/AudioEngine/AESinkFactory.cpp
@@ -32,7 +32,7 @@
   #include "Sinks/AESinkDARWINIOS.h"
 #elif defined(TARGET_DARWIN_OSX)
   #include "Sinks/AESinkDARWINOSX.h"
-#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
+#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   #if defined(HAS_ALSA)
     #include "Sinks/AESinkALSA.h"
   #endif
@@ -71,7 +71,7 @@ void CAESinkFactory::ParseDevice(std::st
         driver == "DARWINIOS"  ||
 #elif defined(TARGET_DARWIN_OSX)
         driver == "DARWINOSX"  ||
-#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
+#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   #if defined(HAS_ALSA)
         driver == "ALSA"        ||
   #endif
@@ -116,7 +116,7 @@ IAESink *CAESinkFactory::TrySink(std::st
     sink = new CAESinkDARWINIOS();
 #elif defined(TARGET_DARWIN_OSX)
     sink = new CAESinkDARWINOSX();
-#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
+#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
  #if defined(HAS_PULSEAUDIO)
     if (driver == "PULSE")
       sink = new CAESinkPULSE();
@@ -225,7 +225,7 @@ void CAESinkFactory::EnumerateEx(AESinkI
   if(!info.m_deviceInfoList.empty())
     list.push_back(info);
 
-#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
+#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   // check if user wants us to do something specific
   if (getenv("AE_SINK"))
   {
