$NetBSD: patch-lib_dns_opensslrsa_link.c,v 1.1 2015/09/02 19:46:44 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/opensslrsa_link.c.orig	2015-09-02 00:43:20.000000000 +0000
+++ lib/dns/opensslrsa_link.c
@@ -964,6 +964,7 @@ opensslrsa_fromdns(dst_key_t *key, isc_b
 	RSA *rsa;
 	isc_region_t r;
 	unsigned int e_bytes;
+	unsigned int length;
 #if USE_EVP
 	EVP_PKEY *pkey;
 #endif
@@ -971,6 +972,7 @@ opensslrsa_fromdns(dst_key_t *key, isc_b
 	isc_buffer_remainingregion(data, &r);
 	if (r.length == 0)
 		return (ISC_R_SUCCESS);
+	length = r.length;
 
 	rsa = RSA_new();
 	if (rsa == NULL)
@@ -981,17 +983,18 @@ opensslrsa_fromdns(dst_key_t *key, isc_b
 		RSA_free(rsa);
 		return (DST_R_INVALIDPUBLICKEY);
 	}
-	e_bytes = *r.base++;
-	r.length--;
+	e_bytes = *r.base;
+	isc_region_consume(&r, 1);
 
 	if (e_bytes == 0) {
 		if (r.length < 2) {
 			RSA_free(rsa);
 			return (DST_R_INVALIDPUBLICKEY);
 		}
-		e_bytes = ((*r.base++) << 8);
-		e_bytes += *r.base++;
-		r.length -= 2;
+		e_bytes = (*r.base) << 8;
+		isc_region_consume(&r, 1);
+		e_bytes += *r.base;
+		isc_region_consume(&r, 1);
 	}
 
 	if (r.length < e_bytes) {
@@ -999,14 +1002,13 @@ opensslrsa_fromdns(dst_key_t *key, isc_b
 		return (DST_R_INVALIDPUBLICKEY);
 	}
 	rsa->e = BN_bin2bn(r.base, e_bytes, NULL);
-	r.base += e_bytes;
-	r.length -= e_bytes;
+	isc_region_consume(&r, e_bytes);
 
 	rsa->n = BN_bin2bn(r.base, r.length, NULL);
 
 	key->key_size = BN_num_bits(rsa->n);
 
-	isc_buffer_forward(data, r.length);
+	isc_buffer_forward(data, length);
 
 #if USE_EVP
 	pkey = EVP_PKEY_new();
