$NetBSD: patch-mpn_arm_mode1o.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/mode1o.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/mode1o.asm
@@ -88,5 +88,8 @@ L(end):	sbcs	cy, r5, cy
 	addcc	r0, r0, #1
 
 	ldmfd	sp!, {r4, r5}
-	bx	r14
+ifdef(`ARM_THUMB_MODE',
+`	bx	r14
+',`	mov	pc, r14
+')
 EPILOGUE()
