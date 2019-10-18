$NetBSD: patch-src_mapi_u__current.h,v 1.3 2019/10/18 09:57:07 nia Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/mapi/u_current.h.orig	2019-10-09 16:52:00.000000000 +0000
+++ src/mapi/u_current.h
@@ -65,7 +65,7 @@ u_current_get_context_internal(void);
 static inline const struct _glapi_table *
 u_current_get_table(void)
 {
-#ifdef USE_ELF_TLS
+#if defined(USE_ELF_TLS) && !defined(__NetBSD__)
    return u_current_table;
 #else
    return (likely(u_current_table) ?
