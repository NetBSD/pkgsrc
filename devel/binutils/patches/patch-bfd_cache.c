$NetBSD: patch-bfd_cache.c,v 1.2 2014/05/12 13:17:01 jperkin Exp $

Fix sign-compare on SunOS.
Handle 256 file descriptor limit in 32-bit SunOS environment.

--- bfd/cache.c.orig	2013-11-04 15:33:37.000000000 +0000
+++ bfd/cache.c
@@ -51,6 +51,10 @@ SUBSECTION
 #include <sys/mman.h>
 #endif
 
+#if defined(__sun) && !defined(_LP64)
+#include <limits.h>
+#endif
+
 /* In some cases we can optimize cache operation when reopening files.
    For instance, a flush is entirely unnecessary if the file is already
    closed, so a flush would use CACHE_NO_OPEN.  Similarly, a seek using
@@ -81,8 +85,13 @@ bfd_cache_max_open (void)
       int max;
 #ifdef HAVE_GETRLIMIT
       struct rlimit rlim;
+#ifdef __sun
+      if (getrlimit (RLIMIT_NOFILE, &rlim) == 0
+	  && rlim.rlim_cur != (rlim_t)RLIM_INFINITY)
+#else
       if (getrlimit (RLIMIT_NOFILE, &rlim) == 0
 	  && rlim.rlim_cur != RLIM_INFINITY)
+#endif
 	max = rlim.rlim_cur / 8;
       else
 #endif /* HAVE_GETRLIMIT */
@@ -91,6 +100,9 @@ bfd_cache_max_open (void)
 #else
 	max = 10;
 #endif /* _SC_OPEN_MAX */
+#if defined(__sun) && !defined(_LP64)
+      max = max > (OPEN_MAX / 8) ? (OPEN_MAX / 8) : max;
+#endif
       max_open_files = max < 10 ? 10 : max;
     }
 
