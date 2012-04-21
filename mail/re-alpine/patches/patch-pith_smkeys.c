$NetBSD: patch-pith_smkeys.c,v 1.1.2.2 2012/04/21 16:21:00 tron Exp $

--- pith/smkeys.c.orig	2012-02-14 13:27:14.000000000 +0000
+++ pith/smkeys.c
@@ -277,7 +277,7 @@ char *
 get_x509_subject_email(X509 *x)
 {
     char *result = NULL;
-#if OPENSSL_VERSION_NUMBER >= 0x1000000f /* OpenSSL 1.0.0 */
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L /* OpenSSL 1.0.0 */
     STACK_OF(OPENSSL_STRING) *emails;
 #else /* OpenSSL 0.x and 1.0.0-dev/beta */
     STACK *emails;
