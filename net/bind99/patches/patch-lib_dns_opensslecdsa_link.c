$NetBSD: patch-lib_dns_opensslecdsa_link.c,v 1.1 2015/09/02 19:44:28 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/opensslecdsa_link.c.orig	2015-09-02 00:08:13.000000000 +0000
+++ lib/dns/opensslecdsa_link.c
@@ -159,9 +159,9 @@ opensslecdsa_sign(dst_context_t *dctx, i
 					       "ECDSA_do_sign",
 					       DST_R_SIGNFAILURE));
 	BN_bn2bin_fixed(ecdsasig->r, r.base, siglen / 2);
-	r.base += siglen / 2;
+	isc_region_consume(&r, siglen / 2);
 	BN_bn2bin_fixed(ecdsasig->s, r.base, siglen / 2);
-	r.base += siglen / 2;
+	isc_region_consume(&r, siglen / 2);
 	ECDSA_SIG_free(ecdsasig);
 	isc_buffer_add(sig, siglen);
 	ret = ISC_R_SUCCESS;
