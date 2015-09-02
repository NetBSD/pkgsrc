$NetBSD: patch-lib_dns_hmac_link.c,v 1.1 2015/09/02 19:44:28 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/hmac_link.c.orig	2015-09-02 00:08:13.000000000 +0000
+++ lib/dns/hmac_link.c
@@ -76,7 +76,7 @@ hmacmd5_createctx(dst_key_t *key, dst_co
 	hmacmd5ctx = isc_mem_get(dctx->mctx, sizeof(isc_hmacmd5_t));
 	if (hmacmd5ctx == NULL)
 		return (ISC_R_NOMEMORY);
-	isc_hmacmd5_init(hmacmd5ctx, hkey->key, ISC_SHA1_BLOCK_LENGTH);
+	isc_hmacmd5_init(hmacmd5ctx, hkey->key, ISC_MD5_BLOCK_LENGTH);
 	dctx->ctxdata.hmacmd5ctx = hmacmd5ctx;
 	return (ISC_R_SUCCESS);
 }
@@ -139,7 +139,7 @@ hmacmd5_compare(const dst_key_t *key1, c
 	else if (hkey1 == NULL || hkey2 == NULL)
 		return (ISC_FALSE);
 
-	if (isc_safe_memcmp(hkey1->key, hkey2->key, ISC_SHA1_BLOCK_LENGTH))
+	if (isc_safe_memcmp(hkey1->key, hkey2->key, ISC_MD5_BLOCK_LENGTH))
 		return (ISC_TRUE);
 	else
 		return (ISC_FALSE);
@@ -150,17 +150,17 @@ hmacmd5_generate(dst_key_t *key, int pse
 	isc_buffer_t b;
 	isc_result_t ret;
 	unsigned int bytes;
-	unsigned char data[ISC_SHA1_BLOCK_LENGTH];
+	unsigned char data[ISC_MD5_BLOCK_LENGTH];
 
 	UNUSED(callback);
 
 	bytes = (key->key_size + 7) / 8;
-	if (bytes > ISC_SHA1_BLOCK_LENGTH) {
-		bytes = ISC_SHA1_BLOCK_LENGTH;
-		key->key_size = ISC_SHA1_BLOCK_LENGTH * 8;
+	if (bytes > ISC_MD5_BLOCK_LENGTH) {
+		bytes = ISC_MD5_BLOCK_LENGTH;
+		key->key_size = ISC_MD5_BLOCK_LENGTH * 8;
 	}
 
-	memset(data, 0, ISC_SHA1_BLOCK_LENGTH);
+	memset(data, 0, ISC_MD5_BLOCK_LENGTH);
 	ret = dst__entropy_getdata(data, bytes, ISC_TF(pseudorandom_ok != 0));
 
 	if (ret != ISC_R_SUCCESS)
@@ -169,7 +169,7 @@ hmacmd5_generate(dst_key_t *key, int pse
 	isc_buffer_init(&b, data, bytes);
 	isc_buffer_add(&b, bytes);
 	ret = hmacmd5_fromdns(key, &b);
-	memset(data, 0, ISC_SHA1_BLOCK_LENGTH);
+	memset(data, 0, ISC_MD5_BLOCK_LENGTH);
 
 	return (ret);
 }
@@ -223,7 +223,7 @@ hmacmd5_fromdns(dst_key_t *key, isc_buff
 
 	memset(hkey->key, 0, sizeof(hkey->key));
 
-	if (r.length > ISC_SHA1_BLOCK_LENGTH) {
+	if (r.length > ISC_MD5_BLOCK_LENGTH) {
 		isc_md5_init(&md5ctx);
 		isc_md5_update(&md5ctx, r.base, r.length);
 		isc_md5_final(&md5ctx, hkey->key);
@@ -236,6 +236,8 @@ hmacmd5_fromdns(dst_key_t *key, isc_buff
 	key->key_size = keylen * 8;
 	key->keydata.hmacmd5 = hkey;
 
+	isc_buffer_forward(data, r.length);
+
 	return (ISC_R_SUCCESS);
 }
 
@@ -512,6 +514,8 @@ hmacsha1_fromdns(dst_key_t *key, isc_buf
 	key->key_size = keylen * 8;
 	key->keydata.hmacsha1 = hkey;
 
+	isc_buffer_forward(data, r.length);
+
 	return (ISC_R_SUCCESS);
 }
 
@@ -790,6 +794,8 @@ hmacsha224_fromdns(dst_key_t *key, isc_b
 	key->key_size = keylen * 8;
 	key->keydata.hmacsha224 = hkey;
 
+	isc_buffer_forward(data, r.length);
+
 	return (ISC_R_SUCCESS);
 }
 
@@ -1068,6 +1074,8 @@ hmacsha256_fromdns(dst_key_t *key, isc_b
 	key->key_size = keylen * 8;
 	key->keydata.hmacsha256 = hkey;
 
+	isc_buffer_forward(data, r.length);
+
 	return (ISC_R_SUCCESS);
 }
 
@@ -1346,6 +1354,8 @@ hmacsha384_fromdns(dst_key_t *key, isc_b
 	key->key_size = keylen * 8;
 	key->keydata.hmacsha384 = hkey;
 
+	isc_buffer_forward(data, r.length);
+
 	return (ISC_R_SUCCESS);
 }
 
@@ -1624,6 +1634,8 @@ hmacsha512_fromdns(dst_key_t *key, isc_b
 	key->key_size = keylen * 8;
 	key->keydata.hmacsha512 = hkey;
 
+	isc_buffer_forward(data, r.length);
+
 	return (ISC_R_SUCCESS);
 }
 
