$NetBSD: patch-src_mapi_u__current.h,v 1.1 2018/10/07 23:49:31 ryoon Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/mapi/u_current.h.orig	2015-09-02 17:06:23.000000000 +0000
+++ src/mapi/u_current.h
@@ -68,7 +68,7 @@ u_current_get_context_internal(void);
 static inline const struct _glapi_table *
 u_current_get_table(void)
 {
-#ifdef GLX_USE_TLS
+#if defined(GLX_USE_TLS) && !defined(__NetBSD__)
    return u_current_table;
 #else
    return (likely(u_current_table) ?
