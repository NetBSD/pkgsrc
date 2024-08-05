$NetBSD: patch-include_my__thread__os__id.h,v 1.1 2024/08/05 01:23:59 jnemeth Exp $

--- include/my_thread_os_id.h.orig	2022-03-23 13:49:36.000000000 +0000
+++ include/my_thread_os_id.h
@@ -36,6 +36,10 @@
 #include <unistd.h>
 #endif
 
+#ifdef __NetBSD__
+#include <lwp.h>
+#endif
+
 #ifdef HAVE_PTHREAD_GETTHREADID_NP
 #include <pthread_np.h> /* pthread_getthreadid_np() */
 #endif                  /* HAVE_PTHREAD_GETTHREADID_NP */
@@ -83,6 +87,9 @@ static inline my_thread_os_id_t my_threa
   /* FreeBSD 10.2 */
   return pthread_getthreadid_np();
 #else
+#ifdef __NetBSD__
+  return (int)_lwp_self();
+#else
 #ifdef HAVE_INTEGER_PTHREAD_SELF
   /* Unknown platform, fallback. */
   return pthread_self();
@@ -90,6 +97,7 @@ static inline my_thread_os_id_t my_threa
   /* Feature not available. */
   return 0;
 #endif /* HAVE_INTEGER_PTHREAD_SELF */
+#endif /* __NetBSD__ */
 #endif /* HAVE_PTHREAD_GETTHREADID_NP */
 #endif /* _WIN32 */
 #endif /* HAVE_SYS_GETTID */
