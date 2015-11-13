$NetBSD: patch-mpn_arm_logops__n.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/logops_n.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/logops_n.asm
@@ -135,5 +135,8 @@ L(mid):	sub	n, n, #4
 	pop	{ r4, r5, r6, r7 }	C popping r8-r10 here strangely fails
 
 L(rtn):	pop	{ r8, r9, r10 }
-	bx	r14
+ifdef(`ARM_THUMB_MODE',
+`	bx	r14
+',`	mov	pc, r14
+')
 EPILOGUE()
