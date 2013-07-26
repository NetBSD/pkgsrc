$NetBSD: patch-src_x86_win64.S,v 1.1 2013/07/26 13:12:25 ryoon Exp $

Fix build on Cygwin64. From Cygwin64 1.7.22's 3.0.12-cygwin.patch.

--- src/x86/win64.S.orig	2013-03-16 11:19:39.000000000 +0000
+++ src/x86/win64.S
@@ -295,7 +295,7 @@ SYMBOL_NAME(ffi_closure_win64):
 	mov	%rax, %rcx	# context is first parameter
 	mov	%rsp, %rdx	# stack is second parameter
 	add	$48, %rdx	# point to start of arguments
-	mov	$SYMBOL_NAME(ffi_closure_win64_inner), %rax
+	lea	SYMBOL_NAME(ffi_closure_win64_inner)(%rip), %rax
 	callq	*%rax		# call the real closure function
 	add	$40, %rsp
 	movq	%rax, %xmm0	# If the closure returned a float,
