$NetBSD: patch-lib_dns_rdata_generic_openpgpkey_61.c,v 1.1 2015/09/02 19:46:44 sevan Exp $

CVE-2015-5986 - An incorrect boundary check can trigger a REQUIRE assertion
failure in openpgpkey_61.c

--- lib/dns/rdata/generic/openpgpkey_61.c.orig	2015-09-02 00:43:20.000000000 +0000
+++ lib/dns/rdata/generic/openpgpkey_61.c
@@ -81,6 +81,8 @@ fromwire_openpgpkey(ARGS_FROMWIRE) {
 	 * Keyring.
 	 */
 	isc_buffer_activeregion(source, &sr);
+	if (sr.length < 1)
+		return (ISC_R_UNEXPECTEDEND);
 	isc_buffer_forward(source, sr.length);
 	return (mem_tobuffer(target, sr.base, sr.length));
 }
