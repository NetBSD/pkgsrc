$NetBSD: patch-camlibs_kodak_dc120_dc120.c,v 1.2 2021/11/23 14:28:34 ryoon Exp $

Set _POSIX_C_SOURCE correctly.

--- camlibs/kodak/dc120/dc120.c.orig	2020-08-28 14:32:42.000000000 +0000
+++ camlibs/kodak/dc120/dc120.c
@@ -19,7 +19,9 @@
  */
 
 #define _DEFAULT_SOURCE
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_C_SOURCE 199309L
+#endif
 
 #include "config.h"
 
