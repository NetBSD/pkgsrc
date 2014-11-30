$NetBSD: patch-mono_utils_mono-mmap.c,v 1.2 2014/11/30 08:40:51 spz Exp $

Use posix_madvise on SunOS.

--- mono/utils/mono-mmap.c.orig	2014-09-22 13:23:09.000000000 +0000
+++ mono/utils/mono-mmap.c
@@ -431,7 +431,7 @@ mono_mprotect (void *addr, size_t length
 			memset (addr, 0, length);
 #else
 		memset (addr, 0, length);
-#ifdef HAVE_MADVISE
+#if defined(HAVE_MADVISE) && !defined(__sun)
 		madvise (addr, length, MADV_DONTNEED);
 		madvise (addr, length, MADV_FREE);
 #else
