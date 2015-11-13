$NetBSD: patch-mpn_arm_lshift.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/lshift.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/lshift.asm
@@ -84,5 +84,8 @@ L(end):	orr	r7, r7, r6, lsr tnc
 L(1):	str	r7, [rp, #-4]
 	mov	r0, r4, lsr tnc
 	pop	{r4, r6, r7, r8}
-	bx	r14
+ifdef(`ARM_THUMB_MODE',
+`	bx	r14
+',`	mov	pc, r14
+')
 EPILOGUE()
