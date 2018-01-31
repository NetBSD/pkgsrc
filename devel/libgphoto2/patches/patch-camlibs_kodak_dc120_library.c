$NetBSD: patch-camlibs_kodak_dc120_library.c,v 1.1 2018/01/31 10:53:40 jperkin Exp $

Set _POSIX_C_SOURCE correctly.

--- camlibs/kodak/dc120/library.c.orig	2015-02-22 08:30:12.000000000 +0000
+++ camlibs/kodak/dc120/library.c
@@ -19,7 +19,9 @@
  */
 
 #define _BSD_SOURCE
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_C_SOURCE 199309L
+#endif
 #include "config.h"
 
 #include <stdio.h>
