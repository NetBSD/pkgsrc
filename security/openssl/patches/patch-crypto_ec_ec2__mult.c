$NetBSD: patch-crypto_ec_ec2__mult.c,v 1.1 2014/04/02 12:11:35 he Exp $

Part of fix for CVE-2014-0076.

--- crypto/ec/ec2_mult.c.orig	2014-01-06 13:47:42.000000000 +0000
+++ crypto/ec/ec2_mult.c
@@ -208,11 +208,15 @@ static int gf2m_Mxy(const EC_GROUP *grou
 	return ret;
 	}
 
+
 /* Computes scalar*point and stores the result in r.
  * point can not equal r.
- * Uses algorithm 2P of
+ * Uses a modified algorithm 2P of
  *     Lopez, J. and Dahab, R.  "Fast multiplication on elliptic curves over 
  *     GF(2^m) without precomputation" (CHES '99, LNCS 1717).
+ *
+ * To protect against side-channel attack the function uses constant time swap,
+ * avoiding conditional branches.
  */
 static int ec_GF2m_montgomery_point_multiply(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar,
 	const EC_POINT *point, BN_CTX *ctx)
@@ -246,6 +250,11 @@ static int ec_GF2m_montgomery_point_mult
 	x2 = &r->X;
 	z2 = &r->Y;
 
+	bn_wexpand(x1, group->field.top);
+	bn_wexpand(z1, group->field.top);
+	bn_wexpand(x2, group->field.top);
+	bn_wexpand(z2, group->field.top);
+
 	if (!BN_GF2m_mod_arr(x1, &point->X, group->poly)) goto err; /* x1 = x */
 	if (!BN_one(z1)) goto err; /* z1 = 1 */
 	if (!group->meth->field_sqr(group, z2, x1, ctx)) goto err; /* z2 = x1^2 = x^2 */
@@ -270,16 +279,12 @@ static int ec_GF2m_montgomery_point_mult
 		word = scalar->d[i];
 		while (mask)
 			{
-			if (word & mask)
-				{
-				if (!gf2m_Madd(group, &point->X, x1, z1, x2, z2, ctx)) goto err;
-				if (!gf2m_Mdouble(group, x2, z2, ctx)) goto err;
-				}
-			else
-				{
-				if (!gf2m_Madd(group, &point->X, x2, z2, x1, z1, ctx)) goto err;
-				if (!gf2m_Mdouble(group, x1, z1, ctx)) goto err;
-				}
+			BN_consttime_swap(word & mask, x1, x2, group->field.top);
+			BN_consttime_swap(word & mask, z1, z2, group->field.top);
+			if (!gf2m_Madd(group, &point->X, x2, z2, x1, z1, ctx)) goto err;
+			if (!gf2m_Mdouble(group, x1, z1, ctx)) goto err;
+			BN_consttime_swap(word & mask, x1, x2, group->field.top);
+			BN_consttime_swap(word & mask, z1, z2, group->field.top);
 			mask >>= 1;
 			}
 		mask = BN_TBIT;
