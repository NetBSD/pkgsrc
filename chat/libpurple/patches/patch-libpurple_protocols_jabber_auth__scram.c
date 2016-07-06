$NetBSD: patch-libpurple_protocols_jabber_auth__scram.c,v 1.2 2016/07/06 09:55:39 wiz Exp $

Fix conflict with NetBSD's hmac(3) function.
https://developer.pidgin.im/ticket/17061

--- libpurple/protocols/jabber/auth_scram.c.orig	2015-12-31 23:19:40.000000000 +0000
+++ libpurple/protocols/jabber/auth_scram.c
@@ -134,7 +134,7 @@ guchar *jabber_scram_hi(const JabberScra
  * Needless to say, these are fragile.
  */
 static void
-hmac(const JabberScramHash *hash, guchar *out, const guchar *key, const gchar *str)
+purple_hmac(const JabberScramHash *hash, guchar *out, const guchar *key, const gchar *str)
 {
 	PurpleCipherContext *context;
 
@@ -187,18 +187,18 @@ jabber_scram_calc_proofs(JabberScramData
 		return FALSE;
 
 	/* client_key = HMAC(salted_password, "Client Key") */
-	hmac(data->hash, client_key, salted_password, "Client Key");
+	purple_hmac(data->hash, client_key, salted_password, "Client Key");
 	/* server_key = HMAC(salted_password, "Server Key") */
-	hmac(data->hash, server_key, salted_password, "Server Key");
+	purple_hmac(data->hash, server_key, salted_password, "Server Key");
 	g_free(salted_password);
 
 	/* stored_key = HASH(client_key) */
 	hash(data->hash, stored_key, client_key);
 
 	/* client_signature = HMAC(stored_key, auth_message) */
-	hmac(data->hash, client_signature, stored_key, data->auth_message->str);
+	purple_hmac(data->hash, client_signature, stored_key, data->auth_message->str);
 	/* server_signature = HMAC(server_key, auth_message) */
-	hmac(data->hash, (guchar *)data->server_signature->str, server_key, data->auth_message->str);
+	purple_hmac(data->hash, (guchar *)data->server_signature->str, server_key, data->auth_message->str);
 
 	/* client_proof = client_key XOR client_signature */
 	for (i = 0; i < hash_len; ++i)
