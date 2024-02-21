$NetBSD: patch-amd64_fltmem.s,v 1.1 2024/02/21 12:50:22 msaitoh Exp $

AMD64: use PLT calls for PIC, as required by linker 
https://github.com/cruvolo/ramspeed/commit/f3a766dc4f89cee97b5283d5c6bdf8b8e3474813

--- amd64/fltmem.s
+++ amd64/fltmem.s
@@ -29,11 +29,11 @@ floatcp:
 	shlq	$10, %rbx
 /* allocate */
 	movq	%rbx, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 /* allocate */
 	movq	%rbx, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r13
 /* prefill */
 	movq	%rbx, %rcx
@@ -52,7 +52,7 @@ floatcp:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$8, %rbx
 	movq	%rbx, %rcx
@@ -138,13 +138,13 @@ floatcp:
 /* wall time (finish) */
 	leaq	16(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* free */
 	movq	%r13, %rdi
-	call	free
+	call	free@plt
 /* free */
 	movq	%r12, %rdi
-	call	free
+	call	free@plt
 /* calculate */
 	movq	16(%rsp), %rax
 	subq	0(%rsp), %rax
@@ -174,11 +174,11 @@ floatsc:
 	shlq	$10, %rbx
 /* allocate */
 	movq	%rbx, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 /* allocate */
 	movq	%rbx, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r13
 /* prefill */
 	movq	%rbx, %rcx
@@ -197,7 +197,7 @@ floatsc:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$8, %rbx
 	movq	%rbx, %rcx
@@ -316,13 +316,13 @@ floatsc:
 /* wall time (finish) */
 	leaq	16(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* free */
 	movq	%r13, %rdi
-	call	free
+	call	free@plt
 /* free */
 	movq	%r12, %rdi
-	call	free
+	call	free@plt
 /* calculate */
 	movq	16(%rsp), %rax
 	subq	0(%rsp), %rax
@@ -354,15 +354,15 @@ floatad:
 	shlq	$10, %rbx
 /* allocate */
 	movq	%rbx, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 /* allocate */
 	movq	%rbx, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r13
 /* allocate */
 	movq	%rbx, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r14
 /* prefill */
 	movq	%rbx, %rcx
@@ -387,7 +387,7 @@ floatad:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$8, %rbx
 	movq	%rbx, %rcx
@@ -508,16 +508,16 @@ floatad:
 /* wall time (finish) */
 	leaq	16(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* free */
 	movq	%r14, %rdi
-	call	free
+	call	free@plt
 /* free */
 	movq	%r13, %rdi
-	call	free
+	call	free@plt
 /* free */
 	movq	%r12, %rdi
-	call	free
+	call	free@plt
 /* calculate */
 	movq	16(%rsp), %rax
 	subq	0(%rsp), %rax
@@ -551,15 +551,15 @@ floattr:
 	shlq	$10, %rbx
 /* allocate */
 	movq	%rbx, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 /* allocate */
 	movq	%rbx, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r13
 /* allocate */
 	movq	%rbx, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r14
 /* prefill */
 	movq	%rbx, %rcx
@@ -584,7 +584,7 @@ floattr:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$8, %rbx
 	movq	%rbx, %rcx
@@ -738,16 +738,16 @@ floattr:
 /* wall time (finish) */
 	leaq	16(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* free */
 	movq	%r14, %rdi
-	call	free
+	call	free@plt
 /* free */
 	movq	%r13, %rdi
-	call	free
+	call	free@plt
 /* free */
 	movq	%r12, %rdi
-	call	free
+	call	free@plt
 /* calculate */
 	movq	16(%rsp), %rax
 	subq	0(%rsp), %rax
