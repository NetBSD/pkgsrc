$NetBSD: patch-objc_msgSend.x86-32.S,v 1.1 2015/04/18 07:23:18 manu Exp $

Depending on the compiler, __i686.get_pc_thunk.bx may be missing
from runtime. Replace it by a localy supplied version.

--- objc_msgSend.x86-32.S.orig	2015-04-17 09:44:49.000000000 +0000
+++ objc_msgSend.x86-32.S	2015-04-17 09:47:40.000000000 +0000
@@ -77,9 +77,9 @@
 
 	jmp   *%eax
 6:                                        # smallObject:
 	push  %ebx                           # Save old %ebx
-	call  __i686.get_pc_thunk.bx
+	call  ___i686.get_pc_thunk.bx
 	addl  $_GLOBAL_OFFSET_TABLE_, %ebx
 	mov   SmallObjectClasses@GOT(%ebx), %eax
 	mov   (%eax), %eax
 	popl  %ebx
@@ -97,4 +97,7 @@
 .globl objc_msgSend_stret
 	.type	objc_msgSend_stret, @function
 objc_msgSend_stret:
 	MSGSEND 8, 12, 0
+___i686.get_pc_thunk.bx:
+	mov   (%esp),%ebx
+	ret
