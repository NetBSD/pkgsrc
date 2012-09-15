$NetBSD: patch-src_modules_rlm_eap_types_rlm_eap_tls_rlm_eap_tls.c,v 1.1.2.2 2012/09/15 10:27:14 spz Exp $
Fix CVE-2012-3547, from freerdius git repository:
https://github.com/alandekok/freeradius-server/commit/78e5aed56c36a9231bc91ea5f55b3edf88a9d2a4

--- src/modules/rlm_eap/types/rlm_eap_tls/rlm_eap_tls.c.orig	2012-09-12 20:17:15.000000000 +0200
+++ src/modules/rlm_eap/types/rlm_eap_tls/rlm_eap_tls.c	2012-09-12 20:17:18.000000000 +0200
@@ -531,7 +531,7 @@
 	 */
 	buf[0] = '\0';
 	asn_time = X509_get_notAfter(client_cert);
-	if ((lookup <= 1) && asn_time && (asn_time->length < MAX_STRING_LEN)) {
+	if ((lookup <= 1) && asn_time && (asn_time->length < sizeof(buf))) {
 		memcpy(buf, (char*) asn_time->data, asn_time->length);
 		buf[asn_time->length] = '\0';
 		pairadd(&handler->certs,
