$NetBSD: patch-libgphoto2_gphoto2-file.c,v 1.2 2021/11/23 14:28:34 ryoon Exp $

Set _POSIX_SOURCE correctly.

--- libgphoto2/gphoto2-file.c.orig	2021-01-31 09:15:29.000000000 +0000
+++ libgphoto2/gphoto2-file.c
@@ -24,7 +24,9 @@
  * This file contains internal functions. Use of these functions from
  * external software modules is considered <strong>deprecated</strong>.
  */
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_SOURCE
+#endif
 #define _DEFAULT_SOURCE
 #define _DARWIN_C_SOURCE
 
