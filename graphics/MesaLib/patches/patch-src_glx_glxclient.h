$NetBSD: patch-src_glx_glxclient.h,v 1.1 2015/09/11 16:27:30 tnn Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/glx/glxclient.h.orig	2015-09-02 17:06:23.000000000 +0000
+++ src/glx/glxclient.h
@@ -635,7 +635,11 @@ extern void __glXSetCurrentContext(struc
 extern __thread void *__glX_tls_Context
    __attribute__ ((tls_model("initial-exec")));
 
+#if defined(__NetBSD__)
+#  define __glXGetCurrentContext() (likely(__glX_tls_Context) ? __glX_tls_Context : (void*)&dummyContext)
+#else
 #  define __glXGetCurrentContext() __glX_tls_Context
+#endif
 
 # else
 
