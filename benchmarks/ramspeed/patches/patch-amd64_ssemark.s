$NetBSD: patch-amd64_ssemark.s,v 1.1 2024/02/21 12:50:22 msaitoh Exp $

AMD64: use PLT calls for PIC, as required by linker 
https://github.com/cruvolo/ramspeed/commit/f3a766dc4f89cee97b5283d5c6bdf8b8e3474813

--- amd64/ssemark.s
+++ amd64/ssemark.s
@@ -31,7 +31,7 @@ ssewr:
 	movq	$0x0000000000001000, %r15
 	movq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -39,7 +39,7 @@ ssewr:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	movq	%rbx, %rcx
@@ -91,10 +91,10 @@ ssewr:
 /* wall time (finish) */
 	leaq	16(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* free memory */
 	movq	%r15, %rdi
-	call	free
+	call	free@plt
 /* time calculation (in microseconds) */
 	movq	16(%rsp), %rax
 	subq	0(%rsp), %rax
@@ -126,7 +126,7 @@ sserd:
 	movq	$0x0000000000001000, %r15
 	movq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -150,7 +150,7 @@ sserd:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	movq	%rbx, %rcx
@@ -201,10 +201,10 @@ sserd:
 /* wall time (finish) */
 	leaq	16(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* free memory */
 	movq	%r15, %rdi
-	call	free
+	call	free@plt
 /* time calculation (in microseconds) */
 	movq	16(%rsp), %rax
 	subq	0(%rsp), %rax
@@ -236,7 +236,7 @@ ssewr_nt:
 	movq	$0x0000000000001000, %r15
 	movq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -244,7 +244,7 @@ ssewr_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	movq	%rbx, %rcx
@@ -296,10 +296,10 @@ ssewr_nt:
 /* wall time (finish) */
 	leaq	16(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* free memory */
 	movq	%r15, %rdi
-	call	free
+	call	free@plt
 /* time calculation (in microseconds) */
 	movq	16(%rsp), %rax
 	subq	0(%rsp), %rax
@@ -331,7 +331,7 @@ sserd_nt:
 	movq	$0x0000000000001000, %r15
 	movq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -355,7 +355,7 @@ sserd_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	decq	%rbx
@@ -451,10 +451,10 @@ sserd_nt:
 /* wall time (finish) */
 	leaq	16(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* free memory */
 	movq	%r15, %rdi
-	call	free
+	call	free@plt
 /* time calculation (in microseconds) */
 	movq	16(%rsp), %rax
 	subq	0(%rsp), %rax
