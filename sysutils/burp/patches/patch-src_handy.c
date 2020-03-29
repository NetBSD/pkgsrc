$NetBSD: patch-src_handy.c,v 1.1 2020/03/29 01:02:12 joerg Exp $

--- src/handy.c.orig	2020-03-29 00:41:21.500961186 +0000
+++ src/handy.c
@@ -279,18 +279,17 @@ EVP_CIPHER_CTX *enc_setup(int encrypt, c
 	// compilation warnings on Macs.
 	unsigned char enc_iv[]={'[', 'l', 'k', 'd', '.', '$', 'G', 0xa3, '\0'};
 
-	if(!(ctx=(EVP_CIPHER_CTX *)malloc(sizeof(EVP_CIPHER_CTX))))
+	if(!(ctx=EVP_CIPHER_CTX_new()))
 	{
 		log_out_of_memory(__FUNCTION__);
 		return NULL;
 	}
-        memset(ctx, 0, sizeof(EVP_CIPHER_CTX));
 	// Don't set key or IV because we will modify the parameters.
 	EVP_CIPHER_CTX_init(ctx);
 	if(!(EVP_CipherInit_ex(ctx, EVP_bf_cbc(), NULL, NULL, NULL, encrypt)))
 	{
 		logp("EVP_CipherInit_ex failed\n");
-		free(ctx);
+		EVP_CIPHER_CTX_free(ctx);
 		return NULL;
 	}
 	EVP_CIPHER_CTX_set_key_length(ctx, strlen(encryption_password));
@@ -301,7 +300,7 @@ EVP_CIPHER_CTX *enc_setup(int encrypt, c
 		enc_iv, encrypt))
 	{
 		logp("Second EVP_CipherInit_ex failed\n");
-		free(ctx);
+		EVP_CIPHER_CTX_free(ctx);
 		return NULL;
 	}
 	return ctx;
@@ -591,8 +590,7 @@ cleanup:
 
 	if(enc_ctx)
 	{
-		EVP_CIPHER_CTX_cleanup(enc_ctx);
-		free(enc_ctx);
+		EVP_CIPHER_CTX_free(enc_ctx);
 	}
 
 	if(!ret)
