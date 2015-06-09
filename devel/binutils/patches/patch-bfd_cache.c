$NetBSD: patch-bfd_cache.c,v 1.3 2015/06/09 20:24:39 ryoon Exp $

Fix sign-compare on SunOS.
Handle 256 file descriptor limit in 32-bit SunOS environment.

--- bfd/cache.c.orig	2014-10-14 07:32:02.000000000 +0000
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
@@ -90,6 +94,9 @@ bfd_cache_max_open (void)
 #else
 	max = 10;
 #endif /* _SC_OPEN_MAX */
+#if defined(__sun) && !defined(_LP64)
+      max = max > (OPEN_MAX / 8) ? (OPEN_MAX / 8) : max;
+#endif
       max_open_files = max < 10 ? 10 : max;
     }
 
