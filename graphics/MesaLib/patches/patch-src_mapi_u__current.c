$NetBSD: patch-src_mapi_u__current.c,v 1.4 2022/03/13 15:50:05 tnn Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/mapi/u_current.c.orig	2021-08-04 18:49:29.246474300 +0000
+++ src/mapi/u_current.c
@@ -101,7 +101,11 @@ extern void (*__glapi_noop_table[])(void
 #if defined(USE_ELF_TLS)
 
 __THREAD_INITIAL_EXEC struct _glapi_table *u_current_table
+#if defined(__NetBSD__)
+    = NULL; /* non-zero initializers not supported with dlopen */
+#else
     = (struct _glapi_table *) table_noop_array;
+#endif
 
 __THREAD_INITIAL_EXEC void *u_current_context;
 
@@ -251,7 +255,11 @@ struct _glapi_table *
 u_current_get_table_internal(void)
 {
 #if defined(USE_ELF_TLS)
+#  if defined(__NetBSD__)
+    return (likely(u_current_table) ? u_current_table : (struct _glapi_table *) table_noop_array);
+#  else
    return u_current_table;
+#  endif
 #else
    if (ThreadSafe)
       return (struct _glapi_table *) tss_get(u_current_table_tsd);
