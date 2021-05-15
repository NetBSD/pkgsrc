$NetBSD: patch-src_gnutls.c,v 1.1 2021/05/15 11:54:48 nia Exp $

Fix building with newer GnuTLS. From FreeBSD Ports.

--- src/gnutls.c.orig	2008-12-06 17:36:33.000000000 +0000
+++ src/gnutls.c
@@ -18,7 +18,6 @@
 
 #include <glib.h>
 
-#include <gcrypt.h>
 #include <gnutls/gnutls.h>
 #include <gnutls/x509.h>
 
@@ -47,11 +46,11 @@ typedef struct {
 static gboolean
 verify_certificate (gnutls_session session, const char *hostname, GError **err)
 {
-	int status;
+	int res, status;
 
-	status = gnutls_certificate_verify_peers (session);
+	res = gnutls_certificate_verify_peers2 (session, &status);
 
-	if (status == GNUTLS_E_NO_CERTIFICATE_FOUND) {
+	if (res < 0 || status == GNUTLS_E_NO_CERTIFICATE_FOUND) {
 		g_set_error (err, SSL_ERROR,
 			     SSL_ERROR_CERTIFICATE,
 			     "No SSL certificate was sent.");
@@ -452,9 +451,6 @@ static gboolean gnutls_inited = FALSE;
 static void
 _gnutls_init (void)
 {
-	/* to disallow usage of the blocking /dev/random */
-	gcry_control (GCRYCTL_ENABLE_QUICK_RANDOM, 0);
-
 	gnutls_global_init ();
 	gnutls_inited = TRUE;
 }
