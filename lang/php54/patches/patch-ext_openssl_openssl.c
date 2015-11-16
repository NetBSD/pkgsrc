$NetBSD: patch-ext_openssl_openssl.c,v 1.4 2015/11/16 13:12:27 sevan Exp $

Unbreak when SSL library is without RAND_EGD() support.
Obtained from http://www.libressl.org/patches.html

--- ext/openssl/openssl.c.orig	Mon Nov 16 00:05:47 2015
+++ ext/openssl/openssl.c
@@ -915,11 +915,13 @@ static int php_openssl_load_rand_file(const char * fil
 
 	if (file == NULL) {
 		file = RAND_file_name(buffer, sizeof(buffer));
+#ifdef HAVE_SSL_RAND_EGD
 	} else if (RAND_egd(file) > 0) {
 		/* if the given filename is an EGD socket, don't
 		 * write anything back to it */
 		*egdsocket = 1;
 		return SUCCESS;
+#endif
 	}
 	if (file == NULL || !RAND_load_file(file, -1)) {
 		if (RAND_status() == 0) {
