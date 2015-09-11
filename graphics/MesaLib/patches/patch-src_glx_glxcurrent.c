$NetBSD: patch-src_glx_glxcurrent.c,v 1.1 2015/09/11 16:27:30 tnn Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/glx/glxcurrent.c.orig	2015-09-02 17:06:23.000000000 +0000
+++ src/glx/glxcurrent.c
@@ -77,7 +77,11 @@ _X_HIDDEN pthread_mutex_t __glXmutex = P
  * \c __glXGetCurrentContext can be implemented as trivial macro.
  */
 __thread void *__glX_tls_Context __attribute__ ((tls_model("initial-exec")))
+#if defined(__NetBSD__)
+   = NULL; /* non-zero initializers not supported with dlopen */
+#else
    = &dummyContext;
+#endif
 
 _X_HIDDEN void
 __glXSetCurrentContext(struct glx_context * c)
