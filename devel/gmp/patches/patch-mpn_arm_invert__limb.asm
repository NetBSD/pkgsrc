$NetBSD: patch-mpn_arm_invert__limb.asm,v 1.3 2013/01/31 20:30:26 adam Exp $

--- mpn/arm/invert_limb.asm.orig	2012-12-18 19:05:09.000000000 +0000
+++ mpn/arm/invert_limb.asm
@@ -41,7 +41,7 @@ PROLOGUE(mpn_invert_limb)
 	adds	r1, r12, r0
 	adc	r3, r3, r0
 	rsb	r0, r3, r2
-	bx	lr
+	mov	pc,lr
 EPILOGUE()
 
 	.section .rodata
