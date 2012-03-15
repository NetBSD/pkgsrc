$NetBSD: patch-mozilla_media_libvpx_vpx__config__c.c,v 1.1.1.1 2012/03/15 09:45:29 ryoon Exp $

--- mozilla/media/libvpx/vpx_config_c.c.orig	2012-02-16 10:25:19.000000000 +0000
+++ mozilla/media/libvpx/vpx_config_c.c
@@ -12,12 +12,12 @@
 /* 32 bit MacOS. */
 #include "vpx_config_x86-darwin9-gcc.c"
 
-#elif defined(__linux__) && defined(__i386__)
-/* 32 bit Linux. */
+#elif (defined(__linux__) | defined(__DragonFly__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__MirBSD__)) && defined(__i386__)
+/* 32 bit Linux or BSD. */
 #include "vpx_config_x86-linux-gcc.c"
 
-#elif defined(__linux__) && defined(__x86_64__)
-/* 64 bit Linux. */
+#elif (defined(__linux__) | defined(__DragonFly__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__MirBSD__)) && defined(__x86_64__)
+/* 64 bit Linux or BSD. */
 #include "vpx_config_x86_64-linux-gcc.c"
 
 #elif defined(__sun) && defined(__i386)
