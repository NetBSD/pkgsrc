$NetBSD: patch-lib_dns_openssldh_link.c,v 1.1 2015/09/02 19:44:28 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/openssldh_link.c.orig	2015-09-02 00:08:13.000000000 +0000
+++ lib/dns/openssldh_link.c
@@ -266,8 +266,10 @@ openssldh_destroy(dst_key_t *key) {
 
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
@@ -278,7 +280,8 @@ uint16_fromregion(isc_region_t *region) 
 	val = ((unsigned int)(cp[0])) << 8;
 	val |= ((unsigned int)(cp[1]));
 
-	region->base += 2;
+	isc_region_consume(region, 2);
+
 	return (val);
 }
 
@@ -319,16 +322,16 @@ openssldh_todns(const dst_key_t *key, is
 	}
 	else
 		BN_bn2bin(dh->p, r.base);
-	r.base += plen;
+	isc_region_consume(&r, plen);
 
 	uint16_toregion(glen, &r);
 	if (glen > 0)
 		BN_bn2bin(dh->g, r.base);
-	r.base += glen;
+	isc_region_consume(&r, glen);
 
 	uint16_toregion(publen, &r);
 	BN_bn2bin(dh->pub_key, r.base);
-	r.base += publen;
+	isc_region_consume(&r, publen);
 
 	isc_buffer_add(data, dnslen);
 
@@ -369,10 +372,12 @@ openssldh_fromdns(dst_key_t *key, isc_bu
 		return (DST_R_INVALIDPUBLICKEY);
 	}
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
 				dh->p = &bn768;
@@ -387,10 +392,9 @@ openssldh_fromdns(dst_key_t *key, isc_bu
 				DH_free(dh);
 				return (DST_R_INVALIDPUBLICKEY);
 		}
-	}
-	else {
+	} else {
 		dh->p = BN_bin2bn(r.base, plen, NULL);
-		r.base += plen;
+		isc_region_consume(&r, plen);
 	}
 
 	/*
@@ -421,15 +425,14 @@ openssldh_fromdns(dst_key_t *key, isc_bu
 				return (DST_R_INVALIDPUBLICKEY);
 			}
 		}
-	}
-	else {
+	} else {
 		if (glen == 0) {
 			DH_free(dh);
 			return (DST_R_INVALIDPUBLICKEY);
 		}
 		dh->g = BN_bin2bn(r.base, glen, NULL);
 	}
-	r.base += glen;
+	isc_region_consume(&r, glen);
 
 	if (r.length < 2) {
 		DH_free(dh);
@@ -441,7 +444,7 @@ openssldh_fromdns(dst_key_t *key, isc_bu
 		return (DST_R_INVALIDPUBLICKEY);
 	}
 	dh->pub_key = BN_bin2bn(r.base, publen, NULL);
-	r.base += publen;
+	isc_region_consume(&r, publen);
 
 	key->key_size = BN_num_bits(dh->p);
 
