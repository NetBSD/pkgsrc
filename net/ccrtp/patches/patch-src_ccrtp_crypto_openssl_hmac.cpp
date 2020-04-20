$NetBSD: patch-src_ccrtp_crypto_openssl_hmac.cpp,v 1.1 2020/04/20 00:42:30 joerg Exp $

--- src/ccrtp/crypto/openssl/hmac.cpp.orig	2020-04-19 15:28:45.135992336 +0000
+++ src/ccrtp/crypto/openssl/hmac.cpp
@@ -52,23 +52,20 @@ void hmac_sha1( uint8_t* key, int32_t ke
                 const uint8_t* data_chunks[],
                 uint32_t data_chunck_length[],
                 uint8_t* mac, int32_t* mac_length ) {
-    HMAC_CTX ctx;
-    HMAC_CTX_init(&ctx);
-    HMAC_Init_ex(&ctx, key, key_length, EVP_sha1(), NULL);
+    HMAC_CTX *ctx = HMAC_CTX_new();
+    HMAC_Init_ex(ctx, key, key_length, EVP_sha1(), NULL);
     while (*data_chunks) {
-        HMAC_Update(&ctx, *data_chunks, *data_chunck_length);
+        HMAC_Update(ctx, *data_chunks, *data_chunck_length);
         data_chunks ++;
         data_chunck_length ++;
     }
-    HMAC_Final(&ctx, mac, reinterpret_cast<uint32_t*>(mac_length));
-    HMAC_CTX_cleanup(&ctx);
+    HMAC_Final(ctx, mac, reinterpret_cast<uint32_t*>(mac_length));
+    HMAC_CTX_free(ctx);
 }
 
 void* createSha1HmacContext(uint8_t* key, int32_t key_length)
 {
-    HMAC_CTX* ctx = (HMAC_CTX*)malloc(sizeof(HMAC_CTX));
-    
-    HMAC_CTX_init(ctx);
+    HMAC_CTX* ctx = HMAC_CTX_new();
     HMAC_Init_ex(ctx, key, key_length, EVP_sha1(), NULL);
     return ctx;
 }
@@ -100,7 +97,6 @@ void hmacSha1Ctx(void* ctx, const uint8_
 void freeSha1HmacContext(void* ctx)
 {
     if (ctx) {
-        HMAC_CTX_cleanup((HMAC_CTX*)ctx);
-        free(ctx);
+        HMAC_CTX_free((HMAC_CTX*)ctx);
     }
 }
\ No newline at end of file
