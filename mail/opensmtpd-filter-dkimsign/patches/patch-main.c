$NetBSD: patch-main.c,v 1.1 2023/09/21 12:22:52 vins Exp $

Address signedness mismatch warnings.

--- main.c.orig	2022-01-27 21:56:05.000000000 +0000
+++ main.c
@@ -594,6 +594,7 @@ dkim_sign(struct osmtpd_ctx *ctx)
 	ssize_t i;
 	size_t linelen = 0;
 	char *tmp, *tmp2;
+	unsigned char *utmp;
 	unsigned int digestsz;
 
 	if (addtime || addexpire)
@@ -717,18 +718,18 @@ dkim_sign(struct osmtpd_ctx *ctx)
 		}
 #endif
 	}
-	if ((tmp = malloc(linelen)) == NULL) {
+	if ((utmp = malloc(linelen)) == NULL) {
 		dkim_err(message, "Can't allocate space for signature");
 		goto fail;
 	}
 	if (!sephash) {
-		if (EVP_DigestSignFinal(message->dctx, tmp, &linelen) != 1) {
+		if (EVP_DigestSignFinal(message->dctx, utmp, &linelen) != 1) {
 			dkim_errx(message, "Failed to finalize signature");
 			goto fail;
 		}
 #ifdef HAVE_ED25519
 	} else {
-		if (EVP_DigestSign(message->dctx, tmp, &linelen, bdigest,
+		if (EVP_DigestSign(message->dctx, utmp, &linelen, bdigest,
 		    digestsz) != 1) {
 			dkim_errx(message, "Failed to finalize signature");
 			goto fail;
@@ -739,8 +740,8 @@ dkim_sign(struct osmtpd_ctx *ctx)
 		dkim_err(message, "Can't create DKIM signature");
 		goto fail;
 	}
-	EVP_EncodeBlock(b, tmp, linelen);
-	free(tmp);
+	EVP_EncodeBlock(b, utmp, linelen);
+	free(utmp);
 	dkim_signature_printf(message, "%s\r\n", b);
 	free(b);
 	dkim_signature_normalize(message);
