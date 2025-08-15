$NetBSD: patch-src_security_x509_polyorb__x509.c,v 1.1 2025/08/15 08:10:03 dkazankov Exp $

Fix usage of undocumented old function

--- src/security/x509/polyorb_x509.c.orig	2024-08-23 19:03:44.000000000 +0300
+++ src/security/x509/polyorb_x509.c
@@ -161,7 +161,7 @@
     BIO *in;
     X509 *pkey = NULL;
 
-    in = BIO_new(BIO_s_file_internal());
+    in = BIO_new(BIO_s_file());
     if (in == NULL) {
         PolyORBerr(POLYORB_F_PEM_READ_CERTIFICATE_FILE, ERR_R_BUF_LIB);
         goto end;
@@ -193,7 +193,7 @@
     BIO *in;
     EVP_PKEY *pkey = NULL;
 
-    in = BIO_new(BIO_s_file_internal());
+    in = BIO_new(BIO_s_file());
     if (in == NULL) {
         PolyORBerr(POLYORB_F_PEM_READ_PRIVATEKEY_FILE, ERR_R_BUF_LIB);
         goto end;
