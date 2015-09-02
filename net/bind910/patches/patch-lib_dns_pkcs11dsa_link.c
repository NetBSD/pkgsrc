$NetBSD: patch-lib_dns_pkcs11dsa_link.c,v 1.1 2015/09/02 19:46:44 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/pkcs11dsa_link.c.orig	2015-09-02 00:44:29.000000000 +0000
+++ lib/dns/pkcs11dsa_link.c
@@ -388,6 +388,7 @@ pkcs11dsa_sign(dst_context_t *dctx, isc_
 	isc_region_t r;
 	pk11_context_t *pk11_ctx = dctx->ctxdata.pk11_ctx;
 	isc_result_t ret = ISC_R_SUCCESS;
+	unsigned int klen;
 
 	isc_buffer_availableregion(sig, &r);
 	if (r.length < ISC_SHA1_DIGESTLENGTH * 2 + 1)
@@ -399,7 +400,10 @@ pkcs11dsa_sign(dst_context_t *dctx, isc_
 	if (siglen != ISC_SHA1_DIGESTLENGTH * 2)
 		return (DST_R_SIGNFAILURE);
 
-	*r.base = (dctx->key->key_size - 512)/64;
+	klen = (dctx->key->key_size - 512)/64;
+	if (klen > 255)
+		return (ISC_R_FAILURE);
+	*r.base = klen;
 	isc_buffer_add(sig, ISC_SHA1_DIGESTLENGTH * 2 + 1);
 
     err:
@@ -744,23 +748,25 @@ pkcs11dsa_todns(const dst_key_t *key, is
 		return (ISC_R_NOSPACE);
 
 	memset(r.base, 0, dnslen);
-	*r.base++ = t;
+	*r.base = t;
+	isc_region_consume(&r, 1);
+
 	cp = (CK_BYTE *) subprime->pValue;
 	memmove(r.base + ISC_SHA1_DIGESTLENGTH - subprime->ulValueLen,
 		cp, subprime->ulValueLen);
-	r.base += ISC_SHA1_DIGESTLENGTH;
+	isc_region_consume(&r, ISC_SHA1_DIGESTLENGTH);
 	cp = (CK_BYTE *) prime->pValue;
 	memmove(r.base + key->key_size/8 - prime->ulValueLen,
 		cp, prime->ulValueLen);
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 	cp = (CK_BYTE *) base->pValue;
 	memmove(r.base + key->key_size/8 - base->ulValueLen,
 		cp, base->ulValueLen);
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 	cp = (CK_BYTE *) pub_key->pValue;
 	memmove(r.base + key->key_size/8 - pub_key->ulValueLen,
 		cp, pub_key->ulValueLen);
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 
 	isc_buffer_add(data, dnslen);
 
@@ -784,7 +790,8 @@ pkcs11dsa_fromdns(dst_key_t *key, isc_bu
 		return (ISC_R_NOMEMORY);
 	memset(dsa, 0, sizeof(*dsa));
 
-	t = (unsigned int) *r.base++;
+	t = (unsigned int) *r.base;
+	isc_region_consume(&r, 1);
 	if (t > 8) {
 		memset(dsa, 0, sizeof(*dsa));
 		isc_mem_put(key->mctx, dsa, sizeof(*dsa));
@@ -792,23 +799,23 @@ pkcs11dsa_fromdns(dst_key_t *key, isc_bu
 	}
 	p_bytes = 64 + 8 * t;
 
-	if (r.length < 1 + ISC_SHA1_DIGESTLENGTH + 3 * p_bytes) {
+	if (r.length < ISC_SHA1_DIGESTLENGTH + 3 * p_bytes) {
 		memset(dsa, 0, sizeof(*dsa));
 		isc_mem_put(key->mctx, dsa, sizeof(*dsa));
 		return (DST_R_INVALIDPUBLICKEY);
 	}
 
 	subprime = r.base;
-	r.base += ISC_SHA1_DIGESTLENGTH;
+	isc_region_consume(&r, ISC_SHA1_DIGESTLENGTH);
 
 	prime = r.base;
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 
 	base = r.base;
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 
 	pub_key = r.base;
-	r.base += p_bytes;
+	isc_region_consume(&r, p_bytes);
 
 	key->key_size = p_bytes * 8;
 
