$NetBSD: patch-mpn_arm_copyd.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/copyd.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/copyd.asm
@@ -80,5 +80,9 @@ L(top):	subs	n, n, #4
 
 L(end):	stmda	rp, { r3,r4,r5,r12 }
 	pop	{ r4-r5 }
-L(rtn):	bx	lr
+L(rtn):
+ifdef(`ARM_THUMB_MODE',
+`	bx	lr
+',`	mov	pc, lr
+')
 EPILOGUE()
