$NetBSD: patch-src_slproc.c,v 1.1 2025/01/06 21:36:25 ktnb Exp $

Set _XOPEN_SOURCE correctly on SunOS.

--- src/slproc.c.orig	2022-08-05 10:33:27.000000000 +0000
+++ src/slproc.c
@@ -28,12 +28,14 @@ USA.
 # define _DEFAULT_SOURCE 1
 #endif
 
+#if !defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L))
 #ifndef _XOPEN_SOURCE
 # define _XOPEN_SOURCE 1
 #endif
 #ifndef _XOPEN_SOURCE_EXTENDED
 # define _XOPEN_SOURCE_EXTENDED 1
 #endif
+#endif
 
 #ifndef __EXTENSIONS__
 # define __EXTENSIONS__
