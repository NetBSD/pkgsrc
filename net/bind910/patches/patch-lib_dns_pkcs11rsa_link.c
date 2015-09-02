$NetBSD: patch-lib_dns_pkcs11rsa_link.c,v 1.1 2015/09/02 19:46:44 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/pkcs11rsa_link.c.orig	2015-09-02 00:44:38.000000000 +0000
+++ lib/dns/pkcs11rsa_link.c
@@ -791,23 +791,21 @@ pkcs11rsa_fromdns(dst_key_t *key, isc_bu
 	unsigned int e_bytes, mod_bytes;
 	CK_BYTE *exponent = NULL, *modulus = NULL;
 	CK_ATTRIBUTE *attr;
+	unsigned int length;
 
 	isc_buffer_remainingregion(data, &r);
 	if (r.length == 0)
 		return (ISC_R_SUCCESS);
+	length = r.length;
 
 	rsa = (pk11_object_t *) isc_mem_get(key->mctx, sizeof(*rsa));
 	if (rsa == NULL)
 		return (ISC_R_NOMEMORY);
+
 	memset(rsa, 0, sizeof(*rsa));
 
-	if (r.length < 1) {
-		memset(rsa, 0, sizeof(*rsa));
-		isc_mem_put(key->mctx, rsa, sizeof(*rsa));
-		return (DST_R_INVALIDPUBLICKEY);
-	}
-	e_bytes = *r.base++;
-	r.length--;
+	e_bytes = *r.base;
+	isc_region_consume(&r, 1);
 
 	if (e_bytes == 0) {
 		if (r.length < 2) {
@@ -815,9 +813,10 @@ pkcs11rsa_fromdns(dst_key_t *key, isc_bu
 			isc_mem_put(key->mctx, rsa, sizeof(*rsa));
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
@@ -826,14 +825,13 @@ pkcs11rsa_fromdns(dst_key_t *key, isc_bu
 		return (DST_R_INVALIDPUBLICKEY);
 	}
 	exponent = r.base;
-	r.base += e_bytes;
-	r.length -= e_bytes;
+	isc_region_consume(&r, e_bytes);
 	modulus = r.base;
 	mod_bytes = r.length;
 
 	key->key_size = pk11_numbits(modulus, mod_bytes);
 
-	isc_buffer_forward(data, r.length);
+	isc_buffer_forward(data, length);
 
 	rsa->repr = (CK_ATTRIBUTE *) isc_mem_get(key->mctx, sizeof(*attr) * 2);
 	if (rsa->repr == NULL)
