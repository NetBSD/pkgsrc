$NetBSD: patch-libretro-common_rthreads_rthreads.c,v 1.1 2018/09/07 00:45:24 nia Exp $

FreeBSD needs _POSIX_C_SOURCE=200112L for CLOCK_REALTIME.

--- libretro-common/rthreads/rthreads.c.orig	2018-08-08 18:35:14.000000000 +0000
+++ libretro-common/rthreads/rthreads.c
@@ -22,7 +22,7 @@
 
 #ifdef __unix__
 #ifndef __sun__
-#define _POSIX_C_SOURCE 199309
+#define _POSIX_C_SOURCE 200112L
 #endif
 #endif
 
