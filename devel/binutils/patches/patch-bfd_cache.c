$NetBSD: patch-bfd_cache.c,v 1.4 2016/01/30 22:15:11 ryoon Exp $

Fix sign-compare on SunOS.
Handle 256 file descriptor limit in 32-bit SunOS environment.

--- bfd/cache.c.orig	2016-01-25 08:51:06.000000000 +0000
+++ bfd/cache.c
@@ -50,6 +50,10 @@ SUBSECTION
 #include <sys/mman.h>
 #endif
 
+#if defined(__sun) && !defined(_LP64)
+#include <limits.h>
+#endif
+
 /* In some cases we can optimize cache operation when reopening files.
    For instance, a flush is entirely unnecessary if the file is already
    closed, so a flush would use CACHE_NO_OPEN.  Similarly, a seek using
