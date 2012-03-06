$NetBSD: patch-media_libvpx_vpx__config.h,v 1.1 2012/03/06 12:34:09 ryoon Exp $

--- media/libvpx/vpx_config.h.orig	2012-01-29 11:24:47.000000000 +0100
+++ media/libvpx/vpx_config.h	2012-02-09 15:07:24.000000000 +0100
@@ -12,12 +12,12 @@
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
