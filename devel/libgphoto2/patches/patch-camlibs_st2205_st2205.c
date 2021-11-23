$NetBSD: patch-camlibs_st2205_st2205.c,v 1.2 2021/11/23 14:28:34 ryoon Exp $

Set _POSIX_C_SOURCE correctly.

--- camlibs/st2205/st2205.c.orig	2021-01-31 09:15:29.000000000 +0000
+++ camlibs/st2205/st2205.c
@@ -18,7 +18,9 @@
  * Boston, MA  02110-1301  USA
  */
 #define _DEFAULT_SOURCE
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_C_SOURCE 1
+#endif
 #define _DARWIN_C_SOURCE
 #include "config.h"
 
