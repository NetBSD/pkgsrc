$NetBSD: patch-src_glx_glxclient.h,v 1.3 2022/03/13 15:50:05 tnn Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/glx/glxclient.h.orig	2021-08-04 18:49:29.150474000 +0000
+++ src/glx/glxclient.h
@@ -648,7 +648,11 @@ extern void __glXSetCurrentContext(struc
 
 extern __THREAD_INITIAL_EXEC void *__glX_tls_Context;
 
+#if defined(__NetBSD__)
+#  define __glXGetCurrentContext() (likely(__glX_tls_Context) ? __glX_tls_Context : (void*)&dummyContext)
+#else
 #  define __glXGetCurrentContext() __glX_tls_Context
+#endif
 
 # else
 
