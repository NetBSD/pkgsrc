$NetBSD: patch-amd64_ssemem.s,v 1.1 2024/02/21 12:50:22 msaitoh Exp $

AMD64: use PLT calls for PIC, as required by linker 
https://github.com/cruvolo/ramspeed/commit/f3a766dc4f89cee97b5283d5c6bdf8b8e3474813
	
--- amd64/ssemem.s
+++ amd64/ssemem.s
@@ -33,7 +33,7 @@ ssecp:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -69,7 +69,7 @@ ssecp:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	movq	%rbx, %rcx
@@ -155,10 +155,10 @@ ssecp:
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
@@ -193,7 +193,7 @@ ssesc:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -229,7 +229,7 @@ ssesc:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	fldln2
 	fst	16(%rsp)
@@ -354,10 +354,10 @@ ssesc:
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
@@ -394,7 +394,7 @@ ssead:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -433,7 +433,7 @@ ssead:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	movq	%rbx, %rcx
@@ -554,10 +554,10 @@ ssead:
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
@@ -595,7 +595,7 @@ ssetr:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -634,7 +634,7 @@ ssetr:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	fldln2
 	fst	16(%rsp)
@@ -794,10 +794,10 @@ ssetr:
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
@@ -833,7 +833,7 @@ ssecp_nt:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -869,7 +869,7 @@ ssecp_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$10, %rbx
 	movq	%rbx, %rcx
@@ -1037,10 +1037,10 @@ ssecp_nt:
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
@@ -1075,7 +1075,7 @@ ssesc_nt:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -1111,7 +1111,7 @@ ssesc_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	fldln2
 	fst	16(%rsp)
@@ -1350,10 +1350,10 @@ ssesc_nt:
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
@@ -1390,7 +1390,7 @@ ssead_nt:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -1429,7 +1429,7 @@ ssead_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$10, %rbx
 	movq	%rbx, %rcx
@@ -1680,10 +1680,10 @@ ssead_nt:
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
@@ -1721,7 +1721,7 @@ ssetr_nt:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -1760,7 +1760,7 @@ ssetr_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	fldln2
 	fst	16(%rsp)
@@ -2082,10 +2082,10 @@ ssetr_nt:
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
@@ -2122,7 +2122,7 @@ ssecp_nt_t0:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -2158,7 +2158,7 @@ ssecp_nt_t0:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$10, %rbx
 	movq	%rbx, %rcx
@@ -2326,10 +2326,10 @@ ssecp_nt_t0:
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
@@ -2364,7 +2364,7 @@ ssesc_nt_t0:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -2400,7 +2400,7 @@ ssesc_nt_t0:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	fldln2
 	fst	16(%rsp)
@@ -2639,10 +2639,10 @@ ssesc_nt_t0:
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
@@ -2679,7 +2679,7 @@ ssead_nt_t0:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -2718,7 +2718,7 @@ ssead_nt_t0:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$10, %rbx
 	movq	%rbx, %rcx
@@ -2969,10 +2969,10 @@ ssead_nt_t0:
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
@@ -3010,7 +3010,7 @@ ssetr_nt_t0:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -3049,7 +3049,7 @@ ssetr_nt_t0:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	fldln2
 	fst	16(%rsp)
@@ -3371,10 +3371,10 @@ ssetr_nt_t0:
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
