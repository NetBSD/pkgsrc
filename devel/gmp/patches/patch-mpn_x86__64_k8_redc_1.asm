$NetBSD: patch-mpn_x86__64_k8_redc_1.asm,v 1.1 2014/04/18 10:49:01 adam Exp $

Workaround for Darwin assembler quirk.
https://gmplib.org/repo/gmp/raw-rev/1fab0adc5ff7

--- mpn/x86_64/k8/redc_1.asm.orig	2014-03-25 14:37:55.000000000 +0000
+++ mpn/x86_64/k8/redc_1.asm
@@ -114,7 +114,7 @@ ifdef(`PIC',`
 
 	JUMPTABSECT
 	ALIGN(8)
-L(tab):	JMPENT(	L(0m4), L(tab))
+L(tab):	JMPENT(	L(0), L(tab))
 	JMPENT(	L(1), L(tab))
 	JMPENT(	L(2), L(tab))
 	JMPENT(	L(3), L(tab))
@@ -397,6 +397,7 @@ L(le1):	add	%r10, (up)
 
 
 	ALIGN(16)
+L(0):
 L(0m4):
 L(lo0):	mov	(mp,nneg,8), %rax
 	mov	nneg, i
