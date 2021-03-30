$NetBSD: patch-rtunes_cipher.c,v 1.1 2021/03/30 12:01:04 nia Exp $

Merge fixes from https://github.com/erincandescent/rtunes

--- rtunes/cipher.c.orig	2009-06-27 10:10:32.000000000 +0000
+++ rtunes/cipher.c
@@ -26,10 +26,6 @@
 #include "extern.h"
 #include "proto.h"
 
-#ifdef __linux__
-#include "../libbsd/arc4random.h"
-#endif
-
 /*
  * cipher_ aes_sendsample()
  *	AES encrypt audio sample
@@ -62,7 +58,7 @@ cipher_aes_sendsample(unsigned char *buf
 		len_encrypt = len;
 
 	/* prepend sample header */
-	memcpy(buf + 16, buf, len_encrypt);
+	memmove(buf + 16, buf, len_encrypt);
 	memcpy(buf, header, 16L);
 	/* write sample size into header */
 	j = len_encrypt + 12;
@@ -122,15 +118,11 @@ cipher_rsa_encrypt_aeskey(unsigned char 
 
 	/* initialize RSA public key */
 	key = RSA_new();
-	key->n = BN_bin2bn(n_bin, 256, key->n);;
-	key->e = BN_bin2bn(e_bin, 3, key->e);
-	key->d = NULL;
-	key->p = NULL;
-	key->q = NULL;
-	key->dmp1 = NULL;
-	key->dmq1 = NULL;
-	key->iqmp = NULL;
-
+	RSA_set0_key(key,
+		BN_bin2bn(n_bin, 256, NULL),
+		BN_bin2bn(e_bin, 3,   NULL),
+		NULL);
+	
 	/* RSA encrypt */
 	to = malloc(256);
 	if (RSA_public_encrypt(16, aeskey, to, key, RSA_PKCS1_OAEP_PADDING) < 1)
@@ -150,18 +142,11 @@ cipher_rsa_encrypt_aeskey(unsigned char 
 unsigned char *
 cipher_aes_generate_key(void)
 {
-	int		 i, v;
 	unsigned char	*p = NULL;
-	unsigned char	 key[16];
-
-	for (i = 0; i <= sizeof(key) - sizeof(v); i += sizeof(v)) {
-		v = arc4random();
-		memcpy(&key[i], &v, sizeof(v));
-	}
 
 	p = malloc(16);
-	memcpy(p, key, 16);
-
+	RAND_bytes(p, 16);
+	
 	return (p);
 }
 
