$NetBSD: patch-mpn_arm_cnd__aors__n.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/cnd_aors_n.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/cnd_aors_n.asm
@@ -130,5 +130,8 @@ L(top):	ldm	vp!, {r4,r5,r6,r7}
 
 L(end):	RETVAL
 	pop	{r4-r11}
-	bx	r14
+ifdef(`ARM_THUMB_MODE',
+`	bx      r14
+',`	mov     pc, r14
+')
 EPILOGUE()
