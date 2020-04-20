$NetBSD: patch-src_lib_eet__cipher.c,v 1.1 2020/04/20 13:19:38 joerg Exp $

--- src/lib/eet_cipher.c.orig	2013-07-29 14:22:39.000000000 +0000
+++ src/lib/eet_cipher.c
@@ -410,8 +410,18 @@ on_error:
    dh = EVP_PKEY_get1_DH(key->private_key);
    if (dh)
      {
+        BIO *b;
         fprintf(out, "Private key (DH):\n");
-        DHparams_print_fp(out, dh);
+        if ((b=BIO_new(BIO_s_file())) == NULL)
+          {
+            DHerr(DH_F_DHPARAMS_PRINT_FP,ERR_R_BUF_LIB);
+          }
+        else
+          {
+            BIO_set_fp(b, out, BIO_NOCLOSE);
+            DHparams_print(b, dh);
+            BIO_free(b);
+          }
      }
 
    fprintf(out, "Public certificate:\n");
@@ -505,7 +515,7 @@ eet_identity_sign(FILE    *fp,
    gnutls_privkey_t privkey;
 #endif
 # else /* ifdef HAVE_GNUTLS */
-   EVP_MD_CTX md_ctx;
+   EVP_MD_CTX *md_ctx;
    unsigned int sign_len = 0;
    int cert_len = 0;
 # endif /* ifdef HAVE_GNUTLS */
@@ -614,9 +624,16 @@ eet_identity_sign(FILE    *fp,
      }
 
    /* Do the signature. */
-   EVP_SignInit(&md_ctx, EVP_sha1());
-   EVP_SignUpdate(&md_ctx, data, st_buf.st_size);
-   err = EVP_SignFinal(&md_ctx,
+   md_ctx = EVP_MD_CTX_create();
+   if (md_ctx == NULL)
+     {
+        ERR_print_errors_fp(stdout);
+        err = EET_ERROR_SIGNATURE_FAILED;
+        goto on_error;
+     }
+   EVP_SignInit(md_ctx, EVP_sha1());
+   EVP_SignUpdate(md_ctx, data, st_buf.st_size);
+   err = EVP_SignFinal(md_ctx,
                        sign,
                        (unsigned int *)&sign_len,
                        key->private_key);
@@ -626,6 +643,7 @@ eet_identity_sign(FILE    *fp,
         err = EET_ERROR_SIGNATURE_FAILED;
         goto on_error;
      }
+   EVP_MD_CTX_free(md_ctx);
 
    /* Give me the der (binary form for X509). */
    cert_len = i2d_X509(key->certificate, &cert);
@@ -814,7 +832,7 @@ eet_identity_check(const void   *data_ba
    const unsigned char *tmp;
    EVP_PKEY *pkey;
    X509 *x509;
-   EVP_MD_CTX md_ctx;
+   EVP_MD_CTX *md_ctx;
    int err;
 
    /* Strange but d2i_X509 seems to put 0 all over the place. */
@@ -833,9 +851,16 @@ eet_identity_check(const void   *data_ba
      }
 
    /* Verify the signature */
-   EVP_VerifyInit(&md_ctx, EVP_sha1());
-   EVP_VerifyUpdate(&md_ctx, data_base, data_length);
-   err = EVP_VerifyFinal(&md_ctx, sign, sign_len, pkey);
+   md_ctx = EVP_MD_CTX_create();
+   if (!md_ctx)
+     {
+        X509_free(x509);
+        return NULL;
+     }
+   EVP_VerifyInit(md_ctx, EVP_sha1());
+   EVP_VerifyUpdate(md_ctx, data_base, data_length);
+   err = EVP_VerifyFinal(md_ctx, sign, sign_len, pkey);
+   EVP_MD_CTX_free(md_ctx);
 
    X509_free(x509);
    EVP_PKEY_free(pkey);
@@ -971,7 +996,7 @@ eet_cipher(const void   *data,
    gcry_cipher_hd_t cipher;
 # else /* ifdef HAVE_GNUTLS */
    /* Openssl declarations*/
-   EVP_CIPHER_CTX ctx;
+   EVP_CIPHER_CTX *ctx;
    unsigned int *buffer = NULL;
    int tmp_len;
 # endif /* ifdef HAVE_GNUTLS */
@@ -1055,27 +1080,28 @@ eet_cipher(const void   *data,
 
    /* Openssl create the corresponding cipher
       AES with a 256 bit key, Cipher Block Chaining mode */
-   EVP_CIPHER_CTX_init(&ctx);
-   if (!EVP_EncryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL, ik, iv))
+   ctx = EVP_CIPHER_CTX_new();
+   if (!ctx)
      goto on_error;
-
    opened = 1;
+   if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, ik, iv))
+     goto on_error;
 
    memset(iv, 0, sizeof (iv));
    memset(ik, 0, sizeof (ik));
 
    /* Openssl encrypt */
-   if (!EVP_EncryptUpdate(&ctx, (unsigned char *)(ret + 1), &tmp_len,
+   if (!EVP_EncryptUpdate(ctx, (unsigned char *)(ret + 1), &tmp_len,
                           (unsigned char *)buffer,
                           size + sizeof(unsigned int)))
      goto on_error;
 
    /* Openssl close the cipher */
-   if (!EVP_EncryptFinal_ex(&ctx, ((unsigned char *)(ret + 1)) + tmp_len,
+   if (!EVP_EncryptFinal_ex(ctx, ((unsigned char *)(ret + 1)) + tmp_len,
                             &tmp_len))
      goto on_error;
 
-   EVP_CIPHER_CTX_cleanup(&ctx);
+   EVP_CIPHER_CTX_cleanup(ctx);
    free(buffer);
 # endif /* ifdef HAVE_GNUTLS */
 
@@ -1102,7 +1128,7 @@ on_error:
 # else /* ifdef HAVE_GNUTLS */
    /* Openssl error */
    if (opened)
-     EVP_CIPHER_CTX_cleanup(&ctx);
+     EVP_CIPHER_CTX_free(ctx);
 
    free(buffer);
    
@@ -1203,26 +1229,28 @@ eet_decipher(const void   *data,
    gcry_cipher_close(cipher);
 
 # else /* ifdef HAVE_GNUTLS */
-   EVP_CIPHER_CTX ctx;
+   EVP_CIPHER_CTX *ctx;
    int opened = 0;
 
    /* Openssl create the corresponding cipher */
-   EVP_CIPHER_CTX_init(&ctx);
+   ctx = EVP_CIPHER_CTX_new();
+   if (!ctx)
+     goto on_error;
    opened = 1;
 
-   if (!EVP_DecryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL, ik, iv))
+   if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, ik, iv))
      goto on_error;
 
    memset(iv, 0, sizeof (iv));
    memset(ik, 0, sizeof (ik));
 
    /* Openssl decrypt */
-   if (!EVP_DecryptUpdate(&ctx, (unsigned char *)ret, &tmp,
+   if (!EVP_DecryptUpdate(ctx, (unsigned char *)ret, &tmp,
                           (unsigned char *)(over + 1), tmp_len))
      goto on_error;
 
    /* Openssl close the cipher*/
-   EVP_CIPHER_CTX_cleanup(&ctx);
+   EVP_CIPHER_CTX_free(ctx);
 # endif /* ifdef HAVE_GNUTLS */
    /* Get the decrypted data size */
    tmp = *ret;
@@ -1255,7 +1283,7 @@ on_error:
 # ifdef HAVE_GNUTLS
 # else
    if (opened)
-     EVP_CIPHER_CTX_cleanup(&ctx);
+     EVP_CIPHER_CTX_free(ctx);
 
 # endif /* ifdef HAVE_GNUTLS */
    if (result)
@@ -1342,13 +1370,19 @@ eet_pbkdf2_sha1(const char          *key
    int j, k;
 # ifdef HAVE_GNUTLS
 # else
-   HMAC_CTX hctx;
+   HMAC_CTX *hctx;
 # endif /* ifdef HAVE_GNUTLS */
 
    buf = alloca(salt_len + 4);
    if (!buf)
      return 1;
 
+# ifdef HAVE_GNUTLS
+# else
+   hctx = HMAC_CTX_new();
+   if (!hctx)
+     return 1;
+# endif /* ifdef HAVE_GNUTLS */
    for (i = 1; len; len -= tmp_len, p += tmp_len, i++)
      {
         if (len > digest_len)
@@ -1366,10 +1400,10 @@ eet_pbkdf2_sha1(const char          *key
         memcpy(buf + salt_len, tab, 4);
         eet_hmac_sha1(key, key_len, buf, salt_len + 4, digest);
 # else /* ifdef HAVE_GNUTLS */
-        HMAC_Init(&hctx, key, key_len, EVP_sha1());
-        HMAC_Update(&hctx, salt, salt_len);
-        HMAC_Update(&hctx, tab, 4);
-        HMAC_Final(&hctx, digest, NULL);
+        HMAC_Init_ex(hctx, key, key_len, EVP_sha1(), NULL);
+        HMAC_Update(hctx, salt, salt_len);
+        HMAC_Update(hctx, tab, 4);
+        HMAC_Final(hctx, digest, NULL);
 # endif /* ifdef HAVE_GNUTLS */
         memcpy(p, digest, tmp_len);
 
@@ -1384,11 +1418,12 @@ eet_pbkdf2_sha1(const char          *key
                p[k] ^= digest[k];
           }
 
+     }
+	HMAC_CTX_reset(hctx);
 # ifdef HAVE_GNUTLS
 # else
-	HMAC_cleanup(&hctx);
+   HMAC_CTX_free(hctx);
 # endif /* ifdef HAVE_GNUTLS */
-     }
 
    return 0;
 }
