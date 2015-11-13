$NetBSD: patch-mpn_arm_sec__tabselect.asm,v 1.1 2015/11/13 10:42:23 wiz Exp $

--- mpn/arm/sec_tabselect.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/arm/sec_tabselect.asm
@@ -109,7 +109,10 @@ L(tp2):	subs	c, c, #1
 	bge	L(tp2)
 	stmia	rp, {r8,r9}
 	pop	{r4-r11, r14}
-	bx	lr
+ifdef(`ARM_THUMB_MODE',
+`	bx      lr
+',`	mov     pc, lr
+')
 
 L(n2):	cmp	j, #-2
 	bne	L(n1)
@@ -127,5 +130,8 @@ L(tp1):	subs	c, c, #1
 	bge	L(tp1)
 	str	r8, [rp]
 L(n1):	pop	{r4-r11, r14}
-	bx	lr
+ifdef(`ARM_THUMB_MODE',
+`	bx      lr
+',`	mov     pc, lr
+')
 EPILOGUE()
