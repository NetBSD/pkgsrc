$NetBSD: patch-src_util_Alloc.hxx,v 1.1 2015/01/25 14:10:03 pho Exp $

Some platforms (e.g. Darwin 9) don't have strndup(3), but the function
xstrndup() isn't used in the first place.

--- src/util/Alloc.hxx.orig	2014-10-24 22:28:53.000000000 +0000
+++ src/util/Alloc.hxx
@@ -54,14 +54,4 @@ gcc_malloc gcc_nonnull_all
 char *
 xstrdup(const char *s);
 
-/**
- * Duplicate a string.  Use free() to free it.
- *
- * This function never fails; in out-of-memory situations, it aborts
- * the process.
- */
-gcc_malloc gcc_nonnull_all
-char *
-xstrndup(const char *s, size_t n);
-
 #endif
