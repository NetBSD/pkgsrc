$NetBSD: patch-lib_dns_pkcs11dh_link.c,v 1.1 2015/09/02 19:46:44 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/pkcs11dh_link.c.orig	2015-09-02 00:44:20.000000000 +0000
+++ lib/dns/pkcs11dh_link.c
@@ -632,8 +632,10 @@ pkcs11dh_destroy(dst_key_t *key) {
 
 static void
 uint16_toregion(isc_uint16_t val, isc_region_t *region) {
-	*region->base++ = (val & 0xff00) >> 8;
-	*region->base++ = (val & 0x00ff);
+	*region->base = (val & 0xff00) >> 8;
+	isc_region_consume(region, 1);
+	*region->base = (val & 0x00ff);
+	isc_region_consume(region, 1);
 }
 
 static isc_uint16_t
@@ -644,7 +646,8 @@ uint16_fromregion(isc_region_t *region) 
 	val = ((unsigned int)(cp[0])) << 8;
 	val |= ((unsigned int)(cp[1]));
 
-	region->base += 2;
+	isc_region_consume(region, 2);
+
 	return (val);
 }
 
@@ -708,16 +711,16 @@ pkcs11dh_todns(const dst_key_t *key, isc
 	}
 	else
 		memmove(r.base, prime, plen);
-	r.base += plen;
+	isc_region_consume(&r, plen);
 
 	uint16_toregion(glen, &r);
 	if (glen > 0)
 		memmove(r.base, base, glen);
-	r.base += glen;
+	isc_region_consume(&r, glen);
 
 	uint16_toregion(publen, &r);
 	memmove(r.base, pub, publen);
-	r.base += publen;
+	isc_region_consume(&r, publen);
 
 	isc_buffer_add(data, dnslen);
 
@@ -764,10 +767,12 @@ pkcs11dh_fromdns(dst_key_t *key, isc_buf
 	}
 	plen_ = plen;
 	if (plen == 1 || plen == 2) {
-		if (plen == 1)
-			special = *r.base++;
-		else
+		if (plen == 1) {
+			special = *r.base;
+			isc_region_consume(&r, 1);
+		} else {
 			special = uint16_fromregion(&r);
+		}
 		switch (special) {
 			case 1:
 				prime = pk11_dh_bn768;
@@ -789,7 +794,7 @@ pkcs11dh_fromdns(dst_key_t *key, isc_buf
 	}
 	else {
 		prime = r.base;
-		r.base += plen;
+		isc_region_consume(&r, plen);
 	}
 
 	/*
@@ -835,7 +840,7 @@ pkcs11dh_fromdns(dst_key_t *key, isc_buf
 		}
 		base = r.base;
 	}
-	r.base += glen;
+	isc_region_consume(&r, glen);
 
 	if (r.length < 2) {
 		memset(dh, 0, sizeof(*dh));
@@ -849,7 +854,7 @@ pkcs11dh_fromdns(dst_key_t *key, isc_buf
 		return (DST_R_INVALIDPUBLICKEY);
 	}
 	pub = r.base;
-	r.base += publen;
+	isc_region_consume(&r, publen);
 
 	key->key_size = pk11_numbits(prime, plen_);
 
