$NetBSD: patch-src_arm_sysv.S,v 1.1 2011/12/31 09:58:22 tsutsui Exp $

Pull fix from upstream for asm error on NetBSD/arm with newer binutils:
https://github.com/atgreen/libffi/commit/0e5843995f46900ef212531281e08b224464f413#diff-39
>  * src/arm/sysv.S (ffi_closure_SYSV): Add UNWIND to .pad directive.

--- src/arm/sysv.S.orig	2009-12-29 15:22:26.000000000 +0000
+++ src/arm/sysv.S
@@ -243,7 +243,7 @@ ARM_FUNC_START ffi_closure_SYSV
 	stmfd	sp!, {ip, lr}
 	UNWIND .save	{r0, lr}
 	add	r2, sp, #8
-	.pad #16
+	UNWIND .pad #16
 	sub	sp, sp, #16
 	str	sp, [sp, #8]
 	add	r1, sp, #8
