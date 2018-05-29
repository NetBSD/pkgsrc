$NetBSD: patch-iked_crypto__openssl.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Adjust for openssl-1.1

--- iked/crypto_openssl.c	2010-02-01 05:30:51.000000000 -0500
+++ iked/crypto_openssl.c	2018-05-28 17:08:27.806906241 -0400
@@ -324,16 +324,17 @@
 {
 	char buf[256];
 	int log_tag;
+	int ctx_error, ctx_error_depth;
 
 	if (!ok) {
-		X509_NAME_oneline(X509_get_subject_name(ctx->current_cert),
-				  buf, 256);
+		X509_NAME_oneline(X509_get_subject_name(
+		    X509_STORE_CTX_get0_cert(ctx)), buf, 256);
 		/*
 		 * since we are just checking the certificates, it is
 		 * ok if they are self signed. But we should still warn
 		 * the user.
 		 */
-		switch (ctx->error) {
+		switch (ctx_error = X509_STORE_CTX_get_error(ctx)) {
 		case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
 #if OPENSSL_VERSION_NUMBER >= 0x00905100L
 		case X509_V_ERR_INVALID_CA:
@@ -347,16 +348,17 @@
 		default:
 			log_tag = PLOG_PROTOERR;
 		}
+		ctx_error_depth = X509_STORE_CTX_get_error_depth(ctx);
 #ifndef EAYDEBUG
 		plog(log_tag, PLOGLOC, NULL,
 		     "%s(%d) at depth:%d SubjectName:%s\n",
-		     X509_verify_cert_error_string(ctx->error),
-		     ctx->error, ctx->error_depth, buf);
+		     X509_verify_cert_error_string(ctx_error),
+		     ctx_error, ctx_error_depth, buf);
 #else
 		printf("%d: %s(%d) at depth:%d SubjectName:%s\n",
 		       log_tag,
-		       X509_verify_cert_error_string(ctx->error),
-		       ctx->error, ctx->error_depth, buf);
+		       X509_verify_cert_error_string(ctx_error),
+		       ctx_error, ctx_error_depth, buf);
 #endif
 	}
 	ERR_clear_error();
@@ -991,6 +993,7 @@
 	BPP_const unsigned char *bp;
 	rc_vchar_t *sig = NULL;
 	int len;
+	RSA *rsa;
 	int pad = RSA_PKCS1_PADDING;
 
 	bp = (unsigned char *)privkey->v;
@@ -1002,14 +1005,15 @@
 	/* XXX: to be handled EVP_dss() */
 	/* XXX: Where can I get such parameters ?  From my cert ? */
 
-	len = RSA_size(evp->pkey.rsa);
+	rsa = EVP_PKEY_get0_RSA(evp);
+	len = RSA_size(rsa);
 
 	sig = rc_vmalloc(len);
 	if (sig == NULL)
 		return NULL;
 
 	len = RSA_private_encrypt(src->l, (unsigned char *)src->v,
-				  (unsigned char *)sig->v, evp->pkey.rsa, pad);
+				  (unsigned char *)sig->v, rsa, pad);
 	EVP_PKEY_free(evp);
 	if (len == 0 || (size_t)len != sig->l) {
 		rc_vfree(sig);
@@ -1028,6 +1032,7 @@
 	BPP_const unsigned char *bp;
 	rc_vchar_t *xbuf = NULL;
 	int pad = RSA_PKCS1_PADDING;
+	RSA *rsa;
 	int len = 0;
 	int error;
 
@@ -1040,7 +1045,8 @@
 		return -1;
 	}
 
-	len = RSA_size(evp->pkey.rsa);
+	rsa = EVP_PKEY_get0_RSA(evp);
+	len = RSA_size(rsa);
 
 	xbuf = rc_vmalloc(len);
 	if (xbuf == NULL) {
@@ -1053,7 +1059,7 @@
 	}
 
 	len = RSA_public_decrypt(sig->l, (unsigned char *)sig->v,
-				 (unsigned char *)xbuf->v, evp->pkey.rsa, pad);
+				 (unsigned char *)xbuf->v, rsa, pad);
 #ifndef EAYDEBUG
 	if (len == 0 || (size_t)len != src->l)
 		plog(PLOG_PROTOERR, PLOGLOC, NULL, "%s\n", eay_strerror());
@@ -1089,7 +1095,8 @@
 	rc_vchar_t *sig = 0;
 	unsigned int siglen;
 	const EVP_MD *md;
-	EVP_MD_CTX ctx;
+	EVP_MD_CTX *ctx = NULL;
+	RSA *rsa;
 
 	bp = (unsigned char *)privkey->v;
 	/* convert private key from vmbuf to internal data */
@@ -1100,7 +1107,8 @@
 		goto fail;
 	}
 
-	len = RSA_size(pkey->pkey.rsa);
+	rsa = EVP_PKEY_get0_RSA(pkey);
+	len = RSA_size(rsa);
 	sig = rc_vmalloc(len);
 	if (sig == NULL) {
 		plog(PLOG_INTERR, PLOGLOC, NULL, "failed allocating memory\n");
@@ -1114,27 +1122,33 @@
 		     "failed to find digest algorithm %s\n", hash_type);
 		goto fail;
 	}
-	EVP_MD_CTX_init(&ctx);
-	EVP_SignInit(&ctx, md);
-	EVP_SignUpdate(&ctx, octets->v, octets->l);
-	if (EVP_SignFinal(&ctx, (unsigned char *)sig->v, &siglen, pkey) <= 0) {
+	ctx = EVP_MD_CTX_new();
+	if (!ctx) {
+		plog(PLOG_INTERR, PLOGLOC, NULL,
+		     "failed to allocate context\n");
+		goto fail;
+	}
+	EVP_SignInit(ctx, md);
+	EVP_SignUpdate(ctx, octets->v, octets->l);
+	if (EVP_SignFinal(ctx, (unsigned char *)sig->v, &siglen, pkey) <= 0) {
 		plog(PLOG_INTERR, PLOGLOC, NULL,
 		     "RSA_sign failed: %s\n", eay_strerror());
-		EVP_MD_CTX_cleanup(&ctx);
 		goto fail;
 	}
-	EVP_MD_CTX_cleanup(&ctx);
 	if (sig->l != siglen) {
 		plog(PLOG_INTERR, PLOGLOC, NULL,
 		     "unexpected signature length %d\n", siglen);
 		goto fail;
 	}
+	EVP_MD_CTX_free(ctx);
 	EVP_PKEY_free(pkey);
 	return sig;
 
       fail:
 	if (sig)
 		rc_vfree(sig);
+	if (ctx)
+		EVP_MD_CTX_free(ctx);
 	if (pkey)
 		EVP_PKEY_free(pkey);
 	return 0;
@@ -1154,7 +1168,7 @@
 	EVP_PKEY *pkey;
 	BPP_const unsigned char *bp;
 	const EVP_MD *md;
-	EVP_MD_CTX ctx;
+	EVP_MD_CTX *ctx = NULL;
 
 	bp = (unsigned char *)pubkey->v;
 	pkey = d2i_PUBKEY(NULL, &bp, pubkey->l);
@@ -1163,7 +1177,7 @@
 		     "failed obtaining public key: %s\n", eay_strerror());
 		goto fail;
 	}
-	if (pkey->type != EVP_PKEY_RSA) {
+	if (EVP_PKEY_id(pkey) != EVP_PKEY_RSA) {
 		plog(PLOG_PROTOERR, PLOGLOC, NULL,
 		     "public key is not for RSA\n");
 		goto fail;
@@ -1175,23 +1189,29 @@
 		     "failed to find the algorithm engine for %s\n", hash_type);
 		goto fail;
 	}
-	EVP_MD_CTX_init(&ctx);
-	EVP_VerifyInit(&ctx, md);
-	EVP_VerifyUpdate(&ctx, octets->v, octets->l);
-	if (EVP_VerifyFinal(&ctx, (unsigned char *)sig->v, sig->l, pkey) <= 0) {
+	ctx = EVP_MD_CTX_new();
+	if (!ctx) {
+		plog(PLOG_INTERR, PLOGLOC, NULL,
+		     "failed to allocate context\n");
+		goto fail;
+	}
+	EVP_VerifyInit(ctx, md);
+	EVP_VerifyUpdate(ctx, octets->v, octets->l);
+	if (EVP_VerifyFinal(ctx, (unsigned char *)sig->v, sig->l, pkey) <= 0) {
 		plog(PLOG_PROTOERR, PLOGLOC, NULL,
 		     "RSA_verify failed: %s\n", eay_strerror());
-		EVP_MD_CTX_cleanup(&ctx);
 		goto fail;
 	}
-	EVP_MD_CTX_cleanup(&ctx);
 
+	EVP_MD_CTX_free(ctx);
 	EVP_PKEY_free(pkey);
 	return 0;
 
       fail:
 	if (pkey)
 		EVP_PKEY_free(pkey);
+	if (ctx)
+		EVP_MD_CTX_free(ctx);
 	return -1;
 }
 
@@ -1204,7 +1224,8 @@
 	EVP_PKEY *pkey;
 	BPP_const unsigned char *bp;
 	const EVP_MD *md;
-	EVP_MD_CTX ctx;
+	EVP_MD_CTX *ctx = NULL;
+	DSA *dsa;
 	int len;
 	rc_vchar_t *sig = 0;
 	unsigned int siglen;
@@ -1217,24 +1238,33 @@
 		goto fail;
 	}
 
-	len = DSA_size(pkey->pkey.dsa);
+	dsa = EVP_PKEY_get0_DSA(pkey);
+	len = DSA_size(dsa);
 	sig = rc_vmalloc(len);
 	if (sig == NULL) {
 		plog(PLOG_INTERR, PLOGLOC, NULL, "failed allocating memory\n");
 		goto fail;
 	}
 
+#if 0
 	md = EVP_dss1();
-	EVP_MD_CTX_init(&ctx);
-	EVP_SignInit(&ctx, md);
-	EVP_SignUpdate(&ctx, octets->v, octets->l);
-	if (EVP_SignFinal(&ctx, (unsigned char *)sig->v, &siglen, pkey) <= 0) {
+#else
+	md = NULL;
+	goto fail;
+#endif
+	ctx = EVP_MD_CTX_new();
+	if (!ctx) {
+		plog(PLOG_INTERR, PLOGLOC, NULL,
+		     "failed to allocate context\n");
+		goto fail;
+	}
+	EVP_SignInit(ctx, md);
+	EVP_SignUpdate(ctx, octets->v, octets->l);
+	if (EVP_SignFinal(ctx, (unsigned char *)sig->v, &siglen, pkey) <= 0) {
 		plog(PLOG_INTERR, PLOGLOC, NULL,
 		     "DSS sign failed: %s\n", eay_strerror());
-		EVP_MD_CTX_cleanup(&ctx);
 		goto fail;
 	}
-	EVP_MD_CTX_cleanup(&ctx);
 
 	if (siglen > sig->l) {
 		plog(PLOG_INTERR, PLOGLOC, NULL,
@@ -1245,6 +1275,7 @@
 	if (siglen < sig->l)
 		sig = rc_vrealloc(sig, siglen);
 	EVP_PKEY_free(pkey);
+	EVP_MD_CTX_free(ctx);
 	return sig;
 
       fail:
@@ -1252,6 +1283,8 @@
 		rc_vfree(sig);
 	if (pkey)
 		EVP_PKEY_free(pkey);
+	if (ctx)
+		EVP_MD_CTX_free(ctx);
 	return 0;
 }
 
@@ -1265,7 +1298,7 @@
 	EVP_PKEY *pkey;
 	BPP_const unsigned char *bp;
 	const EVP_MD *md;
-	EVP_MD_CTX ctx;
+	EVP_MD_CTX *ctx = NULL;
 
 	bp = (unsigned char *)pubkey->v;
 	pkey = d2i_PUBKEY(NULL, &bp, pubkey->l);
@@ -1274,30 +1307,40 @@
 		     "failed obtaining public key: %s\n", eay_strerror());
 		goto fail;
 	}
-	if (pkey->type != EVP_PKEY_DSA) {
+	if (EVP_PKEY_id(pkey) != EVP_PKEY_DSA) {
 		plog(PLOG_PROTOERR, PLOGLOC, NULL,
 		     "public key is not for DSS\n");
 		goto fail;
 	}
 
+#if 0
 	md = EVP_dss1();
-	EVP_MD_CTX_init(&ctx);
-	EVP_VerifyInit(&ctx, md);
-	EVP_VerifyUpdate(&ctx, octets->v, octets->l);
-	if (EVP_VerifyFinal(&ctx, (unsigned char *)sig->v, sig->l, pkey) <= 0) {
+#else
+	md = NULL;
+	goto fail;
+#endif
+	ctx = EVP_MD_CTX_new();
+	if (!ctx) {
+		plog(PLOG_INTERR, PLOGLOC, NULL,
+		     "failed to allocate context\n");
+		goto fail;
+	}
+	EVP_VerifyInit(ctx, md);
+	EVP_VerifyUpdate(ctx, octets->v, octets->l);
+	if (EVP_VerifyFinal(ctx, (unsigned char *)sig->v, sig->l, pkey) <= 0) {
 		plog(PLOG_PROTOERR, PLOGLOC, NULL,
 		     "DSS verify failed: %s\n", eay_strerror());
-		EVP_MD_CTX_cleanup(&ctx);
 		goto fail;
 	}
-	EVP_MD_CTX_cleanup(&ctx);
-
+	EVP_MD_CTX_free(ctx);
 	EVP_PKEY_free(pkey);
 	return 0;
 
       fail:
 	if (pkey)
 		EVP_PKEY_free(pkey);
+	if (ctx)
+		EVP_MD_CTX_free(ctx);
 	return -1;
 }
 
@@ -1345,7 +1388,7 @@
 evp_encrypt(const EVP_CIPHER *ciph, rc_vchar_t *data, rc_vchar_t *key, rc_vchar_t *iv)
 {
 	rc_vchar_t *res;
-	EVP_CIPHER_CTX ctx;
+	EVP_CIPHER_CTX *ctx = NULL;
 	int outl;
 
 	if (!iv || iv->l < (size_t)EVP_CIPHER_block_size(ciph))
@@ -1355,12 +1398,17 @@
 	if ((res = rc_vmalloc(data->l)) == NULL)
 		return NULL;
 
-	EVP_CIPHER_CTX_init(&ctx);
-	if (!EVP_EncryptInit(&ctx, ciph, (unsigned char *)key->v, (unsigned char *)iv->v))
+	ctx = EVP_CIPHER_CTX_new();
+	if (!ctx) {
+		plog(PLOG_INTERR, PLOGLOC, NULL,
+		     "failed to allocate context\n");
+		goto fail;
+	}
+	if (!EVP_EncryptInit(ctx, ciph, (unsigned char *)key->v, (unsigned char *)iv->v))
 		goto fail;
-	if (!EVP_CIPHER_CTX_set_padding(&ctx, 0))
+	if (!EVP_CIPHER_CTX_set_padding(ctx, 0))
 		goto fail;
-	if (!EVP_EncryptUpdate(&ctx, (unsigned char *)res->v, &outl, (unsigned char *)data->v,
+	if (!EVP_EncryptUpdate(ctx, (unsigned char *)res->v, &outl, (unsigned char *)data->v,
 	     data->l))
 		goto fail;
 	if ((size_t)outl != data->l) {
@@ -1369,16 +1417,17 @@
 		     outl, (unsigned long)data->l);
 		goto fail;
 	}
-	if (!EVP_EncryptFinal(&ctx, NULL, &outl))
+	if (!EVP_EncryptFinal(ctx, NULL, &outl))
 		goto fail;
 
-	EVP_CIPHER_CTX_cleanup(&ctx);
+	EVP_CIPHER_CTX_free(ctx);
 	return res;
 
       fail:
 	if (res)
 		rc_vfree(res);
-	EVP_CIPHER_CTX_cleanup(&ctx);
+	if (ctx)
+		EVP_CIPHER_CTX_free(ctx);
 	return NULL;
 }
 
@@ -1386,7 +1435,7 @@
 evp_decrypt(const EVP_CIPHER *ciph, rc_vchar_t *data, rc_vchar_t *key, rc_vchar_t *iv)
 {
 	rc_vchar_t *res;
-	EVP_CIPHER_CTX ctx;
+	EVP_CIPHER_CTX *ctx = NULL;
 	int outl;
 
 	if (!iv || iv->l < (size_t)EVP_CIPHER_block_size(ciph))
@@ -1396,12 +1445,17 @@
 	if ((res = rc_vmalloc(data->l)) == NULL)
 		return NULL;
 
-	EVP_CIPHER_CTX_init(&ctx);
-	if (!EVP_DecryptInit(&ctx, ciph, (unsigned char *)key->v, (unsigned char *)iv->v))
+	ctx = EVP_CIPHER_CTX_new();
+	if (!ctx) {
+		plog(PLOG_INTERR, PLOGLOC, NULL,
+		     "failed to allocate context\n");
+		goto fail;
+	}
+	if (!EVP_DecryptInit(ctx, ciph, (unsigned char *)key->v, (unsigned char *)iv->v))
 		goto fail;
-	if (!EVP_CIPHER_CTX_set_padding(&ctx, 0))
+	if (!EVP_CIPHER_CTX_set_padding(ctx, 0))
 		goto fail;
-	if (!EVP_DecryptUpdate(&ctx, (unsigned char *)res->v, &outl, (unsigned char *)data->v,
+	if (!EVP_DecryptUpdate(ctx, (unsigned char *)res->v, &outl, (unsigned char *)data->v,
 	     data->l))
 		goto fail;
 	if ((size_t)outl != data->l) {
@@ -1410,15 +1464,16 @@
 		     outl, (unsigned long)data->l);
 		goto fail;
 	}
-	if (!EVP_DecryptFinal(&ctx, NULL, &outl))
+	if (!EVP_DecryptFinal(ctx, NULL, &outl))
 		goto fail;
-	EVP_CIPHER_CTX_cleanup(&ctx);
+	EVP_CIPHER_CTX_free(ctx);
 	return res;
 
       fail:
 	if (res)
 		rc_vfree(res);
-	EVP_CIPHER_CTX_cleanup(&ctx);
+	if (ctx)
+		EVP_CIPHER_CTX_cleanup(ctx);
 	return NULL;
 }
 
@@ -1963,45 +2018,55 @@
 	 * are used as the nonce value in the counter block.
 	 */
 
-	uint8_t *nonce;
-	union {
-		uint8_t bytes[AES_BLOCK_SIZE];
-		struct aes_ctrblk {
-			uint32_t nonce;
-			uint8_t iv[AES_CTR_IV_SIZE];
-			uint32_t block_counter;
-		} fields;
-	} ctrblk;
-	uint8_t ecount_buf[AES_BLOCK_SIZE];
-	AES_KEY k;
-	unsigned int num;
-	rc_vchar_t *resultbuf;
+	int len;
+	rc_vchar_t *resultbuf = NULL;
+	EVP_CIPHER_CTX *ctx = NULL;
 
 	/*
 	 * if (data->l > AES_BLOCK_SIZE * UINT32_MAX) return 0;
 	 */
 
-	if (iv->l != AES_CTR_IV_SIZE)
-		return 0;
-	nonce = (unsigned char *)key->v + key->l - AES_CTR_NONCE_SIZE;
-	if (AES_set_encrypt_key((unsigned char *)key->v,
-				(key->l - AES_CTR_NONCE_SIZE) << 3, &k) < 0)
+	if (iv->l != AES_CTR_IV_SIZE) {
+		plog(PLOG_INTERR, PLOGLOC, 0, "bad iv size");
 		return 0;
+	}
+
+	ctx = EVP_CIPHER_CTX_new();
+	if (ctx == NULL) {
+		plog(PLOG_INTERR, PLOGLOC, 0, "EVP_CIPHER_CTX_new failed");
+		goto fail;
+	}
+
+	if (!EVP_EncryptInit_ex(ctx, EVP_aes_128_ctr(), NULL, (unsigned char *)key->v, (unsigned char *)iv->v)) {
+		plog(PLOG_INTERR, PLOGLOC, 0, "EVP_EncryptInit_ex failed");
+		goto fail;
+	}
 
 	resultbuf = rc_vmalloc(data->l);
-	if (!resultbuf)
-		return 0;
+	if (!resultbuf) {
+		plog(PLOG_INTERR, PLOGLOC, 0, "allocate resultbuf failed");
+		goto fail;
+	}
 
-	memcpy(&ctrblk.fields.nonce, nonce, AES_CTR_NONCE_SIZE);
-	memcpy(&ctrblk.fields.iv[0], iv->v, AES_CTR_IV_SIZE);
-	ctrblk.fields.block_counter = htonl(1);
-
-	num = 0;
-	AES_ctr128_encrypt((unsigned char *)data->v,
-			   (unsigned char *)resultbuf->v, data->l, &k,
-			   &ctrblk.bytes[0], ecount_buf, &num);
+	if (!EVP_EncryptUpdate(ctx, (unsigned char *)resultbuf->v, &len, (unsigned char *)data->v, data->l)) {
+		plog(PLOG_INTERR, PLOGLOC, 0, "EVP_EncryptUpdate failed");
+		goto fail;
+	}
 
+	if (!EVP_EncryptFinal_ex(ctx, (unsigned char *)resultbuf->v + len, &len)) {
+		plog(PLOG_INTERR, PLOGLOC, 0, "EVP_EncryptFinal_ex failed");
+		goto fail;
+	}
+
+	EVP_CIPHER_CTX_free(ctx);
 	return resultbuf;
+
+fail:
+	EVP_CIPHER_CTX_free(ctx);
+	if (resultbuf)
+		rc_free(resultbuf);
+
+	return NULL;
 }
 
 /* for ipsec part */
@@ -2038,14 +2103,9 @@
 static caddr_t
 eay_hmac_init(rc_vchar_t *key, const EVP_MD *md)
 {
-	HMAC_CTX *c = racoon_malloc(sizeof(*c));
+	HMAC_CTX *c = HMAC_CTX_new();
 
-#if OPENSSL_VERSION_NUMBER < 0x0090700fL
-	HMAC_Init(c, key->v, key->l, md);
-#else
-	HMAC_CTX_init(c);
 	HMAC_Init_ex(c, key->v, key->l, md, NULL);
-#endif
 
 	return (caddr_t)c;
 }
@@ -2053,12 +2113,7 @@
 void
 eay_hmac_dispose(HMAC_CTX *c)
 {
-#if OPENSSL_VERSION_NUMBER < 0x0090700fL
-	HMAC_cleanup(c);
-#else
-	HMAC_CTX_cleanup(c);
-#endif
-	(void)racoon_free(c);
+	HMAC_CTX_free(c);
 }
 
 #ifdef WITH_SHA2
@@ -2972,15 +3027,16 @@
 eay_random_uint32(void)
 {
 	uint32_t value;
-	(void)RAND_pseudo_bytes((uint8_t *)&value, sizeof(value));
+	(void)RAND_bytes((uint8_t *)&value, sizeof(value));
 	return value;
 }
 
 /* DH */
 int
-eay_dh_generate(rc_vchar_t *prime, uint32_t g, unsigned int publen, rc_vchar_t **pub, rc_vchar_t **priv)
+eay_dh_generate(rc_vchar_t *prime, uint32_t gg, unsigned int publen, rc_vchar_t **pub, rc_vchar_t **priv)
 {
-	BIGNUM *p = NULL;
+	BIGNUM *p = NULL, *g = NULL;
+	const BIGNUM *pub_key, *priv_key;
 	DH *dh = NULL;
 	int error = -1;
 
@@ -2991,25 +3047,27 @@
 
 	if ((dh = DH_new()) == NULL)
 		goto end;
-	dh->p = p;
-	p = NULL;		/* p is now part of dh structure */
-	dh->g = NULL;
-	if ((dh->g = BN_new()) == NULL)
+	if ((g = BN_new()) == NULL)
 		goto end;
-	if (!BN_set_word(dh->g, g))
+	if (!BN_set_word(g, gg))
 		goto end;
 
+	if (!DH_set0_pqg(dh, p, NULL, g))
+		goto end;
+	g = p = NULL;
+
 	if (publen != 0)
-		dh->length = publen;
+		DH_set_length(dh, publen);
 
 	/* generate public and private number */
 	if (!DH_generate_key(dh))
 		goto end;
 
+	DH_get0_key(dh, &pub_key, &priv_key);
 	/* copy results to buffers */
-	if (eay_bn2v(pub, dh->pub_key) < 0)
+	if (eay_bn2v(pub, pub_key) < 0)
 		goto end;
-	if (eay_bn2v(priv, dh->priv_key) < 0) {
+	if (eay_bn2v(priv, priv_key) < 0) {
 		rc_vfree(*pub);
 		goto end;
 	}
@@ -3019,44 +3077,57 @@
       end:
 	if (dh != NULL)
 		DH_free(dh);
-	if (p != 0)
+	if (p != NULL)
 		BN_free(p);
+	if (g != NULL)
+		BN_free(g);
 	return (error);
 }
 
 int 
-eay_dh_compute (rc_vchar_t *prime, uint32_t g, rc_vchar_t *pub, 
+eay_dh_compute (rc_vchar_t *prime, uint32_t gg, rc_vchar_t *pub, 
 		rc_vchar_t *priv, rc_vchar_t *pub2, rc_vchar_t **key)
 {
-	BIGNUM *dh_pub = NULL;
+	BIGNUM *dh_pub = NULL, *p = NULL, *g = NULL,
+	    *pub_key = NULL, *priv_key = NULL;
 	DH *dh = NULL;
 	int l;
 	unsigned char *v = NULL;
 	int error = -1;
 
-	/* make public number to compute */
-	if (eay_v2bn(&dh_pub, pub2) < 0)
-		goto end;
-
 	/* make DH structure */
 	if ((dh = DH_new()) == NULL)
 		goto end;
-	if (eay_v2bn(&dh->p, prime) < 0)
+
+	if (eay_v2bn(&p, prime) < 0)
+		goto end;
+	if ((g = BN_new()) == NULL)
 		goto end;
-	if (eay_v2bn(&dh->pub_key, pub) < 0)
+	if (!BN_set_word(g, gg))
 		goto end;
-	if (eay_v2bn(&dh->priv_key, priv) < 0)
+	if (!DH_set0_pqg(dh, p, NULL, g))
 		goto end;
-	dh->length = pub2->l * 8;
+	p = NULL;
+	g = NULL;
 
-	dh->g = NULL;
-	if ((dh->g = BN_new()) == NULL)
+	if (eay_v2bn(&pub_key, pub) < 0)
 		goto end;
-	if (!BN_set_word(dh->g, g))
+	if (eay_v2bn(&priv_key, priv) < 0)
 		goto end;
+	if (!DH_set0_key(dh, pub_key, priv_key))
+		goto end;
+	pub_key = NULL;
+	priv_key = NULL;
+
+	DH_set_length(dh, pub2->l * 8);
 
 	if ((v = racoon_calloc(prime->l, sizeof(unsigned char))) == NULL)
 		goto end;
+
+	/* make public number to compute */
+	if (eay_v2bn(&dh_pub, pub2) < 0)
+		goto end;
+
 	if ((l = DH_compute_key(v, dh_pub, dh)) == -1)
 		goto end;
 	memcpy((*key)->v + (prime->l - l), v, l);
@@ -3066,6 +3137,14 @@
       end:
 	if (dh_pub != NULL)
 		BN_free(dh_pub);
+	if (pub_key != NULL)
+		BN_free(pub_key);
+	if (priv_key != NULL)
+		BN_free(priv_key);
+	if (p != NULL)
+		BN_free(p);
+	if (g != NULL)
+		BN_free(g);
 	if (dh != NULL)
 		DH_free(dh);
 	if (v != NULL)
@@ -3083,9 +3162,9 @@
 }
 
 int
-eay_bn2v(rc_vchar_t **var, BIGNUM *bn)
+eay_bn2v(rc_vchar_t **var, const BIGNUM *bn)
 {
-	*var = rc_vmalloc(bn->top * BN_BYTES);
+	*var = rc_vmalloc(BN_num_bytes(bn));
 	if (*var == NULL)
 		return (-1);
 
