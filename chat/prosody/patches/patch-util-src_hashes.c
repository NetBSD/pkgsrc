$NetBSD: patch-util-src_hashes.c,v 1.3 2020/01/23 18:26:15 gdt Exp $

Avoid conflict with NetBSD's hmac.

--- util-src/hashes.c.orig	2019-08-31 14:08:45.000000000 +0000
+++ util-src/hashes.c
@@ -75,7 +75,7 @@ struct hash_desc {
 	void *ctx, *ctxo;
 };
 
-static void hmac(struct hash_desc *desc, const char *key, size_t key_len,
+static void myhmac(struct hash_desc *desc, const char *key, size_t key_len,
                  const char *msg, size_t msg_len, unsigned char *result) {
 	union xory {
 		unsigned char bytes[64];
@@ -168,14 +168,14 @@ static int LscramHi(lua_State *L) {
 
 	memcpy(salt2, salt, salt_len);
 	memcpy(salt2 + salt_len, "\0\0\0\1", 4);
-	hmac(&desc, str, str_len, salt2, salt_len + 4, Ust);
+	myhmac(&desc, str, str_len, salt2, salt_len + 4, Ust);
 	free(salt2);
 
 	memcpy(res.bytes, Ust, sizeof(res));
 
 	for(i = 1; i < iter; i++) {
 		int j;
-		hmac(&desc, str, str_len, (char *)Ust, sizeof(Ust), Und.bytes);
+		myhmac(&desc, str, str_len, (char *)Ust, sizeof(Ust), Und.bytes);
 
 		for(j = 0; j < SHA_DIGEST_LENGTH / 4; j++) {
 			res.quadbytes[j] ^= Und.quadbytes[j];
