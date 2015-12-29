$NetBSD: patch-libf95.a-0.93_math_x87.S,v 1.2 2015/12/29 23:34:46 dholland Exp $

Fix assembler instructions.

--- libf95.a-0.93/math/x87.S.orig	2013-03-01 11:18:05.000000000 +0000
+++ libf95.a-0.93/math/x87.S
@@ -250,7 +250,7 @@ PUBLIC(g95_ceiling_1_r10)
 	fldcw	(SP)
 	frndint
 	fldcw	4(SP)
-	fistp	(SP)
+	fistps	(SP)
 	mov	(SP), %al
 	SIGNX_AL
 	add	$8, SP
@@ -266,7 +266,7 @@ PUBLIC(g95_ceiling_2_r10)
 	fldcw	(SP)
 	frndint
 	fldcw	4(SP)
-	fistp	(SP)
+	fistps	(SP)
 	mov	(SP), %ax
 	SIGNX_AX
 	add	$8, SP
@@ -675,7 +675,7 @@ PUBLIC(g95_floor_1_r10)
 	fldcw	(SP)
 	frndint
 	fldcw	4(SP)
-	fistp	(SP)
+	fistps	(SP)
 	mov	(SP), %al
 	SIGNX_AL
 	add	$8, SP
@@ -691,7 +691,7 @@ PUBLIC(g95_floor_2_r10)
 	fldcw	(SP)
 	frndint
 	fldcw	4(SP)
-	fistp	(SP)
+	fistps	(SP)
 	mov	(SP), %ax
 	SIGNX_AX
 	add	$8, SP
@@ -833,7 +833,7 @@ PUBLIC(g95_nint_1_r10)
 	frndint
 	fldcw	4(SP)
 
-	fistp	(SP)
+	fistps	(SP)
 	movb	(SP), %al
 	SIGNX_AL
 	add	$8, SP
@@ -861,7 +861,7 @@ PUBLIC(g95_nint_2_r10)
 	frndint
 	fldcw	4(SP)
 
-	fistp	(SP)
+	fistps	(SP)
 	movw	(SP), %ax
 	SIGNX_AX
 	add	$8, SP
