$NetBSD: patch-src_runtime_sys__netbsd__arm64.s,v 1.2 2020/04/27 18:42:12 tnn Exp $

fix stack alignent for runtime.pipe2 return value

Work around kernel clobbering of r28 on aarch64 by reloading from ucontext.
https://nxr.netbsd.org/xref/src/sys/arch/aarch64/aarch64/sig_machdep.c#104

--- src/runtime/sys_netbsd_arm64.s.orig	2020-04-08 19:15:51.000000000 +0000
+++ src/runtime/sys_netbsd_arm64.s
@@ -169,11 +169,12 @@ pipeok:
 
 // func pipe2(flags int32) (r, w int32, errno int32)
 TEXT runtime·pipe2(SB),NOSPLIT|NOFRAME,$0-20
-	ADD	$8, RSP, R0
+	ADD	$16, RSP, R0
 	MOVW	flags+0(FP), R1
 	SVC	$SYS_pipe2
-	BCC	2(PC)
+	BCC	pipe2ok
 	NEG	R0, R0
+pipe2ok:
 	MOVW	R0, errno+16(FP)
 	RET
 
@@ -319,6 +320,12 @@ TEXT runtime·sigtramp(SB),NOSPLIT,$192
 	MOVD	R26, 8*11(RSP)
 	MOVD	R27, 8*12(RSP)
 	MOVD	g, 8*13(RSP)
+	// Unclobber g for now (kernel uses it as ucontext ptr)
+	// See https://github.com/golang/go/issues/30824#issuecomment-492772426
+	// This is only correct in the non-cgo case.
+	// XXX should use lwp_getprivate as suggested.
+	// 8*36 is ucontext.uc_mcontext.__gregs[_REG_X28]
+	MOVD	8*36(g), g
 	MOVD	R29, 8*14(RSP)
 	FMOVD	F8, 8*15(RSP)
 	FMOVD	F9, 8*16(RSP)
