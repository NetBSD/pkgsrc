$NetBSD: patch-mysys__ssl_my__aes__openssl.cc,v 1.1.2.2 2019/09/08 16:55:18 bsiegert Exp $

* Allow build with OpenSSL 1.1.

--- mysys_ssl/my_aes_openssl.cc.orig	2019-06-10 10:25:32.000000000 +0000
+++ mysys_ssl/my_aes_openssl.cc
@@ -108,33 +108,46 @@ int my_aes_encrypt(const unsigned char *
                    const unsigned char *key, uint32 key_length,
                    enum my_aes_opmode mode, const unsigned char *iv)
 {
-  EVP_CIPHER_CTX ctx;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CIPHER_CTX stack_ctx;
+  EVP_CIPHER_CTX *ctx= &stack_ctx;
+#else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+  EVP_CIPHER_CTX *ctx= EVP_CIPHER_CTX_new();
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   const EVP_CIPHER *cipher= aes_evp_type(mode);
   int u_len, f_len;
   /* The real key to be used for encryption */
   unsigned char rkey[MAX_AES_KEY_LENGTH / 8];
   my_aes_create_key(key, key_length, rkey, mode);
 
-  if (!cipher || (EVP_CIPHER_iv_length(cipher) > 0 && !iv))
+  if (!ctx || !cipher || (EVP_CIPHER_iv_length(cipher) > 0 && !iv))
     return MY_AES_BAD_DATA;
 
-  if (!EVP_EncryptInit(&ctx, cipher, rkey, iv))
+  if (!EVP_EncryptInit(ctx, cipher, rkey, iv))
     goto aes_error;                             /* Error */
-  if (!EVP_CIPHER_CTX_set_padding(&ctx, 1))
+  if (!EVP_CIPHER_CTX_set_padding(ctx, 1))
     goto aes_error;                             /* Error */
-  if (!EVP_EncryptUpdate(&ctx, dest, &u_len, source, source_length))
+  if (!EVP_EncryptUpdate(ctx, dest, &u_len, source, source_length))
     goto aes_error;                             /* Error */
 
-  if (!EVP_EncryptFinal(&ctx, dest + u_len, &f_len))
+  if (!EVP_EncryptFinal(ctx, dest + u_len, &f_len))
     goto aes_error;                             /* Error */
 
-  EVP_CIPHER_CTX_cleanup(&ctx);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CIPHER_CTX_cleanup(ctx);
+#else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+  EVP_CIPHER_CTX_free(ctx);
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   return u_len + f_len;
 
 aes_error:
   /* need to explicitly clean up the error if we want to ignore it */
   ERR_clear_error();
-  EVP_CIPHER_CTX_cleanup(&ctx);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    EVP_CIPHER_CTX_cleanup(ctx);
+#else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+    EVP_CIPHER_CTX_free(ctx);
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   return MY_AES_BAD_DATA;
 }
 
@@ -145,7 +158,12 @@ int my_aes_decrypt(const unsigned char *
                    enum my_aes_opmode mode, const unsigned char *iv)
 {
 
-  EVP_CIPHER_CTX ctx;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CIPHER_CTX stack_ctx;
+  EVP_CIPHER_CTX *ctx= &stack_ctx;
+#else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+  EVP_CIPHER_CTX *ctx= EVP_CIPHER_CTX_new();
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   const EVP_CIPHER *cipher= aes_evp_type(mode);
   int u_len, f_len;
 
@@ -153,27 +171,33 @@ int my_aes_decrypt(const unsigned char *
   unsigned char rkey[MAX_AES_KEY_LENGTH / 8];
 
   my_aes_create_key(key, key_length, rkey, mode);
-  if (!cipher || (EVP_CIPHER_iv_length(cipher) > 0 && !iv))
+  if (!ctx || !cipher || (EVP_CIPHER_iv_length(cipher) > 0 && !iv))
     return MY_AES_BAD_DATA;
 
-  EVP_CIPHER_CTX_init(&ctx);
-
-  if (!EVP_DecryptInit(&ctx, aes_evp_type(mode), rkey, iv))
+  if (!EVP_DecryptInit(ctx, aes_evp_type(mode), rkey, iv))
     goto aes_error;                             /* Error */
-  if (!EVP_CIPHER_CTX_set_padding(&ctx, 1))
+  if (!EVP_CIPHER_CTX_set_padding(ctx, 1))
     goto aes_error;                             /* Error */
-  if (!EVP_DecryptUpdate(&ctx, dest, &u_len, source, source_length))
+  if (!EVP_DecryptUpdate(ctx, dest, &u_len, source, source_length))
     goto aes_error;                             /* Error */
-  if (!EVP_DecryptFinal_ex(&ctx, dest + u_len, &f_len))
+  if (!EVP_DecryptFinal_ex(ctx, dest + u_len, &f_len))
     goto aes_error;                             /* Error */
 
-  EVP_CIPHER_CTX_cleanup(&ctx);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CIPHER_CTX_cleanup(ctx);
+#else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+  EVP_CIPHER_CTX_free(ctx);
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   return u_len + f_len;
 
 aes_error:
   /* need to explicitly clean up the error if we want to ignore it */
   ERR_clear_error();
-  EVP_CIPHER_CTX_cleanup(&ctx);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CIPHER_CTX_cleanup(ctx);
+#else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+  EVP_CIPHER_CTX_free(ctx);
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   return MY_AES_BAD_DATA;
 }
 
