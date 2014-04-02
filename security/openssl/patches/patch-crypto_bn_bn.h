$NetBSD: patch-crypto_bn_bn.h,v 1.1 2014/04/02 12:11:35 he Exp $

Part of fix for CVE-2014-0076.

--- crypto/bn/bn.h.orig	2014-01-06 13:47:42.000000000 +0000
+++ crypto/bn/bn.h
@@ -538,6 +538,8 @@ BIGNUM *BN_mod_inverse(BIGNUM *ret,
 BIGNUM *BN_mod_sqrt(BIGNUM *ret,
 	const BIGNUM *a, const BIGNUM *n,BN_CTX *ctx);
 
+void	BN_consttime_swap(BN_ULONG swap, BIGNUM *a, BIGNUM *b, int nwords);
+
 /* Deprecated versions */
 #ifndef OPENSSL_NO_DEPRECATED
 BIGNUM *BN_generate_prime(BIGNUM *ret,int bits,int safe,
@@ -774,11 +776,20 @@ int RAND_pseudo_bytes(unsigned char *buf
 
 #define bn_fix_top(a)		bn_check_top(a)
 
+#define bn_check_size(bn, bits) bn_wcheck_size(bn, ((bits+BN_BITS2-1))/BN_BITS2)
+#define bn_wcheck_size(bn, words) \
+	do { \
+		const BIGNUM *_bnum2 = (bn); \
+		assert(words <= (_bnum2)->dmax && words >= (_bnum2)->top); \
+	} while (0)
+
 #else /* !BN_DEBUG */
 
 #define bn_pollute(a)
 #define bn_check_top(a)
 #define bn_fix_top(a)		bn_correct_top(a)
+#define bn_check_size(bn, bits)
+#define bn_wcheck_size(bn, words)
 
 #endif
 
