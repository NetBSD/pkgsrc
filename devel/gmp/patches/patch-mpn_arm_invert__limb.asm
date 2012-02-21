$NetBSD: patch-mpn_arm_invert__limb.asm,v 1.2 2012/02/21 13:18:19 drochner Exp $

--- mpn/arm/invert_limb.asm.orig	2012-01-27 08:59:30.000000000 +0000
+++ mpn/arm/invert_limb.asm
@@ -42,7 +42,7 @@ L(2):	add	r2, pc, r2
 	adds	r1, r12, r0
 	adc	r3, r3, r0
 	rsb	r0, r3, r2
-	bx	lr
+	mov	pc,lr
 
 	ALIGN(4)
 L(4):	.word	approx_tab-8-512-L(2)
