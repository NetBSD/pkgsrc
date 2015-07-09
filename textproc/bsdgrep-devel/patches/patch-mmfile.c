$NetBSD: patch-mmfile.c,v 1.1 2015/07/09 10:56:54 jperkin Exp $

Use nbcompat headers.

--- mmfile.c.orig	2007-12-06 20:33:48.000000000 +0000
+++ mmfile.c
@@ -29,3 +29,8 @@
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/cdefs.h>
+#else
 #include <sys/cdefs.h>
+#endif
 #ifndef lint
@@ -46,2 +51,5 @@ __RCSID("$NetBSD: mmfile.c,v 1.4 2007/12
 
+#ifndef SIZE_T_MAX
+#define SIZE_T_MAX SIZE_MAX
+#endif
 #define MAX_MAP_LEN (SIZE_T_MAX / 64)	/* ~70M is reasonable size */
