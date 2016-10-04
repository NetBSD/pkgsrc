$NetBSD: patch-src_runtime_sys__darwin__386.s,v 1.1 2016/10/04 18:45:22 bsiegert Exp $

--- src/runtime/sys_darwin_386.s.orig	2016-10-04 18:40:17.000000000 +0000
+++ src/runtime/sys_darwin_386.s
@@ -182,11 +182,17 @@ timeloop:
 
 systime:
 	// Fall back to system call (usually first call in this thread)
-	LEAL	12(SP), AX	// must be non-nil, unused
+	LEAL	16(SP), AX	// must be non-nil, unused
 	MOVL	AX, 4(SP)
 	MOVL	$0, 8(SP)	// time zone pointer
+	MOVL	$0, 12(SP)	// required as of Sierra; Issue 16570
 	MOVL	$116, AX
 	INT	$0x80
+	CMPL	AX, $0
+	JNE	inreg
+	MOVL	16(SP), AX
+	MOVL	20(SP), DX
+inreg:
 	// sec is in AX, usec in DX
 	// convert to DX:AX nsec
 	MOVL	DX, BX
