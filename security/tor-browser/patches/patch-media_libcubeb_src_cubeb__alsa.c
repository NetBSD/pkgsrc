$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.4.6.1 2020/10/23 17:27:13 bsiegert Exp $

--- media/libcubeb/src/cubeb_alsa.c.orig	2019-12-02 12:23:28.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c
@@ -7,6 +7,7 @@
 #undef NDEBUG
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
+#define _NETBSD_SOURCE
 #define _XOPEN_SOURCE 500
 #include <pthread.h>
 #include <sys/time.h>
