$NetBSD: patch-src_ssl__env.c,v 1.1 2024/09/29 00:42:50 schmonz Exp $

Fix newly introduced non-C99.

--- src/ssl_env.c.orig	2024-09-09 15:44:27.000000000 +0000
+++ src/ssl_env.c
@@ -167,7 +167,7 @@ static int ssl_client_vars(X509 *cert,ST
   BIGNUM *bn;
   BIO *bio;
   char *x = 0;
-  int n;
+  int n, i;
   char *yname;
 
   if (!cert) return 1;
@@ -243,7 +243,7 @@ static int ssl_client_vars(X509 *cert,ST
   GENERAL_NAMES *extensions = X509_get_ext_d2i(cert,NID_subject_alt_name,0,0);
   int num = sk_GENERAL_NAME_num(extensions);  /* num = 0, if no SAN extensions */
 
-  for (int i = 0, n = 0; i < num; ++i) {
+  for (i = 0, n = 0; i < num; ++i) {
     const GENERAL_NAME *ext = sk_GENERAL_NAME_value(extensions,i);
     if (ext->type == GEN_DNS) {
       if (OBJ_sn2nid((const char*)ext->d.ia5) != V_ASN1_IA5STRING) continue;
@@ -338,7 +338,7 @@ static int ssl_server_vars(X509 *cert,ST
   BIGNUM *bn;
   BIO *bio;
   char *x = 0;
-  int n;
+  int n, i;
   char *yname;
 
   if (!cert) return 1;
@@ -411,7 +411,7 @@ static int ssl_server_vars(X509 *cert,ST
   GENERAL_NAMES *extensions = X509_get_ext_d2i(cert,NID_subject_alt_name,0,0);
   int num = sk_GENERAL_NAME_num(extensions);  /* num = 0, if no SAN extensions */
 
-  for (int i = 0, n = 0; i < num; ++i) {
+  for (i = 0, n = 0; i < num; ++i) {
     const GENERAL_NAME *ext = sk_GENERAL_NAME_value(extensions,i);
     if (ext->type == GEN_DNS) {
       if (OBJ_sn2nid((const char*)ext->d.ia5) != V_ASN1_IA5STRING) continue;
