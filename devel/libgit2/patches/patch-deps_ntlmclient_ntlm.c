$NetBSD: patch-deps_ntlmclient_ntlm.c,v 1.3 2024/04/05 17:03:59 wiz Exp $

Ensure proper value range for arg to toupper().

--- deps/ntlmclient/ntlm.c.orig	2023-04-12 12:05:25.000000000 +0000
+++ deps/ntlmclient/ntlm.c
@@ -988,9 +988,9 @@ static inline bool generate_lm_hash(
 	keystr2_len = (password_len > 7) ? MIN(14, password_len) - 7 : 0;
 
 	for (i = 0; i < keystr1_len; i++)
-		keystr1[i] = (unsigned char)toupper(password[i]);
+		keystr1[i] = (unsigned char)toupper((unsigned char)password[i]);
 	for (i = 0; i < keystr2_len; i++)
-		keystr2[i] = (unsigned char)toupper(password[i+7]);
+		keystr2[i] = (unsigned char)toupper((unsigned char)password[i+7]);
 
 	/* DES encrypt the LM constant using the password as the key */
 	des_key_from_password(&key1, keystr1, keystr1_len);
