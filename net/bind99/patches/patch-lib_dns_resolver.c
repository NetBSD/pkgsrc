$NetBSD: patch-lib_dns_resolver.c,v 1.3 2015/09/02 19:44:28 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/resolver.c.orig	2015-09-02 00:08:14.000000000 +0000
+++ lib/dns/resolver.c
@@ -9058,6 +9058,12 @@ dns_resolver_algorithm_supported(dns_res
 
 	REQUIRE(VALID_RESOLVER(resolver));
 
+	/*
+	 * DH is unsupported for DNSKEYs, see RFC 4034 sec. A.1.
+	 */
+	if ((alg == DST_ALG_DH) || (alg == DST_ALG_INDIRECT))
+		return (ISC_FALSE);
+
 #if USE_ALGLOCK
 	RWLOCK(&resolver->alglock, isc_rwlocktype_read);
 #endif
@@ -9077,6 +9083,7 @@ dns_resolver_algorithm_supported(dns_res
 #endif
 	if (found)
 		return (ISC_FALSE);
+
 	return (dst_algorithm_supported(alg));
 }
 
