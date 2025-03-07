$NetBSD: patch-src_glx_glxcurrent.c,v 1.7 2025/03/07 07:00:33 wiz Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/glx/glxcurrent.c.orig	2021-08-04 18:49:29.150474000 +0000
+++ src/glx/glxcurrent.c
@@ -76,7 +76,11 @@ _X_HIDDEN pthread_mutex_t __glXmutex = P
  * \b never be \c NULL.  This is important!  Because of this
  * \c __glXGetCurrentContext can be implemented as trivial macro.
  */
+#if defined(__NetBSD__)
+__THREAD_INITIAL_EXEC void *__glX_tls_Context = NULL; /* non-zero initializers not supported with dlopen */
+#else
 __THREAD_INITIAL_EXEC void *__glX_tls_Context = &dummyContext;
+#endif
 
 _X_HIDDEN void
 __glXSetCurrentContext(struct glx_context * c)
