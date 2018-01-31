$NetBSD: patch-libgphoto2__port_gphoto2_gphoto2-port-portability.h,v 1.1 2018/01/31 10:53:40 jperkin Exp $

Set _XOPEN_SOURCE / _POSIX_C_SOURCE correctly.

--- libgphoto2_port/gphoto2/gphoto2-port-portability.h.orig	2014-06-27 05:26:01.000000000 +0000
+++ libgphoto2_port/gphoto2/gphoto2-port-portability.h
@@ -176,7 +176,9 @@ typedef struct {
 
 /* XOPEN needed for usleep */
 #ifndef _XOPEN_SOURCE
+# if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 # define _XOPEN_SOURCE 500
+# endif
 #else
 # if ((_XOPEN_SOURCE - 0) < 500)
 #  undef _XOPEN_SOURCE
@@ -186,7 +188,9 @@ typedef struct {
 
 /* for nanosleep */
 # ifndef _POSIX_C_SOURCE
+#  if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #  define _POSIX_C_SOURCE 199309
+#  endif
 # endif
 # include <time.h>
 
