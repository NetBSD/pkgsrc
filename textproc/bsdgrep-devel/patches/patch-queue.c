$NetBSD: patch-queue.c,v 1.1 2015/07/09 10:56:54 jperkin Exp $

Use nbcompat headers.

--- queue.c.orig	2004-01-02 15:00:34.000000000 +0000
+++ queue.c
@@ -29,3 +29,8 @@
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/cdefs.h>
+#else
 #include <sys/cdefs.h>
+#endif
 #ifndef lint
