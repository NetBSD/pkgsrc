$NetBSD: patch-plugins_ADM_audioDevices_Oss_ADM_deviceoss.cpp,v 1.1 2011/02/17 09:20:17 markd Exp $

--- plugins/ADM_audioDevices/Oss/ADM_deviceoss.cpp.orig	2007-09-25 22:01:54 +0300
+++ plugins/ADM_audioDevices/Oss/ADM_deviceoss.cpp	2008-09-18 14:08:20 +0300
@@ -26,9 +26,10 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 
-#if defined(ADM_BSD_FAMILY) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if defined(ADM_BSD_FAMILY) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 	#include <soundcard.h>
-	const char *dsp = DEVOSSAUDIO;;
+	const char *dsp = "/dev/dsp";
+	const char *device_mixer = "/dev/mixer";
 
 #elif defined(__OpenBSD__)
 	#include <soundcard.h>
