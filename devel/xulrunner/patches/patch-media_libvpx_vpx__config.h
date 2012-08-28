$NetBSD: patch-media_libvpx_vpx__config.h,v 1.2 2012/08/28 12:42:01 ryoon Exp $

--- media/libvpx/vpx_config.h.orig	2012-08-08 20:20:44.000000000 +0000
+++ media/libvpx/vpx_config.h
@@ -16,12 +16,12 @@
 /* 32 bit MacOS. */
 #include "vpx_config_x86-darwin9-gcc.h"
 
-#elif defined(__linux__) && defined(__i386__)
-/* 32 bit Linux. */
+#elif (defined(__linux__) | defined(__DragonFly__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__MirBSD__)) && defined(__i386__)
+/* 32 bit Linux or some BSD. */
 #include "vpx_config_x86-linux-gcc.h"
 
-#elif defined(__linux__) && defined(__x86_64__)
-/* 64 bit Linux. */
+#elif (defined(__linux__) | defined(__DragonFly__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__MirBSD__)) && defined(__x86_64__)
+/* 64 bit Linux or some BSD. */
 #include "vpx_config_x86_64-linux-gcc.h"
 
 #elif defined(__sun) && defined(__i386)
