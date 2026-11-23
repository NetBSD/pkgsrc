$NetBSD: patch-src_glx_glxcurrent.c,v 1.1 2026/11/23 10:29:52 adam Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/glx/glxcurrent.c.orig	2025-08-13 14:41:43.198379856 +0000
+++ src/glx/glxcurrent.c
@@ -51,7 +51,11 @@ pthread_mutex_t __glXmutex = PTHREAD_MUT
  * \b never be \c NULL.  This is important!  Because of this
  * \c __glXGetCurrentContext can be implemented as trivial macro.
  */
+#if defined(__NetBSD__)
+__THREAD_INITIAL_EXEC void *__glX_tls_Context = NULL; /* non-zero initializers not supported with dlopen */
+#else
 __THREAD_INITIAL_EXEC void *__glX_tls_Context = &dummyContext;
+#endif
 
 void
 __glXSetCurrentContext(struct glx_context * c)
