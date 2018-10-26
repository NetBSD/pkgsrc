$NetBSD: patch-libiberty_sigsetmask.c,v 1.1 2018/10/26 10:10:48 jperkin Exp $

Fix build on SunOS.

--- libiberty/sigsetmask.c.orig	2013-11-04 15:33:40.000000000 +0000
+++ libiberty/sigsetmask.c
@@ -15,7 +15,9 @@ be the value @code{1}).
 
 */
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901UL)
 #define _POSIX_SOURCE
+#endif
 #include <ansidecl.h>
 /* Including <sys/types.h> seems to be needed by ISC. */
 #include <sys/types.h>
