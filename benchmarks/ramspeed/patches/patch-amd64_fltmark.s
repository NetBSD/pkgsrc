$NetBSD: patch-amd64_fltmark.s,v 1.1 2024/02/21 12:50:22 msaitoh Exp $

AMD64: use PLT calls for PIC, as required by linker 
https://github.com/cruvolo/ramspeed/commit/f3a766dc4f89cee97b5283d5c6bdf8b8e3474813

--- amd64/fltmark.s
+++ amd64/fltmark.s
@@ -27,12 +27,12 @@ floatwr:
 	movq	%rsi, %rbp
 /* allocate */
 	shlq	$10, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	movq	%rbx, %rcx
 	movq	%r12, %rdi
@@ -180,10 +180,10 @@ floatwr:
 /* wall time (finish) */
 	leaq	16(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* free */
 	movq	%r12, %rdi
-	call	free
+	call	free@plt
 /* calculate */
 	movq	16(%rsp), %rax
 	subq	0(%rsp), %rax
@@ -210,7 +210,7 @@ floatrd:
 	movq	%rsi, %rbp
 /* allocate */
 	shlq	$10, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 /* prefill */
 	movq	%rbx, %rcx
@@ -228,7 +228,7 @@ floatrd:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	movq	%rbx, %rcx
 	movq	%r12, %rdi
@@ -502,10 +502,10 @@ floatrd:
 /* wall time (finish) */
 	leaq	16(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* free */
 	movq	%r12, %rdi
-	call	free
+	call	free@plt
 /* calculate */
 	movq	16(%rsp), %rax
 	subq	0(%rsp), %rax
