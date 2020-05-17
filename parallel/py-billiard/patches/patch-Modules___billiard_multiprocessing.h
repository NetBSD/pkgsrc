$NetBSD: patch-Modules___billiard_multiprocessing.h,v 1.2 2020/05/17 19:16:38 adam Exp $

Set _XOPEN_SOURCE correctly.

--- Modules/_billiard/multiprocessing.h.orig	2020-02-02 00:14:06.000000000 +0000
+++ Modules/_billiard/multiprocessing.h
@@ -3,10 +3,14 @@
 
 #define PY_SSIZE_T_CLEAN
 
-#ifdef __sun
+#if defined(__sun) && !defined(_XOPEN_SOURCE)
 /* The control message API is only available on Solaris
    if XPG 4.2 or later is requested. */
+# if (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE 500
+# else
+#define _XOPEN_SOURCE 600
+# endif
 #endif
 
 #include "Python.h"
