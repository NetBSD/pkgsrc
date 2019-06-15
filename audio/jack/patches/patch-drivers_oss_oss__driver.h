$NetBSD: patch-drivers_oss_oss__driver.h,v 1.1 2019/06/15 08:21:33 adam Exp $

Use proper OSS device.

--- drivers/oss/oss_driver.h.orig	2016-02-23 15:13:53.000000000 +0000
+++ drivers/oss/oss_driver.h
@@ -35,7 +35,11 @@
 #include "driver.h"
 
 
+#if defined(DEVOSSAUDIO)
+#define OSS_DRIVER_DEF_DEV	DEVOSSAUDIO
+#else
 #define OSS_DRIVER_DEF_DEV      "/dev/dsp"
+#endif
 #define OSS_DRIVER_DEF_FS       48000
 #define OSS_DRIVER_DEF_BLKSIZE  1024
 #define OSS_DRIVER_DEF_NPERIODS 2
