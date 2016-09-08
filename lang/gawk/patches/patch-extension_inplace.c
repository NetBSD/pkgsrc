$NetBSD: patch-extension_inplace.c,v 1.1 2016/09/08 16:16:15 jperkin Exp $

Support SunOS in C99 mode.

--- extension/inplace.c.orig	2015-04-27 15:09:07.000000000 +0000
+++ extension/inplace.c
@@ -27,12 +27,14 @@
 #include <config.h>
 #endif
 
+#if !(defined(__sun) && (__STDC_VERSION__ - 0 >= 199901L))
 #ifndef _XOPEN_SOURCE
 # define _XOPEN_SOURCE
 #endif
 #ifndef _XOPEN_SOURCE_EXTENDED
 # define _XOPEN_SOURCE_EXTENDED 1
 #endif
+#endif
 
 #include <stdio.h>
 #include <assert.h>
