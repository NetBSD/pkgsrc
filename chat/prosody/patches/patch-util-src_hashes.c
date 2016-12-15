$NetBSD: patch-util-src_hashes.c,v 1.1 2016/12/15 23:45:42 joerg Exp $

Avoid conflict with NetBSD's hmac.

--- util-src/hashes.c.orig	2016-12-15 15:20:05.616992510 +0000
+++ util-src/hashes.c
@@ -70,7 +70,7 @@ struct hash_desc {
 	void *ctx, *ctxo;
 };
 
-static void hmac(struct hash_desc *desc, const char *key, size_t key_len,
+static void myhmac(struct hash_desc *desc, const char *key, size_t key_len,
     const char *msg, size_t msg_len, unsigned char *result)
 {
 	union xory {
@@ -124,7 +124,7 @@ static int myFunc(lua_State *L) { \
 	desc.digestLength = size; \
 	desc.ctx = &ctx; \
 	desc.ctxo = &ctxo; \
-	hmac(&desc, key, key_len, msg, msg_len, hash); \
+	myhmac(&desc, key, key_len, msg, msg_len, hash); \
 	if (hex_out) { \
 		toHex(hash, size, result); \
 		lua_pushlstring(L, (char*)result, size*2); \
@@ -168,13 +168,13 @@ static int LscramHi(lua_State *L) {
 		luaL_error(L, "Out of memory in scramHi");
 	memcpy(salt2, salt, salt_len);
 	memcpy(salt2 + salt_len, "\0\0\0\1", 4);
-	hmac(&desc, str, str_len, salt2, salt_len + 4, Ust);
+	myhmac(&desc, str, str_len, salt2, salt_len + 4, Ust);
 	free(salt2);
 
 	memcpy(res.bytes, Ust, sizeof(res));
 	for (i = 1; i < iter; i++) {
 		int j;
-		hmac(&desc, str, str_len, (char*)Ust, sizeof(Ust), Und.bytes);
+		myhmac(&desc, str, str_len, (char*)Ust, sizeof(Ust), Und.bytes);
 		for (j = 0; j < SHA_DIGEST_LENGTH/4; j++)
 			res.quadbytes[j] ^= Und.quadbytes[j];
 		memcpy(Ust, Und.bytes, sizeof(Ust));
