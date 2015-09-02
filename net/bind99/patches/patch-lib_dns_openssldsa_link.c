$NetBSD: patch-lib_dns_openssldsa_link.c,v 1.1 2015/09/02 19:44:28 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/openssldsa_link.c.orig	2015-09-02 00:08:13.000000000 +0000
+++ lib/dns/openssldsa_link.c
@@ -137,6 +137,7 @@ openssldsa_sign(dst_context_t *dctx, isc
 	DSA *dsa = key->keydata.dsa;
 	isc_region_t r;
 	DSA_SIG *dsasig;
+	unsigned int klen;
 #if USE_EVP
 	EVP_MD_CTX *evp_md_ctx = dctx->ctxdata.evp_md_ctx;
 	EVP_PKEY *pkey;
@@ -188,6 +189,7 @@ openssldsa_sign(dst_context_t *dctx, isc
 					       ISC_R_FAILURE));
 	}
 	free(sigbuf);
+
 #elif 0
 	/* Only use EVP for the Digest */
 	if (!EVP_DigestFinal_ex(evp_md_ctx, digest, &siglen)) {
@@ -209,11 +211,17 @@ openssldsa_sign(dst_context_t *dctx, isc
 					       "DSA_do_sign",
 					       DST_R_SIGNFAILURE));
 #endif
-	*r.base++ = (key->key_size - 512)/64;
+
+	klen = (key->key_size - 512)/64;
+	if (klen > 255)
+		return (ISC_R_FAILURE);
+	*r.base = klen;
+	isc_region_consume(&r, 1);
+
 	BN_bn2bin_fixed(dsasig->r, r.base, ISC_SHA1_DIGESTLENGTH);
-	r.base += ISC_SHA1_DIGESTLENGTH;
+	isc_region_consume(&r, ISC_SHA1_DIGESTLENGTH);
 	BN_bn2bin_fixed(dsasig->s, r.base, ISC_SHA1_DIGESTLENGTH);
-	r.base += ISC_SHA1_DIGESTLENGTH;
+	isc_region_consume(&r, ISC_SHA1_DIGESTLENGTH);
 	DSA_SIG_free(dsasig);
 	isc_buffer_add(sig, ISC_SHA1_DIGESTLENGTH * 2 + 1);
 
@@ -446,15 +454,16 @@ openssldsa_todns(const dst_key_t *key, i
 	if (r.length < (unsigned int) dnslen)
 		return (ISC_R_NOSPACE);
 
-	*r.base++ = t;
+	*r.base = t;
+	isc_region_consume(&r, 1);
 	BN_bn2bin_fixed(dsa->q, r.base, ISC_SHA1_DIGESTLENGTH);
-	r.base += ISC_SHA1_DIGESTLENGTH;
+	isc_region_consume(&r, ISC_SHA1_DIGESTLENGTH);
 	BN_bn2bin_fixed(dsa->p, r.base, key->key_size/8);
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 	BN_bn2bin_fixed(dsa->g, r.base, key->key_size/8);
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 	BN_bn2bin_fixed(dsa->pub_key, r.base, key->key_size/8);
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 
 	isc_buffer_add(data, dnslen);
 
@@ -479,29 +488,30 @@ openssldsa_fromdns(dst_key_t *key, isc_b
 		return (ISC_R_NOMEMORY);
 	dsa->flags &= ~DSA_FLAG_CACHE_MONT_P;
 
-	t = (unsigned int) *r.base++;
+	t = (unsigned int) *r.base;
+	isc_region_consume(&r, 1);
 	if (t > 8) {
 		DSA_free(dsa);
 		return (DST_R_INVALIDPUBLICKEY);
 	}
 	p_bytes = 64 + 8 * t;
 
-	if (r.length < 1 + ISC_SHA1_DIGESTLENGTH + 3 * p_bytes) {
+	if (r.length < ISC_SHA1_DIGESTLENGTH + 3 * p_bytes) {
 		DSA_free(dsa);
 		return (DST_R_INVALIDPUBLICKEY);
 	}
 
 	dsa->q = BN_bin2bn(r.base, ISC_SHA1_DIGESTLENGTH, NULL);
-	r.base += ISC_SHA1_DIGESTLENGTH;
+	isc_region_consume(&r, ISC_SHA1_DIGESTLENGTH);
 
 	dsa->p = BN_bin2bn(r.base, p_bytes, NULL);
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 
 	dsa->g = BN_bin2bn(r.base, p_bytes, NULL);
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 
 	dsa->pub_key = BN_bin2bn(r.base, p_bytes, NULL);
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 
 	key->key_size = p_bytes * 8;
 
