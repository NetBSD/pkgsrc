$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.1 2023/09/06 10:40:30 hauke Exp $

--- media/libcubeb/src/cubeb_alsa.c.orig	2020-08-28 21:33:11.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c
@@ -7,6 +7,7 @@
 #undef NDEBUG
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
+#define _NETBSD_SOURCE
 #define _XOPEN_SOURCE 500
 #include "cubeb-internal.h"
 #include "cubeb/cubeb.h"
