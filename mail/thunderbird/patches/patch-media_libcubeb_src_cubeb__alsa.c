$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.2 2020/09/03 15:26:22 ryoon Exp $

--- media/libcubeb/src/cubeb_alsa.c.orig	2020-08-28 21:33:11.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c
@@ -7,6 +7,7 @@
 #undef NDEBUG
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
+#define _NETBSD_SOURCE
 #define _XOPEN_SOURCE 500
 #include <pthread.h>
 #include <sys/time.h>
