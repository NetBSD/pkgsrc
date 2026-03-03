$NetBSD: patch-source_helpers_pkcs7_pkcs7-openssl.c,v 1.2 2026/03/03 21:49:01 yhardy Exp $

Add default_paths to STORE for checking signatures.
From OpenBSD ports.

--- source/helpers/pkcs7/pkcs7-openssl.c.orig	2026-02-18 16:24:19.000000000 +0000
+++ source/helpers/pkcs7/pkcs7-openssl.c
@@ -209,7 +209,7 @@ static int stream_free(BIO *b)
 	return 1;
 }
 
-static long stream_callback_ctrl(BIO *b, int cmd, bio_info_cb *fp)
+static long stream_callback_ctrl(BIO *b, int cmd, BIO_info_cb *fp)
 {
 	return 1;
 }
@@ -524,6 +524,9 @@ check_certificate(fz_context *ctx, pdf_pkcs7_verifier 
 			X509_STORE_add_cert(st, c);
 		}
 	}
+
+	/* Add default paths */
+	X509_STORE_set_default_paths(st);
 
 	res = pk7_verify_cert(st, pk7sig);
 
