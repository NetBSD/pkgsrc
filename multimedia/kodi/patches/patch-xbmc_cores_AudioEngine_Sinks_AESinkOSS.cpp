$NetBSD: patch-xbmc_cores_AudioEngine_Sinks_AESinkOSS.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/cores/AudioEngine/Sinks/AESinkOSS.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/cores/AudioEngine/Sinks/AESinkOSS.cpp
@@ -30,7 +30,7 @@
 #include <sys/ioctl.h>
 #include <sys/fcntl.h>
 
-#if defined(OSS4) || defined(TARGET_FREEBSD)
+#if defined(OSS4) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   #include <sys/soundcard.h>
 #else
   #include <linux/soundcard.h>
