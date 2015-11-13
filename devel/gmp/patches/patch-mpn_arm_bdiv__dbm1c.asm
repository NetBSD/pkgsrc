$NetBSD: patch-mpn_arm_bdiv__dbm1c.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/bdiv_dbm1c.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/bdiv_dbm1c.asm
@@ -109,5 +109,8 @@ L(wd1):	subs	r5, r5, r8
 	str	r5, [qp]
 	sbc	r0, r5, r12
 	pop	{r4, r5, r6, r7, r8}
-	bx	lr
+ifdef(`ARM_THUMB_MODE',
+`	bx	lr
+',`	mov	pc, lr
+')
 EPILOGUE()
