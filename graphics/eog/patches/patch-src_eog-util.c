$NetBSD: patch-src_eog-util.c,v 1.1 2018/05/16 13:13:32 jperkin Exp $

Ensure _XOPEN_SOURCE is set correctly on SunOS.

--- src/eog-util.c.orig	2010-11-13 13:16:52.000000000 +0000
+++ src/eog-util.c
@@ -27,7 +27,7 @@
 #endif
 
 #include <sys/time.h>
-#ifdef HAVE_STRPTIME
+#if defined(HAVE_STRPTIME) && (!defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L)))
 #define _XOPEN_SOURCE
 #endif /* HAVE_STRPTIME */
 
