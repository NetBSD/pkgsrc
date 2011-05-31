$NetBSD: patch-crypto_ecdsa_ecs__ossl.c,v 1.1 2011/05/31 17:18:42 tez Exp $

Add protection against ECDSA timing attacks as mentioned in the paper
by Billy Bob Brumley and Nicola Tuveri, see:
  http://eprint.iacr.org/2011/232.pdf
[Billy Bob Brumley and Nicola Tuveri]

--- crypto/ecdsa/ecs_ossl.c.orig	2009-12-01 11:32:16.000000000 -0600
+++ crypto/ecdsa/ecs_ossl.c	2011-05-31 11:17:14.168169900 -0500
@@ -144,6 +144,16 @@
 			}
 		while (BN_is_zero(k));
 
+#ifdef ECDSA_POINT_MUL_NO_CONSTTIME
+		/* We do not want timing information to leak the length of k,
+		 * so we compute G*k using an equivalent scalar of fixed
+		 * bit-length. */
+
+		if (!BN_add(k, k, order)) goto err;
+		if (BN_num_bits(k) <= BN_num_bits(order))
+			if (!BN_add(k, k, order)) goto err;
+#endif /* def(ECDSA_POINT_MUL_NO_CONSTTIME) */
+
 		/* compute r the x-coordinate of generator * k */
 		if (!EC_POINT_mul(group, tmp_point, k, NULL, NULL, ctx))
 		{

