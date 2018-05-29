$NetBSD: patch-spmd_shell.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Fix for OpenSSL 1.1

--- spmd/shell.c	2008-01-25 01:13:01.000000000 -0500
+++ spmd/shell.c	2018-05-28 13:54:05.166565802 -0400
@@ -655,7 +655,7 @@
 	char *p;
 	int i;
 	const EVP_MD *m;
-	EVP_MD_CTX ctx;
+	EVP_MD_CTX *ctx;
 	unsigned char digest[EVP_MAX_MD_SIZE];
 	unsigned int digest_len;
 
@@ -693,27 +693,27 @@
 		}
 	}
 #endif
-	EVP_MD_CTX_init(&ctx);
-	if (!EVP_DigestInit_ex(&ctx, m, SPMD_EVP_ENGINE)) {
-		SPMD_PLOG(SPMD_L_INTERR, "Failed to initilize Message Digest function");
+	ctx = EVP_MD_CTX_new();
+	if (ctx == NULL) {
+		SPMD_PLOG(SPMD_L_INTERR, "Failed to allocate Message Digest context");
 		goto fin;
 	}
-	if (!EVP_DigestUpdate(&ctx, seed, seed_len)) {
+	if (!EVP_DigestInit_ex(ctx, m, SPMD_EVP_ENGINE)) {
+		SPMD_PLOG(SPMD_L_INTERR, "Failed to initialize Message Digest function");
+		goto fin;
+	}
+	if (!EVP_DigestUpdate(ctx, seed, seed_len)) {
 		SPMD_PLOG(SPMD_L_INTERR, "Failed to hash Seed");
 		goto fin;
 	}
-	if (!EVP_DigestFinal_ex(&ctx, digest, &digest_len)) {
+	if (!EVP_DigestFinal_ex(ctx, digest, &digest_len)) {
 		SPMD_PLOG(SPMD_L_INTERR, "Failed to get Message Digest value");
 		goto fin;
 	}
-	if (digest_len != EVP_MD_CTX_size(&ctx)) {
+	if (digest_len != EVP_MD_CTX_size(ctx)) {
 		SPMD_PLOG(SPMD_L_INTERR, "Message Digest length is not enough");
 		goto fin;
 	}
-	if (!EVP_MD_CTX_cleanup(&ctx)) {
-		SPMD_PLOG(SPMD_L_INTERR, "Failed to cleanup Message Digest context");
-		goto fin;
-	}
 
 	challenge_len = digest_len*2+1;
 	challenge = spmd_calloc(challenge_len);
@@ -729,6 +729,7 @@
         }
 
 fin:
+	EVP_MD_CTX_free(ctx);
 	spmd_free(seed);
 just_fin:
 	return challenge;
