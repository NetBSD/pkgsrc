$NetBSD: patch-mpn_arm_com.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/com.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/com.asm
@@ -71,5 +71,9 @@ L(top):	ldmia	up!, { r3, r8, r9, r12 }	C
 	bne	L(top)
 
 	ldmfd	sp!, { r7, r8, r9 }		C restore regs from stack
-L(rtn):	bx	lr
+L(rtn):
+ifdef(`ARM_THUMB_MODE',
+`	bx	lr
+',`	mov	pc, lr
+')
 EPILOGUE()
