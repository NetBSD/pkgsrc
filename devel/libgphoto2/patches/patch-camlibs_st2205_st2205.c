$NetBSD: patch-camlibs_st2205_st2205.c,v 1.1 2018/01/31 10:53:40 jperkin Exp $

Set _POSIX_C_SOURCE correctly.

--- camlibs/st2205/st2205.c.orig	2014-07-22 21:59:09.000000000 +0000
+++ camlibs/st2205/st2205.c
@@ -18,7 +18,9 @@
  * Boston, MA  02110-1301  USA
  */
 #define _BSD_SOURCE
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_C_SOURCE 1
+#endif
 #include "config.h"
 
 #include <stdio.h>
