$NetBSD: patch-extension_inplace.c,v 1.3 2026/02/23 13:30:37 wiz Exp $

Support SunOS in C99 mode.

--- extension/inplace.c.orig	2025-07-30 04:20:31.000000000 +0000
+++ extension/inplace.c
@@ -27,11 +27,13 @@
 #include <config.h>
 #endif
 
+#if !(defined(__sun) && (__STDC_VERSION__ - 0 >= 199901L))
 #ifndef _XOPEN_SOURCE
 # define _XOPEN_SOURCE 1
 #endif
 #ifndef _XOPEN_SOURCE_EXTENDED
 # define _XOPEN_SOURCE_EXTENDED 1
+#endif
 #endif
 
 #include <stdio.h>
