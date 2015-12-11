$NetBSD: patch-src_common_compat__pthreads.c,v 1.1 2015/12/11 12:13:00 wiz Exp $

Disable a function that is not there on NetBSD before 7.
https://trac.torproject.org/projects/tor/ticket/17819

--- src/common/compat_pthreads.c.orig	2015-11-13 13:33:25.000000000 +0000
+++ src/common/compat_pthreads.c
@@ -186,12 +186,14 @@ tor_cond_init(tor_cond_t *cond)
   }
 
 #if defined(HAVE_CLOCK_GETTIME) && defined(CLOCK_MONOTONIC)
+#if !defined(__NetBSD__) || (defined(__NetBSD__) && __NetBSD_Version__ > 699999999)
   /* Use monotonic time so when we timedwait() on it, any clock adjustment
    * won't affect the timeout value. */
   if (pthread_condattr_setclock(&condattr, CLOCK_MONOTONIC)) {
     return -1;
   }
 #endif
+#endif
   if (pthread_cond_init(&cond->cond, &condattr)) {
     return -1;
   }
