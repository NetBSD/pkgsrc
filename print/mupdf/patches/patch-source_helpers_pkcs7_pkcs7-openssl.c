$NetBSD: patch-source_helpers_pkcs7_pkcs7-openssl.c,v 1.1 2023/09/07 14:36:54 vins Exp $

Add default_paths to STORE for checking signatures.
From OpenBSD ports.

--- source/helpers/pkcs7/pkcs7-openssl.c.orig	2023-09-05 11:51:19.000000000 +0000
+++ source/helpers/pkcs7/pkcs7-openssl.c
@@ -203,7 +203,7 @@ static int stream_free(BIO *b)
 	return 1;
 }
 
-static long stream_callback_ctrl(BIO *b, int cmd, bio_info_cb *fp)
+static long stream_callback_ctrl(BIO *b, int cmd, BIO_info_cb *fp)
 {
 	return 1;
 }
@@ -519,6 +519,9 @@ check_certificate(fz_context *ctx, pdf_p
 		}
 	}
 
+	/* Add default paths */
+	X509_STORE_set_default_paths(st);
+
 	res = pk7_verify_cert(st, pk7sig);
 
 exit:
