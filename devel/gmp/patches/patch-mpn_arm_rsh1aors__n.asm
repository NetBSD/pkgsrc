$NetBSD: patch-mpn_arm_rsh1aors__n.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/rsh1aors_n.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/rsh1aors_n.asm
@@ -120,5 +120,8 @@ L(e1):	RSTCY(	r12, r1)
 	str	r4, [rp, #0]
 	mov	r0, r11
 	pop	{r4-r11}
-	bx	r14
+ifdef(`ARM_THUMB_MODE',
+`	bx	r14
+',`	mov	pc, r14
+')
 EPILOGUE()
