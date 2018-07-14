$NetBSD: patch-extension_inplace.c,v 1.2 2018/07/14 13:47:32 adam Exp $

Support SunOS in C99 mode.

--- extension/inplace.c.orig	2018-02-23 08:44:11.000000000 +0000
+++ extension/inplace.c
@@ -27,12 +27,14 @@
 #include <config.h>
 #endif
 
+#if !(defined(__sun) && (__STDC_VERSION__ - 0 >= 199901L))
 #ifndef _XOPEN_SOURCE
 # define _XOPEN_SOURCE 1
 #endif
 #ifndef _XOPEN_SOURCE_EXTENDED
 # define _XOPEN_SOURCE_EXTENDED 1
 #endif
+#endif
 
 #include <stdio.h>
 #include <assert.h>
