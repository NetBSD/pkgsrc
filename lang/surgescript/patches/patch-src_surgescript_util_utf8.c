$NetBSD: patch-src_surgescript_util_utf8.c,v 1.1 2021/02/28 08:06:52 nia Exp $

Much more than FreeBSD doesn't have <alloca.h>.

--- src/surgescript/util/utf8.c.orig	2021-01-22 18:42:07.000000000 +0000
+++ src/surgescript/util/utf8.c
@@ -24,9 +24,9 @@
 #include <malloc.h>
 #define snprintf _snprintf
 #else
-#ifndef __FreeBSD__
+#if defined(__linux__) || defined(__sun)
 #include <alloca.h>
-#endif /* __FreeBSD__ */
+#endif /* defined(__linux__) || defined(__sun) */
 #endif
 #include <assert.h>
 
