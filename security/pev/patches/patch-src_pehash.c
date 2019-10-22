$NetBSD: patch-src_pehash.c,v 1.1 2019/10/22 16:37:05 khorben Exp $

Compatibility fix for OpenSSL 1.1.0

--- src/pehash.c.orig	2017-01-06 22:49:50.000000000 +0000
+++ src/pehash.c
@@ -215,13 +215,22 @@ static void calc_hash(const char *alg_na
 	unsigned char md_value[EVP_MAX_MD_SIZE];
 	unsigned int md_len;
 
-	EVP_MD_CTX md_ctx;
 	// FIXME: Handle errors - Check return values.
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+	EVP_MD_CTX * md_ctx;
+	md_ctx = EVP_MD_CTX_new();
+	EVP_DigestInit_ex(md_ctx, md, NULL);
+	EVP_DigestUpdate(md_ctx, data, size);
+	EVP_DigestFinal_ex(md_ctx, md_value, &md_len);
+	EVP_MD_CTX_free(md_ctx);
+#else
+	EVP_MD_CTX md_ctx;
 	EVP_MD_CTX_init(&md_ctx);
 	EVP_DigestInit_ex(&md_ctx, md, NULL);
 	EVP_DigestUpdate(&md_ctx, data, size);
 	EVP_DigestFinal_ex(&md_ctx, md_value, &md_len);
 	EVP_MD_CTX_cleanup(&md_ctx);
+#endif
 
 	for (unsigned int i=0; i < md_len; i++)
 		sprintf(&output[i * 2], "%02x", md_value[i]);
