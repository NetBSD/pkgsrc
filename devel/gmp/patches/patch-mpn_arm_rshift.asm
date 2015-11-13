$NetBSD: patch-mpn_arm_rshift.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/rshift.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/rshift.asm
@@ -82,5 +82,8 @@ L(end):	orr	r7, r7, r6, lsl tnc
 L(1):	str	r7, [rp]
 	mov	r0, r4, lsl tnc
 	pop	{r4, r6, r7, r8}
-	bx	r14
+ifdef(`ARM_THUMB_MODE',
+`	bx	r14
+',`	mov	pc, r14
+')
 EPILOGUE()
