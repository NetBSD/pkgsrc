$NetBSD: patch-rts_PosixSource.h,v 1.1 2020/01/03 15:24:08 pho Exp $

Set _XOPEN_SOURCE correctly on SunOS. Fixed in later versions.

--- rts/PosixSource.h.orig	2013-04-18 21:22:46.000000000 +0000
+++ rts/PosixSource.h
@@ -11,7 +11,7 @@
 
 #include <ghcplatform.h>
 
-#if defined(freebsd_HOST_OS) || defined(dragonfly_HOST_OS)
+#if defined(freebsd_HOST_OS) || defined(dragonfly_HOST_OS) || (defined(__sun) && __STDC_VERSION__-0 >= 199901L)
 #define _POSIX_C_SOURCE 200112L
 #define _XOPEN_SOURCE   600
 #else
