$NetBSD: patch-plugins_preauth_pkinit_pkinit__crypto__openssl.c,v 1.1 2026/04/07 14:12:48 tnn Exp $

https://github.com/krb5/krb5/commit/ad4dcf1856dadc4b352b5c8ff08e51c7290fb41f

--- plugins/preauth/pkinit/pkinit_crypto_openssl.c.orig	2026-04-07 12:42:05.472824469 +0000
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.c
@@ -4999,7 +4999,7 @@ load_cas_and_crls(krb5_context context,
                   pkinit_req_crypto_context req_cryptoctx,
                   pkinit_identity_crypto_context id_cryptoctx,
                   int catype,
-                  char *filename)
+                  const char *filename)
 {
     STACK_OF(X509_INFO) *sk = NULL;
     STACK_OF(X509) *ca_certs = NULL;
@@ -5157,7 +5157,7 @@ load_cas_and_crls_dir(krb5_context conte
                       pkinit_req_crypto_context req_cryptoctx,
                       pkinit_identity_crypto_context id_cryptoctx,
                       int catype,
-                      char *dirname)
+                      const char *dirname)
 {
     krb5_error_code retval = EINVAL;
     char **fnames = NULL, *filename;
@@ -5201,7 +5201,7 @@ crypto_load_cas_and_crls(krb5_context co
                          pkinit_identity_crypto_context id_cryptoctx,
                          int idtype,
                          int catype,
-                         char *id)
+                         const char *id)
 {
     switch (idtype) {
     case IDTYPE_FILE:
