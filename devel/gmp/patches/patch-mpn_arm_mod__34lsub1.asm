$NetBSD: patch-mpn_arm_mod__34lsub1.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/mod_34lsub1.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/mod_34lsub1.asm
@@ -106,7 +106,10 @@ L(sum2):
 	add	r0, r0, r12, lsr #8
 
 	pop	{ r4, r5, r6, r7 }
-	bx	lr
+ifdef(`ARM_THUMB_MODE',
+`	bx	lr
+',`	mov	pc, lr
+')
 
 L(le2):	cmn	n, #1
 	bne	L(1)
@@ -117,5 +120,8 @@ L(1):	ldr	r2, [ap]
 	bic	r0, r2, #0xff000000
 	add	r0, r0, r2, lsr #24
 	pop	{ r4, r5, r6, r7 }
-	bx	lr
+ifdef(`ARM_THUMB_MODE',
+`	bx	lr
+',`	mov	pc, lr
+')
 EPILOGUE()
