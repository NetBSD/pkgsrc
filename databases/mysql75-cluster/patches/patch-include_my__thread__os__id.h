$NetBSD: patch-include_my__thread__os__id.h,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- include/my_thread_os_id.h.orig	2021-09-14 09:08:08.000000000 +0000
+++ include/my_thread_os_id.h
@@ -37,6 +37,10 @@
 #include <pthread.h>                /* pthread_self */
 #endif
 
+#ifdef __NetBSD__
+#include <lwp.h>
+#endif
+
 #ifdef HAVE_PTHREAD_GETTHREADID_NP
 #include <pthread_np.h>             /* pthread_getthreadid_np() */
 #endif /* HAVE_PTHREAD_GETTHREADID_NP */
@@ -87,6 +91,9 @@ static inline my_thread_os_id_t my_threa
   /* FreeBSD 10.2 */
   return pthread_getthreadid_np();
 #else
+#ifdef __NetBSD__
+  return (int)_lwp_self();
+#else
 #ifdef HAVE_INTEGER_PTHREAD_SELF
   /* Unknown platform, fallback. */
   return pthread_self();
@@ -94,6 +101,7 @@ static inline my_thread_os_id_t my_threa
   /* Feature not available. */
   return 0;
 #endif /* HAVE_INTEGER_PTHREAD_SELF */
+#endif /* __NetBSD__ */
 #endif /* HAVE_PTHREAD_GETTHREADID_NP */
 #endif /* _WIN32 */
 #endif /* HAVE_SYS_GETTID */
