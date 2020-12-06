$NetBSD: patch-bfd_cache.c,v 1.5 2020/12/06 18:07:53 fcambus Exp $

Fix sign-compare on SunOS.
Handle 256 file descriptor limit in 32-bit SunOS environment.

--- bfd/cache.c.orig	2020-07-24 09:12:19.000000000 +0000
+++ bfd/cache.c
@@ -49,6 +49,10 @@ SUBSECTION
 #include <sys/mman.h>
 #endif
 
+#if defined(__sun) && !defined(_LP64)
+#include <limits.h>
+#endif
+
 /* In some cases we can optimize cache operation when reopening files.
    For instance, a flush is entirely unnecessary if the file is already
    closed, so a flush would use CACHE_NO_OPEN.  Similarly, a seek using
