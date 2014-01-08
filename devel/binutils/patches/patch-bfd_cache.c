$NetBSD: patch-bfd_cache.c,v 1.1 2014/01/08 21:04:15 jperkin Exp $

Fix sign-compare on SunOS.

--- bfd/cache.c.orig	2013-11-04 15:33:37.000000000 +0000
+++ bfd/cache.c
@@ -82,7 +82,11 @@ bfd_cache_max_open (void)
 #ifdef HAVE_GETRLIMIT
       struct rlimit rlim;
       if (getrlimit (RLIMIT_NOFILE, &rlim) == 0
+#ifdef __sun
+	  && rlim.rlim_cur != (rlim_t)RLIM_INFINITY)
+#else
 	  && rlim.rlim_cur != RLIM_INFINITY)
+#endif
 	max = rlim.rlim_cur / 8;
       else
 #endif /* HAVE_GETRLIMIT */
