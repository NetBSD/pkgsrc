$NetBSD: patch-src_glx_glxcurrent.c,v 1.5 2022/03/13 15:50:05 tnn Exp $

Interim fix for toolchain/50277.

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/glx/glxcurrent.c.orig	2021-08-04 18:49:29.150474000 +0000
+++ src/glx/glxcurrent.c
@@ -40,6 +40,20 @@
 #include "glx_error.h"
 
 /*
+ * MASSIVE KLUDGE!
+ * We need these to not be extern in libGL.so because of
+ * PR toolchain/50277
+ */
+#if defined(USE_ELF_TLS) && defined(__NetBSD__)
+#define u_current_table _glapi_tls_Dispatch
+#define u_current_context _glapi_tls_Context
+_X_EXPORT __thread struct _glapi_table *u_current_table
+    __attribute__((tls_model("initial-exec"))) = NULL;
+_X_EXPORT __thread void * u_current_context
+    __attribute__((tls_model("initial-exec")));
+#endif
+
+/*
 ** We setup some dummy structures here so that the API can be used
 ** even if no context is current.
 */
@@ -76,7 +90,11 @@ _X_HIDDEN pthread_mutex_t __glXmutex = P
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
