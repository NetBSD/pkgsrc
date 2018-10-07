$NetBSD: patch-src_mapi_u__current.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/mapi/u_current.c.orig	2015-09-02 17:06:23.000000000 +0000
+++ src/mapi/u_current.c
@@ -101,7 +101,11 @@ extern void (*__glapi_noop_table[])(void
 
 __thread struct _glapi_table *u_current_table
     __attribute__((tls_model("initial-exec")))
+#if defined(__NetBSD__)
+    = NULL; /* non-zero initializers not supported with dlopen */
+#else
     = (struct _glapi_table *) table_noop_array;
+#endif
 
 __thread void *u_current_context
     __attribute__((tls_model("initial-exec")));
@@ -283,7 +287,11 @@ struct _glapi_table *
 u_current_get_table_internal(void)
 {
 #if defined(GLX_USE_TLS)
+#  if defined(__NetBSD__)
+   return (likely(u_current_table) ? u_current_table : (struct _glapi_table *) table_noop_array);
+#  else
    return u_current_table;
+#  endif
 #else
    if (ThreadSafe)
       return (struct _glapi_table *) tss_get(u_current_table_tsd);
