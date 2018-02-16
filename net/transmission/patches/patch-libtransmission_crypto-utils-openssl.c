$NetBSD: patch-libtransmission_crypto-utils-openssl.c,v 1.1 2018/02/16 12:33:37 wiz Exp $

Fix build with openssl-1.1.
From upstream via Peter Hjalmarsson via
https://bugzilla.redhat.com/show_bug.cgi?id=1468077

--- libtransmission/crypto-utils-openssl.c.orig	2015-12-29 00:47:32.449150371 +0000
+++ libtransmission/crypto-utils-openssl.c
@@ -230,6 +230,61 @@ tr_rc4_process (tr_rc4_ctx_t   handle,
 ****
 ***/
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000
+static inline int
+DH_set0_pqg (DH     * dh,
+             BIGNUM * p,
+             BIGNUM * q,
+             BIGNUM * g)
+{
+  /* If the fields p and g in d are NULL, the corresponding input
+   * parameters MUST be non-NULL.  q may remain NULL.
+   */
+  if ((dh->p == NULL && p == NULL)
+      || (dh->g == NULL && g == NULL))
+    return 0;
+
+  if (p != NULL) {
+    BN_free (dh->p);
+    dh->p = p;
+  }
+  if (q != NULL) {
+    BN_free (dh->q);
+    dh->q = q;
+  }
+  if (g != NULL) {
+    BN_free (dh->g);
+    dh->g = g;
+  }
+
+  if (q != NULL) {
+    dh->length = BN_num_bits (q);
+  }
+
+  return 1;
+}
+
+static inline int
+DH_set_length (DH   * dh,
+               long   length)
+{
+	dh->length = length;
+	return 1;
+}
+
+static inline void
+DH_get0_key(const DH      * dh,
+            const BIGNUM ** pub_key,
+            const BIGNUM ** priv_key)
+{
+  if (pub_key != NULL)
+    *pub_key = dh->pub_key;
+  if (priv_key != NULL)
+    *priv_key = dh->priv_key;
+}
+
+#endif
+
 tr_dh_ctx_t
 tr_dh_new (const uint8_t * prime_num,
            size_t          prime_num_length,
@@ -237,13 +292,19 @@ tr_dh_new (const uint8_t * prime_num,
            size_t          generator_num_length)
 {
   DH * handle = DH_new ();
+  BIGNUM * p, * g;
 
   assert (prime_num != NULL);
   assert (generator_num != NULL);
+  p = BN_bin2bn (prime_num, prime_num_length, NULL);
+  g = BN_bin2bn (generator_num, generator_num_length, NULL);
 
-  if (!check_pointer (handle->p = BN_bin2bn (prime_num, prime_num_length, NULL)) ||
-      !check_pointer (handle->g = BN_bin2bn (generator_num, generator_num_length, NULL)))
+  if (!check_pointer (p) ||
+      !check_pointer (g) ||
+      !DH_set0_pqg (handle, p, NULL, g))
     {
+      BN_free (p);
+      BN_free (g);
       DH_free (handle);
       handle = NULL;
     }
@@ -268,16 +329,20 @@ tr_dh_make_key (tr_dh_ctx_t   raw_handle
 {
   DH * handle = raw_handle;
   int dh_size, my_public_key_length;
+  const BIGNUM * hand_pub_key;
 
   assert (handle != NULL);
   assert (public_key != NULL);
 
-  handle->length = private_key_length * 8;
+
+  DH_set_length(handle, private_key_length * 8);
 
   if (!check_result (DH_generate_key (handle)))
     return false;
 
-  my_public_key_length = BN_bn2bin (handle->pub_key, public_key);
+  DH_get0_key (handle, &hand_pub_key, NULL);
+
+  my_public_key_length = BN_bn2bin (hand_pub_key, public_key);
   dh_size = DH_size (handle);
 
   tr_dh_align_key (public_key, my_public_key_length, dh_size);
