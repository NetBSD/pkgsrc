$NetBSD: patch-mpn_arm_invert__limb.asm,v 1.5 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/invert_limb.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/invert_limb.asm
@@ -52,7 +52,10 @@ PROLOGUE(mpn_invert_limb)
 	adds	r1, r12, r0
 	adc	r3, r3, r0
 	rsb	r0, r3, r2
-	bx	lr
+ifdef(`ARM_THUMB_MODE',
+`	bx	lr
+',`	mov	pc, lr
+')
 EPILOGUE()
 
 	.section .rodata
