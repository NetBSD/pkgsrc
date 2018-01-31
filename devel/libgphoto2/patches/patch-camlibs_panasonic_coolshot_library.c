$NetBSD: patch-camlibs_panasonic_coolshot_library.c,v 1.1 2018/01/31 10:53:40 jperkin Exp $

Set _POSIX_C_SOURCE correctly.

--- camlibs/panasonic/coolshot/library.c.orig	2014-06-27 05:31:22.000000000 +0000
+++ camlibs/panasonic/coolshot/library.c
@@ -24,7 +24,9 @@
 /* Boston, MA  02110-1301  USA					*/
 /****************************************************************/
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_C_SOURCE 199309L
+#endif
 #define _BSD_SOURCE
 
 #include "config.h"
