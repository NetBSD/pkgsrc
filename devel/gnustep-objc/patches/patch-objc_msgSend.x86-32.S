$NetBSD: patch-objc_msgSend.x86-32.S,v 1.2 2016/11/16 22:46:49 wiedi Exp $

Depending on the compiler, __i686.get_pc_thunk.bx may be missing
from runtime. Replace it by a localy supplied version.

--- objc_msgSend.x86-32.S.orig	2012-05-04 13:28:08.000000000 +0000
+++ objc_msgSend.x86-32.S
@@ -78,7 +78,7 @@
 	jmp   *%eax
 6:                                        # smallObject:
 	push  %ebx                           # Save old %ebx
-	call  __i686.get_pc_thunk.bx
+	call  ___i686.get_pc_thunk.bx
 	addl  $_GLOBAL_OFFSET_TABLE_, %ebx
 	mov   SmallObjectClasses@GOT(%ebx), %eax
 	mov   (%eax), %eax
@@ -98,3 +98,6 @@ objc_msgSend:
 	.type	objc_msgSend_stret, @function
 objc_msgSend_stret:
 	MSGSEND 8, 12, 0
+___i686.get_pc_thunk.bx:
+	mov   (%esp),%ebx
+	ret
