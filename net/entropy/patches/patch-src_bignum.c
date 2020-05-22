$NetBSD: patch-src_bignum.c,v 1.1 2020/05/22 01:23:42 joerg Exp $

Don't play with assembler, the compiler knows how to do it anyway.

--- src/bignum.c.orig	2020-05-22 00:32:45.737382942 +0000
+++ src/bignum.c
@@ -703,20 +703,6 @@ limb_t bn_mul_limb(limb_t w[], limb_t u[
  */
 limb_t sl_div(limb_t *q, limb_t *r, limb_t u[2], limb_t v)
 {
-#if	ASM_X86
-	limb_t qq;
-	limb_t rr;
-
-	if (0 == v)
-		/* division by zero */
-		return LIMBMASK;
-	asm volatile(
-		"divl	%4"
-		: "=a"(qq), "=d"(rr)
-		: "a"(u[0]), "d"(u[1]), "g"(v));
-	*q = qq;
-	*r = rr;
-#else
 	dlimb_t dd;
 
 	if (0 == v)
@@ -725,7 +711,6 @@ limb_t sl_div(limb_t *q, limb_t *r, limb
 	dd = ((dlimb_t)u[1] << LIMBBITS) | u[0];
 	*q = dd / v;
 	*r = dd % v;
-#endif
 	return 0;
 }
 
