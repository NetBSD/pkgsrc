$NetBSD: patch-util-src_hashes.c,v 1.2 2017/11/23 22:06:15 fhajny Exp $

Avoid conflict with NetBSD's hmac.

--- util-src/hashes.c.orig	2017-09-28 13:07:47.000000000 +0000
+++ util-src/hashes.c
@@ -74,7 +74,7 @@ struct hash_desc {
 	void *ctx, *ctxo;
 };
 
-static void hmac(struct hash_desc *desc, const char *key, size_t key_len,
+static void myhmac(struct hash_desc *desc, const char *key, size_t key_len,
                  const char *msg, size_t msg_len, unsigned char *result) {
 	union xory {
 		unsigned char bytes[64];
@@ -127,7 +127,7 @@ static int myFunc(lua_State *L) { \
 	desc.digestLength = size; \
 	desc.ctx = &ctx; \
 	desc.ctxo = &ctxo; \
-	hmac(&desc, key, key_len, msg, msg_len, hash); \
+	myhmac(&desc, key, key_len, msg, msg_len, hash); \
 	if (hex_out) { \
 		toHex(hash, size, result); \
 		lua_pushlstring(L, (char*)result, size*2); \
@@ -174,14 +174,14 @@ static int LscramHi(lua_State *L) {
 
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
