$NetBSD: patch-lib_strncat.c,v 1.1 2014/03/25 07:53:35 obache Exp $

* strncat is defined as a macro in NetBSD-6

--- lib/strncat.c.orig	2013-12-04 15:02:02.000000000 +0000
+++ lib/strncat.c
@@ -19,6 +19,7 @@
 
 /* Specification.  */
 #include <string.h>
+#undef strncat
 
 char *
 strncat (char *dest, const char *src, size_t n)
