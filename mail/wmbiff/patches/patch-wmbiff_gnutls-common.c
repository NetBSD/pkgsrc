$NetBSD: patch-wmbiff_gnutls-common.c,v 1.2 2012/07/05 10:30:58 drochner Exp $

Fix build with GnuTLS 3.0.

--- wmbiff/gnutls-common.c.orig	2004-06-23 02:52:42.000000000 +0000
+++ wmbiff/gnutls-common.c
@@ -3,7 +3,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <gnutls/gnutls.h>
-#include <gnutls/extra.h>
 #include <gnutls/x509.h>
 #include <gnutls/openpgp.h>
 #include <time.h>
@@ -334,8 +333,8 @@ void print_openpgp_info(gnutls_session s
 void print_cert_vrfy(gnutls_session session)
 {
 
-	int status;
-	status = gnutls_certificate_verify_peers(session);
+	int verify_ret, status;
+	verify_ret = gnutls_certificate_verify_peers2(session, &status);
 	printf("\n");
 
 	if (status == GNUTLS_E_NO_CERTIFICATE_FOUND) {
@@ -508,7 +507,6 @@ void print_list(void)
 
 	printf("Compression methods:");
 	printf(" ZLIB");
-	printf(", LZO");
 	printf(", NULL\n");
 }
 
@@ -636,8 +634,6 @@ void parse_comp(char **comp, int ncomp, 
 				comp_priority[j++] = GNUTLS_COMP_NULL;
 			if (strncasecmp(comp[i], "ZLI", 3) == 0)
 				comp_priority[j++] = GNUTLS_COMP_ZLIB;
-			if (strncasecmp(comp[i], "LZO", 3) == 0)
-				comp_priority[j++] = GNUTLS_COMP_LZO;
 		}
 		comp_priority[j] = 0;
 	}
