$NetBSD: patch-amd64_intmem.s,v 1.1 2024/02/21 12:50:22 msaitoh Exp $

AMD64: use PLT calls for PIC, as required by linker 
https://github.com/cruvolo/ramspeed/commit/f3a766dc4f89cee97b5283d5c6bdf8b8e3474813

--- amd64/intmem.s
+++ amd64/intmem.s
@@ -31,11 +31,11 @@ intcp:
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
@@ -52,7 +52,7 @@ intcp:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$8, %rbx
 	movq	%rbx, %rcx
@@ -137,13 +137,13 @@ intcp:
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
@@ -177,11 +177,11 @@ intsc:
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
@@ -198,7 +198,7 @@ intsc:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$8, %rbx
 	movq	%rbx, %rcx
@@ -283,13 +283,13 @@ intsc:
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
@@ -323,15 +323,15 @@ intad:
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
@@ -355,7 +355,7 @@ intad:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$8, %rbx
 	movq	%rbx, %rcx
@@ -475,16 +475,16 @@ intad:
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
@@ -518,15 +518,15 @@ inttr:
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
@@ -550,7 +550,7 @@ inttr:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$8, %rbx
 	movq	%rbx, %rcx
@@ -670,16 +670,16 @@ inttr:
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
