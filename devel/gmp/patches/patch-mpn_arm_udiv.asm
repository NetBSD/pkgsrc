$NetBSD: patch-mpn_arm_udiv.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/udiv.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/udiv.asm
@@ -61,7 +61,10 @@ L(oop):	divstep(n1,n0,d)
 
 	str	n1, [rem_ptr]		C store remainder
 	adc	r0, n0, n0		C quotient: add last carry from divstep
-	bx	lr
+ifdef(`ARM_THUMB_MODE',
+`	bx	lr
+',`	mov	pc, lr
+')
 
 L(_large_divisor):
 	stmfd	sp!, { r8, lr }
