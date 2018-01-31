$NetBSD: patch-libgphoto2_gphoto2-file.c,v 1.1 2018/01/31 10:53:40 jperkin Exp $

Set _POSIX_SOURCE correctly.

--- libgphoto2/gphoto2-file.c.orig	2014-11-05 20:37:59.000000000 +0000
+++ libgphoto2/gphoto2-file.c
@@ -24,7 +24,9 @@
  * This file contains internal functions. Use of these functions from
  * external software modules is considered <strong>deprecated</strong>.
  */
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_SOURCE
+#endif
 #define _BSD_SOURCE
 
 #include "config.h"
