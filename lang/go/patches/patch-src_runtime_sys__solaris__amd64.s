$NetBSD: patch-src_runtime_sys__solaris__amd64.s,v 1.1 2015/03/10 13:11:36 jperkin Exp $

Support cgo on illumos.

--- src/runtime/sys_solaris_amd64.s.orig	2014-12-11 01:18:12.000000000 +0000
+++ src/runtime/sys_solaris_amd64.s
@@ -40,7 +40,7 @@ TEXT runtime·nanotime1(SB),NOSPLIT,$0
 	SUBQ	$64, SP	// 16 bytes will do, but who knows in the future?
 	MOVQ	$3, DI	// CLOCK_REALTIME from <sys/time_impl.h>
 	MOVQ	SP, SI
-	MOVQ	libc·clock_gettime(SB), AX
+	LEAQ	libc·clock_gettime(SB), AX
 	CALL	AX
 	MOVQ	(SP), AX	// tv_sec from struct timespec
 	IMULQ	$1000000000, AX	// multiply into nanoseconds
@@ -53,7 +53,7 @@ TEXT runtime·nanotime1(SB),NOSPLIT,$0
 TEXT runtime·pipe1(SB),NOSPLIT,$0
 	SUBQ	$16, SP // 8 bytes will do, but stack has to be 16-byte alligned
 	MOVQ	SP, DI
-	MOVQ	libc·pipe(SB), AX
+	LEAQ	libc·pipe(SB), AX
 	CALL	AX
 	MOVL	0(SP), AX
 	MOVL	4(SP), DX
@@ -320,13 +320,13 @@ usleep1_noswitch:
 
 // Runs on OS stack. duration (in µs units) is in DI.
 TEXT runtime·usleep2(SB),NOSPLIT,$0
-	MOVQ	libc·usleep(SB), AX
+	LEAQ	libc·usleep(SB), AX
 	CALL	AX
 	RET
 
 // Runs on OS stack, called from runtime·osyield.
 TEXT runtime·osyield1(SB),NOSPLIT,$0
-	MOVQ	libc·sched_yield(SB), AX
+	LEAQ	libc·sched_yield(SB), AX
 	CALL	AX
 	RET
 
