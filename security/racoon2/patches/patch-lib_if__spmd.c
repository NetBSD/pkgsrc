$NetBSD: patch-lib_if__spmd.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Adjust for OpenSSL v1.1

--- lib/if_spmd.c.orig	2008-03-27 06:05:42.000000000 -0400
+++ lib/if_spmd.c	2018-05-28 13:31:19.367838157 -0400
@@ -1100,7 +1100,7 @@
 spmd_if_login_response(struct spmd_cid *pci)
 {
 	unsigned char md[EVP_MAX_MD_SIZE];
-	EVP_MD_CTX ctx;
+	EVP_MD_CTX *ctx;
 	size_t hash_len;
 	unsigned int md_len;
 	int error, used, i;
@@ -1108,28 +1108,33 @@
 
 	error = -1;
 
-	EVP_MD_CTX_init(&ctx);
-	if (!EVP_DigestInit_ex(&ctx, SPMD_DIGEST_ALG, SPMD_EVP_ENGINE)) {
+	ctx = EVP_MD_CTX_new();
+	if (ctx == NULL) {
+		plog(PLOG_INTERR, PLOGLOC, NULL,
+		    "failed to allocate Message Digest context\n");
+		goto fail_early;
+	}
+	if (!EVP_DigestInit_ex(ctx, SPMD_DIGEST_ALG, SPMD_EVP_ENGINE)) {
 		plog(PLOG_INTERR, PLOGLOC, NULL,
 		    "failed to initilize Message Digest function\n");
 		goto fail_early;
 	}
-	if (!EVP_DigestUpdate(&ctx, pci->challenge, strlen(pci->challenge))) {
+	if (!EVP_DigestUpdate(ctx, pci->challenge, strlen(pci->challenge))) {
 		plog(PLOG_INTERR, PLOGLOC, NULL,
 		    "failed to hash Challenge\n");
 		goto fail;
 	}
-	if (!EVP_DigestUpdate(&ctx, pci->password, strlen(pci->password))) {
+	if (!EVP_DigestUpdate(ctx, pci->password, strlen(pci->password))) {
 		plog(PLOG_INTERR, PLOGLOC, NULL,
 		    "failed to hash Password\n");
 		goto fail;
 	}
-	if (sizeof(md) < EVP_MD_CTX_size(&ctx)) {
+	if (sizeof(md) < EVP_MD_CTX_size(ctx)) {
 		plog(PLOG_INTERR, PLOGLOC, NULL,
 		    "Message Digest buffer is not enough\n");
 		goto fail;
 	}
-	if (!EVP_DigestFinal_ex(&ctx, md, &md_len)) {
+	if (!EVP_DigestFinal_ex(ctx, md, &md_len)) {
 		plog(PLOG_INTERR, PLOGLOC, NULL,
 		    "failed to get Message Digest value\n");
 		goto fail;
@@ -1154,11 +1159,7 @@
 
 	error = 0;
 fail:
-	if (!EVP_MD_CTX_cleanup(&ctx)) {
-		plog(PLOG_INTERR, PLOGLOC, NULL,
-		    "failed to cleanup Message Digest context\n");
-		error = -1;		/* error again */
-	}
+	EVP_MD_CTX_free(ctx);
 fail_early:
 	return error;
 }
