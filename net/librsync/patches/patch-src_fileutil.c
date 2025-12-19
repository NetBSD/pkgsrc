$NetBSD: patch-src_fileutil.c,v 1.1 2025/12/19 12:27:03 nia Exp $

Maybe don't peek into internal libc symbols if we can avoid it.

Fixes build on SunOS.

--- src/fileutil.c.orig	2025-12-19 12:12:34.445444467 +0000
+++ src/fileutil.c
@@ -74,7 +74,7 @@
 #endif
 
 /* Use and prefer _fileno if it exists. */
-#ifdef HAVE__FILENO
+#if defined(HAVE__FILENO) && !defined(HAVE_FILENO)
 #  define fileno(f) _fileno((f))
 #endif
 
