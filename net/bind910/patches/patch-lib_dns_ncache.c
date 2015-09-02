$NetBSD: patch-lib_dns_ncache.c,v 1.1 2015/09/02 19:46:44 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/ncache.c.orig	2015-09-02 00:43:20.000000000 +0000
+++ lib/dns/ncache.c
@@ -615,13 +615,11 @@ dns_ncache_getsigrdataset(dns_rdataset_t
 		dns_name_fromregion(&tname, &remaining);
 		INSIST(remaining.length >= tname.length);
 		isc_buffer_forward(&source, tname.length);
-		remaining.length -= tname.length;
-		remaining.base += tname.length;
+		isc_region_consume(&remaining, tname.length);
 
 		INSIST(remaining.length >= 2);
 		type = isc_buffer_getuint16(&source);
-		remaining.length -= 2;
-		remaining.base += 2;
+		isc_region_consume(&remaining, 2);
 
 		if (type != dns_rdatatype_rrsig ||
 		    !dns_name_equal(&tname, name)) {
@@ -633,8 +631,7 @@ dns_ncache_getsigrdataset(dns_rdataset_t
 		INSIST(remaining.length >= 1);
 		trust = isc_buffer_getuint8(&source);
 		INSIST(trust <= dns_trust_ultimate);
-		remaining.length -= 1;
-		remaining.base += 1;
+		isc_region_consume(&remaining, 1);
 
 		raw = remaining.base;
 		count = raw[0] * 256 + raw[1];
