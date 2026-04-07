$NetBSD: patch-plugins_preauth_pkinit_pkinit__identity.c,v 1.1 2026/04/07 14:12:48 tnn Exp $

https://github.com/krb5/krb5/commit/ad4dcf1856dadc4b352b5c8ff08e51c7290fb41f

--- plugins/preauth/pkinit/pkinit_identity.c.orig	2026-04-07 12:42:37.246002783 +0000
+++ plugins/preauth/pkinit/pkinit_identity.c
@@ -473,7 +473,7 @@ process_option_ca_crl(krb5_context conte
                       const char *value,
                       int catype)
 {
-    char *residual;
+    const char *residual;
     unsigned int typelen;
     int idtype;
 
