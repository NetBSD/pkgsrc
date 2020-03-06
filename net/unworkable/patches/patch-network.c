$NetBSD: patch-network.c,v 1.1 2020/03/06 13:10:02 nia Exp $

Use DH_set0_pqg() for OpenSSL 1.1 compatibility

https://github.com/niallo/Unworkable/commit/79d717826532850772fb49e0b22ce89087636a40.patch

--- network.c.orig	2008-10-06 17:04:18.000000000 +0000
+++ network.c
@@ -1282,13 +1282,21 @@ DH *
 network_crypto_dh()
 {
 	DH *dhp;
+	BIGNUM *p, *g;
 
 	if ((dhp = DH_new()) == NULL)
 		errx(1, "network_crypto_pubkey: DH_new() failure");
-	if ((dhp->p = BN_bin2bn(mse_P, CRYPTO_INT_LEN, NULL)) == NULL)
+	if ((p = BN_bin2bn(mse_P, CRYPTO_INT_LEN, NULL)) == NULL)
 		errx(1, "network_crypto_pubkey: BN_bin2bn(P) failure");
-	if ((dhp->g = BN_bin2bn(mse_G, CRYPTO_INT_LEN, NULL)) == NULL)
+	if ((g = BN_bin2bn(mse_G, CRYPTO_INT_LEN, NULL)) == NULL)
 		errx(1, "network_crypto_pubkey: BN_bin2bn(G) failure");
+#if defined(OPENSSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x10100000)
+	if (DH_set0_pqg(dhp, p, NULL, g) != 1)
+		errx(1, "DH_set0_pgq failed");
+#else
+	dhp->p = p;
+	dhp->g = g;
+#endif
 	if (DH_generate_key(dhp) == 0)
 		errx(1, "network_crypto_pubkey: DH_generate_key() failure");
 
