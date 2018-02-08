$NetBSD: patch-src_eom-exif-util.c,v 1.1 2018/02/08 17:01:34 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- src/eom-exif-util.c.orig	2017-01-15 09:31:32.000000000 +0000
+++ src/eom-exif-util.c
@@ -29,9 +29,11 @@
 #endif
 
 #ifdef HAVE_STRPTIME
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE
 #define _XOPEN_SOURCE_EXTENDED 1
 #endif
+#endif
 #include <time.h>
 
 #include "eom-exif-util.h"
