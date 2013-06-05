$NetBSD: patch-mono_utils_mono-mmap.c,v 1.1 2013/06/05 17:03:55 jperkin Exp $

Use posix_madvise on SunOS.

--- mono/utils/mono-mmap.c.orig	2013-04-25 09:01:42.000000000 +0000
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
