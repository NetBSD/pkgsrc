$NetBSD: patch-mpn_arm_aorslsh1__n.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/aorslsh1_n.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/aorslsh1_n.asm
@@ -163,5 +163,8 @@ L(rt1):	mov	r14, r12
 	REVCY(r12)
 L(rt0):	RETVAL(	r14)
 	pop	{r4-r10r11, r14}
-	bx	r14
+ifdef(`ARM_THUMB_MODE',
+`	bx	r14
+',`	mov	pc, r14
+')
 EPILOGUE()
