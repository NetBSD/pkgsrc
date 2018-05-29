$NetBSD: patch-kinkd-crypto__openssl.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Fix signness issues

--- kinkd/crypto_openssl.c.orig	2008-02-07 05:12:28.000000000 -0500
+++ kinkd/crypto_openssl.c	2018-05-28 19:32:47.287261308 -0400
@@ -239,7 +239,7 @@
 	rc_vchar_t *res;
 	AES_KEY k;
 
-	if (AES_set_encrypt_key(key->v, key->l << 3, &k) < 0)
+	if (AES_set_encrypt_key((unsigned char *)key->v, key->l << 3, &k) < 0)
 		return NULL;
 	/* allocate buffer for result */
 	if ((res = rc_vmalloc(data->l)) == NULL) {
@@ -247,7 +247,7 @@
 		EXITREQ_NOMEM();
 		return NULL;
 	}
-	AES_cbc_encrypt(data->v, res->v, data->l, &k, iv->v, AES_ENCRYPT);
+	AES_cbc_encrypt((unsigned char *)data->v, (unsigned char *)res->v, data->l, &k, (unsigned char *)iv->v, AES_ENCRYPT);
 
 	return res;
 }
@@ -258,7 +258,7 @@
 	rc_vchar_t *res;
 	AES_KEY k;
 
-	if (AES_set_decrypt_key(key->v, key->l << 3, &k) < 0)
+	if (AES_set_decrypt_key((unsigned char *)key->v, key->l << 3, &k) < 0)
 		return NULL;
 	/* allocate buffer for result */
 	if ((res = rc_vmalloc(data->l)) == NULL) {
@@ -266,7 +266,7 @@
 		EXITREQ_NOMEM();
 		return NULL;
 	}
-	AES_cbc_encrypt(data->v, res->v, data->l, &k, iv->v, AES_DECRYPT);
+	AES_cbc_encrypt((unsigned char *)data->v, (unsigned char *)res->v, data->l, &k, (unsigned char *)iv->v, AES_DECRYPT);
 
 	return res;
 }
@@ -291,7 +291,7 @@
 	rc_vchar_t *res;
 	AES_KEY k;
 
-	if (AES_set_encrypt_key(key->v, key->l << 3, &k) < 0)
+	if (AES_set_encrypt_key((unsigned char *)key->v, key->l << 3, &k) < 0)
 		return NULL;
 	/* allocate buffer for result */
 	if ((res = rc_vmalloc(data->l)) == NULL) {
@@ -299,7 +299,7 @@
 		EXITREQ_NOMEM();
 		return NULL;
 	}
-	AES_cts_encrypt(data->v, res->v, data->l, &k, iv->v, AES_ENCRYPT);
+	AES_cts_encrypt((unsigned char *)data->v, (unsigned char *)res->v, data->l, &k, (unsigned char *)iv->v, AES_ENCRYPT);
 
 	return res;
 }
@@ -310,7 +310,7 @@
 	rc_vchar_t *res;
 	AES_KEY k;
 
-	if (AES_set_decrypt_key(key->v, key->l << 3, &k) < 0)
+	if (AES_set_decrypt_key((unsigned char *)key->v, key->l << 3, &k) < 0)
 		return NULL;
 	/* allocate buffer for result */
 	if ((res = rc_vmalloc(data->l)) == NULL) {
@@ -318,7 +318,7 @@
 		EXITREQ_NOMEM();
 		return NULL;
 	}
-	AES_cts_encrypt(data->v, res->v, data->l, &k, iv->v, AES_DECRYPT);
+	AES_cts_encrypt((unsigned char *)data->v, (unsigned char *)res->v, data->l, &k, (unsigned char *)iv->v, AES_DECRYPT);
 
 	return res;
 }
@@ -348,17 +348,17 @@
 		memcpy(lastblk, ivec, AES_BLOCK_SIZE);
 		for (i = 0; i < fraglen; i++)
 			lastblk[i] ^= (in + cbclen + AES_BLOCK_SIZE)[i];
-		AES_encrypt(lastblk, out + cbclen, key);
+		AES_encrypt((unsigned char *)lastblk, out + cbclen, key);
 	} else {
 		/* Decrypt the last plainblock. */
-		AES_decrypt(in + cbclen, lastblk, key);
+		AES_decrypt(in + cbclen, (unsigned char *)lastblk, key);
 		for (i = 0; i < fraglen; i++)
 			(out + cbclen + AES_BLOCK_SIZE)[i] =
 			    lastblk[i] ^ (in + cbclen + AES_BLOCK_SIZE)[i];
 
 		/* Decrypt the second last block. */
 		memcpy(lastblk, in + cbclen + AES_BLOCK_SIZE, fraglen);
-		AES_decrypt(lastblk, out + cbclen, key);
+		AES_decrypt((unsigned char *)lastblk, out + cbclen, key);
 		if (cbclen == 0)
 			for (i = 0; i < AES_BLOCK_SIZE; i++)
 				(out + cbclen)[i] ^= ivec[i];
@@ -738,7 +738,7 @@
 	if ((res = rc_vmalloc(SHA_DIGEST_LENGTH)) == 0)
 		return(0);
 
-	SHA1_Final(res->v, (SHA_CTX *)c);
+	SHA1_Final((unsigned char *)res->v, (SHA_CTX *)c);
 	(void)free(c);
 
 	return(res);
@@ -792,7 +792,7 @@
 	if ((res = rc_vmalloc(MD5_DIGEST_LENGTH)) == 0)
 		return(0);
 
-	MD5_Final(res->v, (MD5_CTX *)c);
+	MD5_Final((unsigned char *)res->v, (MD5_CTX *)c);
 	(void)free(c);
 
 	return(res);
