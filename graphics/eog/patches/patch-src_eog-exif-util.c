$NetBSD: patch-src_eog-exif-util.c,v 1.1 2018/05/16 13:13:32 jperkin Exp $

Ensure _XOPEN_SOURCE is set correctly on SunOS.

--- src/eog-exif-util.c.orig	2009-08-11 10:49:55.000000000 +0000
+++ src/eog-exif-util.c
@@ -28,7 +28,7 @@
 #include "config.h"
 #endif
 
-#ifdef HAVE_STRPTIME
+#if defined(HAVE_STRPTIME) && (!defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L)))
 #define _XOPEN_SOURCE
 #endif
 #include <time.h>
