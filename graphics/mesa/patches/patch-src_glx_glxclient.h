$NetBSD: patch-src_glx_glxclient.h,v 1.1 2026/11/23 10:29:52 adam Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/glx/glxclient.h.orig	2025-01-22 18:12:23.000000000 +0000
+++ src/glx/glxclient.h
@@ -648,7 +648,11 @@ extern void __glXSetCurrentContext(struc
 
 extern __THREAD_INITIAL_EXEC void *__glX_tls_Context;
 
+#if defined(__NetBSD__)
+#  define __glXGetCurrentContext() (likely(__glX_tls_Context) ? __glX_tls_Context : (void*)&dummyContext)
+#else
 #  define __glXGetCurrentContext() __glX_tls_Context
+#endif
 
 extern void __glXSetCurrentContextNull(void);
 
