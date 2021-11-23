$NetBSD: patch-camlibs_panasonic_coolshot_library.c,v 1.2 2021/11/23 14:28:34 ryoon Exp $

Set _POSIX_C_SOURCE correctly.

--- camlibs/panasonic/coolshot/library.c.orig	2020-07-30 11:14:29.000000000 +0000
+++ camlibs/panasonic/coolshot/library.c
@@ -24,7 +24,9 @@
 /* Boston, MA  02110-1301  USA					*/
 /****************************************************************/
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_C_SOURCE 199309L
+#endif
 #define _DEFAULT_SOURCE
 
 #include "config.h"
