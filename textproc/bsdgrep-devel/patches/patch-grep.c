$NetBSD: patch-grep.c,v 1.1 2015/07/09 10:56:54 jperkin Exp $

Use nbcompat headers.

--- grep.c.orig	2006-05-15 21:12:21.000000000 +0000
+++ grep.c
@@ -31,3 +31,8 @@
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/cdefs.h>
+#else
 #include <sys/cdefs.h>
+#endif
 #ifndef lint
