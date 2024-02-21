$NetBSD: patch-amd64_mmxmark.s,v 1.1 2024/02/21 12:50:22 msaitoh Exp $

AMD64: use PLT calls for PIC, as required by linker 
https://github.com/cruvolo/ramspeed/commit/f3a766dc4f89cee97b5283d5c6bdf8b8e3474813

--- amd64/mmxmark.s
+++ amd64/mmxmark.s
@@ -31,7 +31,7 @@ mmxwr:
 	movq	$0x0000000000001000, %r15
 	movq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -39,7 +39,7 @@ mmxwr:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	movq	%rbx, %rcx
@@ -123,10 +123,10 @@ mmxwr:
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
@@ -159,7 +159,7 @@ mmxrd:
 	movq	$0x0000000000001000, %r15
 	movq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -183,7 +183,7 @@ mmxrd:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	movq	%rbx, %rcx
@@ -266,10 +266,10 @@ mmxrd:
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
@@ -302,7 +302,7 @@ mmxwr_nt:
 	movq	$0x0000000000001000, %r15
 	movq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -310,7 +310,7 @@ mmxwr_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	movq	%rbx, %rcx
@@ -394,10 +394,10 @@ mmxwr_nt:
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
@@ -430,7 +430,7 @@ mmxrd_nt:
 	movq	$0x0000000000001000, %r15
 	movq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -454,7 +454,7 @@ mmxrd_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	decq	%rbx
@@ -614,10 +614,10 @@ mmxrd_nt:
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
