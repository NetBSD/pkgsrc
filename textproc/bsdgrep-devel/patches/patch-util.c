$NetBSD: patch-util.c,v 1.1 2015/07/09 10:56:54 jperkin Exp $

Use nbcompat headers.

--- util.c.orig	2007-12-06 20:33:49.000000000 +0000
+++ util.c
@@ -29,3 +29,8 @@
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/cdefs.h>
+#else
 #include <sys/cdefs.h>
+#endif
 #ifndef lint
@@ -41,3 +46,7 @@ __RCSID("$NetBSD: util.c,v 1.5 2007/12/0
 #include <errno.h>
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/fts.h>
+#else
 #include <fts.h>
+#endif
 #include <regex.h>
