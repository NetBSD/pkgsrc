$NetBSD: patch-ext_apexsink_gstapexraop.c,v 1.1 2020/03/27 02:08:46 joerg Exp $

--- ext/apexsink/gstapexraop.c.orig	2020-03-26 23:08:26.395993230 +0000
+++ ext/apexsink/gstapexraop.c
@@ -292,12 +292,11 @@ gst_apexraop_connect (GstApExRAOP * con)
 
   rsa = RSA_new ();
   mod = g_base64_decode (GST_APEX_RAOP_RSA_PUBLIC_MOD, &size);
-  rsa->n = BN_bin2bn (mod, size, NULL);
   exp = g_base64_decode (GST_APEX_RAOP_RSA_PUBLIC_EXP, &size);
-  rsa->e = BN_bin2bn (exp, size, NULL);
   size =
       RSA_public_encrypt (AES_BLOCK_SIZE, conn->aes_ky, rsakey, rsa,
       RSA_PKCS1_OAEP_PADDING);
+  RSA_set0_key(rsa, BN_bin2bn (mod, size, NULL), BN_bin2bn (exp, size, NULL), NULL);
 
   ky = g_base64_encode (rsakey, size);
   iv = g_base64_encode (conn->aes_iv, AES_BLOCK_SIZE);
@@ -677,7 +676,7 @@ gst_apexraop_write (GstApExRAOP * con, g
   guchar *buffer, *frame_data;
   gushort len;
   gint bit_offset, byte_offset, i, out_len, res;
-  EVP_CIPHER_CTX aes_ctx;
+  EVP_CIPHER_CTX *aes_ctx;
   _GstApExRAOP *conn = (_GstApExRAOP *) con;
   const int frame_header_size = conn->generation == GST_APEX_GENERATION_ONE
       ? GST_APEX_RAOP_FRAME_HEADER_SIZE : GST_APEX_RTP_FRAME_HEADER_SIZE;
@@ -737,13 +736,13 @@ gst_apexraop_write (GstApExRAOP * con, g
         &bit_offset, &byte_offset);
   }
 
-  EVP_CIPHER_CTX_init (&aes_ctx);
-  EVP_CipherInit_ex (&aes_ctx, EVP_aes_128_cbc (), NULL, conn->aes_ky,
+  aes_ctx = EVP_CIPHER_CTX_new();
+  EVP_CipherInit_ex (aes_ctx, EVP_aes_128_cbc (), NULL, conn->aes_ky,
       conn->aes_iv, AES_ENCRYPT);
-  EVP_CipherUpdate (&aes_ctx, frame_data, &out_len, frame_data, /*( */
+  EVP_CipherUpdate (aes_ctx, frame_data, &out_len, frame_data, /*( */
       GST_APEX_RAOP_ALAC_HEADER_SIZE +
       length /*) / AES_BLOCK_SIZE * AES_BLOCK_SIZE */ );
-  EVP_CIPHER_CTX_cleanup (&aes_ctx);
+  EVP_CIPHER_CTX_release (aes_ctx);
 
   res =
       gst_apexraop_send (conn->data_sd, buffer,
