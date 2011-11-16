$NetBSD: patch-mpn_arm_invert__limb.asm,v 1.1 2011/11/16 21:30:07 is Exp $

--- mpn/arm/invert_limb.asm.orig	2011-05-08 09:49:29.000000000 +0000
+++ mpn/arm/invert_limb.asm
@@ -42,7 +42,7 @@ L(2):	add	r2, pc, r2
 	adds	r1, r3, r0
 	adc	r12, r12, r0
 	rsb	r0, r12, r2
-	bx	lr
+	mov	pc,lr
 
 	ALIGN(4)
 L(4):	.word	approx_tab-8-512-L(2)
