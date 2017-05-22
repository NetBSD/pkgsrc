$NetBSD: patch-Modules___multiprocessing_multiprocessing.h,v 1.1 2017/05/22 16:45:19 jperkin Exp $

Only define _XOPEN_SOURCE if we aren't already using newer.

--- Modules/_multiprocessing/multiprocessing.h.orig	2016-12-17 20:05:07.000000000 +0000
+++ Modules/_multiprocessing/multiprocessing.h
@@ -3,7 +3,7 @@
 
 #define PY_SSIZE_T_CLEAN
 
-#ifdef __sun
+#if defined(__sun) && !(__STDC_VERSION__ - 0 >= 199901L)
 /* The control message API is only available on Solaris 
    if XPG 4.2 or later is requested. */
 #define _XOPEN_SOURCE 500
