$NetBSD: patch-lib_krb5_ccache_ccbase.c,v 1.1 2026/04/07 14:12:48 tnn Exp $

https://github.com/krb5/krb5/commit/ad4dcf1856dadc4b352b5c8ff08e51c7290fb41f

--- lib/krb5/ccache/ccbase.c.orig	2026-04-07 12:37:27.187192166 +0000
+++ lib/krb5/ccache/ccbase.c
@@ -201,8 +201,8 @@ krb5_cc_register(krb5_context context, c
 krb5_error_code KRB5_CALLCONV
 krb5_cc_resolve (krb5_context context, const char *name, krb5_ccache *cache)
 {
-    char *pfx, *cp;
-    const char *resid;
+    char *pfx;
+    const char *cp, *resid;
     unsigned int pfxlen;
     krb5_error_code err;
     const krb5_cc_ops *ops;
