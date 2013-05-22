$NetBSD: patch-deps_uv_src_unix_thread.c,v 1.1 2013/05/22 15:17:07 mspo Exp $

Older NetBSD does not have pthread_condattr_setclock.
--- deps/uv/src/unix/thread.c.orig	2013-03-14 11:27:01.000000000 +0900
+++ deps/uv/src/unix/thread.c	2013-03-14 11:45:57.000000000 +0900
@@ -283,8 +283,10 @@
   if (pthread_condattr_init(&attr))
     return -1;
 
+#if !(defined(__NetBSD__) && (__NetBSD_Version__ < 699001600))
   if (pthread_condattr_setclock(&attr, CLOCK_MONOTONIC))
     goto error2;
+#endif
 
   if (pthread_cond_init(cond, &attr))
     goto error2;
