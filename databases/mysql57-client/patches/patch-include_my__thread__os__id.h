$NetBSD: patch-include_my__thread__os__id.h,v 1.1 2016/09/27 09:01:59 fhajny Exp $

Add support for NetBSD.

--- include/my_thread_os_id.h.orig	2016-08-25 11:52:06.000000000 +0000
+++ include/my_thread_os_id.h
@@ -30,6 +30,10 @@
 #include <pthread.h>                /* pthread_self */
 #endif
 
+#ifdef __NetBSD__
+#include <lwp.h>
+#endif
+
 #ifdef HAVE_PTHREAD_GETTHREADID_NP
 #include <pthread_np.h>             /* pthread_getthreadid_np() */
 #endif /* HAVE_PTHREAD_GETTHREADID_NP */
@@ -74,6 +78,9 @@ static inline my_thread_os_id_t my_threa
   /* FreeBSD 10.2 */
   return pthread_getthreadid_np();
 #else
+#ifdef __NetBSD__
+  return (int)_lwp_self();
+#else
 #ifdef HAVE_INTEGER_PTHREAD_SELF
   /* Unknown platform, fallback. */
   return pthread_self();
@@ -81,6 +88,7 @@ static inline my_thread_os_id_t my_threa
   /* Feature not available. */
   return 0;
 #endif /* HAVE_INTEGER_PTHREAD_SELF */
+#endif /* __NetBSD__ */
 #endif /* HAVE_PTHREAD_GETTHREADID_NP */
 #endif /* _WIN32 */
 #endif /* HAVE_SYS_GETTID */
