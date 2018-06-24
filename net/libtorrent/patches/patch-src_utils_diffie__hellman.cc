$NetBSD: patch-src_utils_diffie__hellman.cc,v 1.1 2018/06/24 16:57:58 adam Exp $

Fix for OpenSSL 1.1.x.
https://github.com/rakshasa/libtorrent/issues/171

--- src/utils/diffie_hellman.cc.orig	2018-06-07 04:24:52.000000000 +0000
+++ src/utils/diffie_hellman.cc
@@ -55,8 +55,16 @@ DiffieHellman::DiffieHellman(const unsig
 
 #ifdef USE_OPENSSL
   m_dh = DH_new();
+#  ifdef USE_OPENSSL_1_1
+  BIGNUM * const dh_p = BN_bin2bn(prime, primeLength, NULL);
+  BIGNUM * const dh_g = BN_bin2bn(generator, generatorLength, NULL);
+  if (dh_p == NULL || dh_g == NULL ||
+      !DH_set0_pqg(m_dh, dh_p, NULL, dh_g))
+	  throw internal_error("Could not generate Diffie-Hellman parameters");
+#  else
   m_dh->p = BN_bin2bn(prime, primeLength, NULL);
   m_dh->g = BN_bin2bn(generator, generatorLength, NULL);
+#  endif
 
   DH_generate_key(m_dh);
 #else
@@ -74,7 +82,15 @@ DiffieHellman::~DiffieHellman() {
 bool
 DiffieHellman::is_valid() const {
 #ifdef USE_OPENSSL
+  if (m_dh == NULL)
+    return false;
+#  ifdef USE_OPENSSL_1_1
+  const BIGNUM *pub_key;
+  DH_get0_key(m_dh, &pub_key, NULL);
+  return pub_key != NULL;
+#  else
   return m_dh != NULL && m_dh->pub_key != NULL;
+#  endif
 #else
   return false;
 #endif
@@ -103,8 +119,14 @@ DiffieHellman::store_pub_key(unsigned ch
 #ifdef USE_OPENSSL
   std::memset(dest, 0, length);
 
-  if ((int)length >= BN_num_bytes(m_dh->pub_key))
-    BN_bn2bin(m_dh->pub_key, dest + length - BN_num_bytes(m_dh->pub_key));
+  const BIGNUM *pub_key;
+#  ifdef USE_OPENSSL_1_1
+  DH_get0_key(m_dh, &pub_key, NULL);
+#  else
+  pub_key = m_dh->pub_key;
+#  endif
+  if ((int)length >= BN_num_bytes(pub_key))
+    BN_bn2bin(pub_key, dest + length - BN_num_bytes(pub_key));
 #endif
 }
 
