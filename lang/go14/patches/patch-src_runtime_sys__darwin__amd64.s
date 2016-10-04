$NetBSD: patch-src_runtime_sys__darwin__amd64.s,v 1.1 2016/10/04 18:45:22 bsiegert Exp $

--- src/runtime/sys_darwin_amd64.s.orig	2016-10-04 18:40:17.000000000 +0000
+++ src/runtime/sys_darwin_amd64.s
@@ -141,10 +141,16 @@ timeloop:
 
 systime:
 	// Fall back to system call (usually first call in this thread).
-	MOVQ	SP, DI	// must be non-nil, unused
+	MOVQ	SP, DI
 	MOVQ	$0, SI
+	MOVQ	$0, DX  // required as of Sierra; Issue 16570
 	MOVL	$(0x2000000+116), AX
 	SYSCALL
+	CMPQ	AX, $0
+	JNE	inreg
+	MOVQ	0(SP), AX
+	MOVL	8(SP), DX
+inreg:
 	// sec is in AX, usec in DX
 	// return nsec in AX
 	IMULQ	$1000000000, AX
