$NetBSD: patch-mpn_arm_invert__limb.asm,v 1.6 2015/11/13 11:36:44 wiz Exp $

--- mpn/arm/invert_limb.asm.orig	2015-11-01 15:19:49.000000000 +0000
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
 
 	RODATA
