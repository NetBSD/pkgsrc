$NetBSD: patch-libsecret_secret-file-collection.c,v 1.1 2020/01/21 14:04:16 nia Exp $

Avoid conflicting with encrypt(3) on NetBSD

--- libsecret/secret-file-collection.c.orig	2019-10-14 15:15:45.000000000 +0000
+++ libsecret/secret-file-collection.c
@@ -164,7 +164,7 @@ decrypt (SecretFileCollection *self,
 }
 
 static gboolean
-encrypt (SecretFileCollection *self,
+encrypt_ (SecretFileCollection *self,
 	 guint8 *data,
 	 gsize n_data)
 {
@@ -584,7 +584,7 @@ secret_file_collection_replace (SecretFi
 	g_variant_store (serialized_item, data);
 	g_variant_unref (serialized_item);
 	memset (data + n_data, n_padded - n_data, n_padded - n_data);
-	if (!encrypt (self, data, n_padded)) {
+	if (!encrypt_ (self, data, n_padded)) {
 		egg_secure_free (data);
 		g_set_error (error,
 			     SECRET_ERROR,
