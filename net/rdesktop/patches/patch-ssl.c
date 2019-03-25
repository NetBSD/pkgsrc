$NetBSD: patch-ssl.c,v 1.1 2019/03/25 19:56:08 markd Exp $

Workaround for key caching in OpenSSL > 1.1.0 ( fixes #118)
commit bba4cd2cf0269ec933cb2ccf92743bbcebf3c2da

--- ssl.c.orig	2019-01-02 13:50:34.000000000 +0000
+++ ssl.c
@@ -143,6 +143,11 @@ rdssl_cert_to_rkey(RDSSL_CERT * cert, ui
 	int nid;
 	int ret;
 
+	const unsigned char *p;
+	int pklen;
+
+	RSA *rsa = NULL;
+
 	/* By some reason, Microsoft sets the OID of the Public RSA key to
 	   the oid for "MD5 with RSA Encryption" instead of "RSA Encryption"
 
@@ -170,9 +175,28 @@ rdssl_cert_to_rkey(RDSSL_CERT * cert, ui
 
 	if ((nid == NID_md5WithRSAEncryption) || (nid == NID_shaWithRSAEncryption))
 	{
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 		DEBUG_RDP5(("Re-setting algorithm type to RSA in server certificate\n"));
 		X509_PUBKEY_set0_param(key, OBJ_nid2obj(NID_rsaEncryption),
 				       0, NULL, NULL, 0);
+#else
+		if (!X509_PUBKEY_get0_param(NULL, &p, &pklen, NULL, key)) {
+			error("failed to get algorithm used for public key");
+
+			return NULL;
+		}
+
+		if (!(rsa = d2i_RSAPublicKey(NULL, &p, pklen))) {
+			error("failed to extract public key from certificate");
+
+			return NULL;
+		}
+
+		lkey = RSAPublicKey_dup(rsa);
+		*key_len = RSA_size(lkey);
+		return lkey;
+#endif
+
 	}
 	epk = X509_get_pubkey(cert);
 	if (NULL == epk)
@@ -229,7 +255,7 @@ rdssl_rkey_get_exp_mod(RDSSL_RKEY * rkey
 	e = rkey->e;
 	n = rkey->n;
 #else
-	RSA_get0_key(rkey, &e, &n, NULL);
+	RSA_get0_key(rkey, &n, &e, NULL);
 #endif
 
 	if ((BN_num_bytes(e) > (int) max_exp_len) ||
