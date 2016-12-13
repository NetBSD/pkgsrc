$NetBSD: patch-libraries_libldap_tls__m.c,v 1.1 2016/12/13 10:38:06 he Exp $

Incorrect multi-keyword mode cipherstring parsing.
Lifted from https://bugzilla.redhat.com/show_bug.cgi?id=1238322
Fixes CVE-2015-3276.
Submitted upstream as ITS#8543
http://www.openldap.org/its/index.cgi/Incoming?id=8543

--- libraries/libldap/tls_m.c.orig	2016-02-05 23:57:45.000000000 +0000
+++ libraries/libldap/tls_m.c
@@ -621,17 +621,23 @@ nss_parse_ciphers(const char *cipherstr,
 			 */
 			if (mask || strength || protocol) {
 				for (i=0; i<ciphernum; i++) {
-					if (((ciphers_def[i].attr & mask) ||
-						 (ciphers_def[i].strength & strength) ||
-						 (ciphers_def[i].version & protocol)) &&
-						(cipher_list[i] != -1)) {
-						/* Enable the NULL ciphers only if explicity
-						 * requested */
-						if (ciphers_def[i].attr & SSL_eNULL) {
-							if (mask & SSL_eNULL)
-								cipher_list[i] = action;
-						} else
+					/* if more than one mask is provided
+					 * then AND logic applies (to match openssl)
+					 */
+					if ( cipher_list[i] == -1) )
+						continue;
+					if ( mask && ! (ciphers_def[i].attr & mask) )
+						continue;
+					if ( strength && ! (ciphers_def[i].strength & strength) )
+						continue;
+					if ( protocol && ! (ciphers_def[i].version & protocol) )
+						continue;
+					/* Enable the NULL ciphers only if explicity requested */
+					if (ciphers_def[i].attr & SSL_eNULL) {
+						if (mask & SSL_eNULL)
 							cipher_list[i] = action;
+					} else
+						cipher_list[i] = action;
 					}
 				}
 			} else {
