$NetBSD: patch-src_s2_util_math_exactfloat_exactfloat.cc,v 1.1 2022/10/08 20:02:06 he Exp $

Import fix from upstream for newer openssl on 32-bit hosts, ref.

https://github.com/r-spatial/s2/commit/3e791194ceb348a81d6317438e2bfe9e4a2ff1e3

--- src/s2/util/math/exactfloat/exactfloat.cc.orig	2021-01-04 12:00:17.000000000 +0000
+++ src/s2/util/math/exactfloat/exactfloat.cc
@@ -93,6 +93,7 @@ inline static void BN_ext_set_uint64(BIG
 #endif
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 // Return the absolute value of a BIGNUM as a 64-bit unsigned integer.
 // Requires that BIGNUM fits into 64 bits.
 inline static uint64 BN_ext_get_uint64(const BIGNUM* bn) {
@@ -108,8 +109,6 @@ inline static uint64 BN_ext_get_uint64(c
 #endif
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-
 // Count the number of low-order zero bits in the given BIGNUM (ignoring its
 // sign).  Returns 0 if the argument is zero.
 static int BN_ext_count_low_zero_bits(const BIGNUM* bn) {
@@ -130,6 +129,22 @@ static int BN_ext_count_low_zero_bits(co
 
 #else  // OPENSSL_VERSION_NUMBER >= 0x10100000L
 
+// Return the absolute value of a BIGNUM as a 64-bit unsigned integer.
+// Requires that BIGNUM fits into 64 bits.
+inline static uint64 BN_ext_get_uint64(const BIGNUM* bn) {
+  uint64 r;
+#ifdef IS_LITTLE_ENDIAN
+  S2_CHECK_EQ(BN_bn2lebinpad(bn, reinterpret_cast<unsigned char*>(&r),
+                             sizeof(r)), sizeof(r));
+#elif IS_BIG_ENDIAN
+  S2_CHECK_EQ(BN_bn2binpad(bn, reinterpret_cast<unsigned char*>(&r),
+                           sizeof(r)), sizeof(r));
+#else
+#error one of IS_LITTLE_ENDIAN or IS_BIG_ENDIAN should be defined!
+#endif
+  return r;
+}
+
 static int BN_ext_count_low_zero_bits(const BIGNUM* bn) {
   // In OpenSSL >= 1.1, BIGNUM is an opaque type, so d and top
   // cannot be accessed.  The bytes must be copied out at a ~25%
