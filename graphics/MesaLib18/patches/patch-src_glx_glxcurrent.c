$NetBSD: patch-src_glx_glxcurrent.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Interim fix for toolchain/50277.

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/glx/glxcurrent.c.orig	2018-02-09 02:17:59.000000000 +0000
+++ src/glx/glxcurrent.c
@@ -40,6 +40,18 @@
 #include "glx_error.h"
 
 /*
+ * MASSIVE KLUDGE!
+ * We need these to not be extern in libGL.so because of
+ * PR toolchain/50277
+ */
+#if defined(GLX_USE_TLS) && defined(__NetBSD__)
+_X_EXPORT __thread struct _glapi_table * _glapi_tls_Dispatch
+    __attribute__((tls_model("initial-exec"))) = NULL;
+_X_EXPORT __thread void * _glapi_tls_Context
+    __attribute__((tls_model("initial-exec")));
+#endif
+
+/*
 ** We setup some dummy structures here so that the API can be used
 ** even if no context is current.
 */
@@ -77,7 +89,11 @@ _X_HIDDEN pthread_mutex_t __glXmutex = P
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
