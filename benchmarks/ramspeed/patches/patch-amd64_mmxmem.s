$NetBSD: patch-amd64_mmxmem.s,v 1.1 2024/02/21 12:50:22 msaitoh Exp $

AMD64: use PLT calls for PIC, as required by linker 
https://github.com/cruvolo/ramspeed/commit/f3a766dc4f89cee97b5283d5c6bdf8b8e3474813

--- amd64/mmxmem.s
+++ amd64/mmxmem.s
@@ -33,7 +33,7 @@ mmxcp:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -59,7 +59,7 @@ mmxcp:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$8, %rbx
 	movq	%rbx, %rcx
@@ -145,10 +145,10 @@ mmxcp:
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
@@ -184,7 +184,7 @@ mmxsc:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -210,7 +210,7 @@ mmxsc:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	movw	$77, 16(%rsp)
 	movw	$77, 18(%rsp)
@@ -334,10 +334,10 @@ mmxsc:
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
@@ -375,7 +375,7 @@ mmxad:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -414,7 +414,7 @@ mmxad:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$8, %rbx
 	movq	%rbx, %rcx
@@ -535,10 +535,10 @@ mmxad:
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
@@ -577,7 +577,7 @@ mmxtr:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -616,7 +616,7 @@ mmxtr:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	movw	$77, 16(%rsp)
 	movw	$77, 18(%rsp)
@@ -775,10 +775,10 @@ mmxtr:
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
@@ -815,7 +815,7 @@ mmxcp_nt:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -841,7 +841,7 @@ mmxcp_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	decq	%rbx
@@ -1002,10 +1002,10 @@ mmxcp_nt:
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
@@ -1041,7 +1041,7 @@ mmxsc_nt:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -1067,7 +1067,7 @@ mmxsc_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	movw	$77, 16(%rsp)
 	movw	$77, 18(%rsp)
@@ -1298,10 +1298,10 @@ mmxsc_nt:
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
@@ -1339,7 +1339,7 @@ mmxad_nt:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -1378,7 +1378,7 @@ mmxad_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	decq	%rbx
@@ -1614,10 +1614,10 @@ mmxad_nt:
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
@@ -1656,7 +1656,7 @@ mmxtr_nt:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -1695,7 +1695,7 @@ mmxtr_nt:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	movw	$77, 16(%rsp)
 	movw	$77, 18(%rsp)
@@ -2001,10 +2001,10 @@ mmxtr_nt:
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
@@ -2041,7 +2041,7 @@ mmxcp_nt_t0:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -2067,7 +2067,7 @@ mmxcp_nt_t0:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	decq	%rbx
@@ -2228,10 +2228,10 @@ mmxcp_nt_t0:
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
@@ -2267,7 +2267,7 @@ mmxsc_nt_t0:
 	movq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -2293,7 +2293,7 @@ mmxsc_nt_t0:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	movw	$77, 16(%rsp)
 	movw	$77, 18(%rsp)
@@ -2524,10 +2524,10 @@ mmxsc_nt_t0:
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
@@ -2565,7 +2565,7 @@ mmxad_nt_t0:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -2604,7 +2604,7 @@ mmxad_nt_t0:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* execute */
 	shrq	$9, %rbx
 	decq	%rbx
@@ -2840,10 +2840,10 @@ mmxad_nt_t0:
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
@@ -2882,7 +2882,7 @@ mmxtr_nt_t0:
 	addq	%rbx, %rdi
 	addq	%rbx, %rdi
 	addq	%r15, %rdi
-	call	malloc
+	call	malloc@plt
 	movq	%rax, %r12
 	addq	%r15, %r12
 	andq	$0xFFFFFFFFFFFFF000, %r12
@@ -2921,7 +2921,7 @@ mmxtr_nt_t0:
 /* wall time (start) */
 	leaq	0(%rsp), %rdi
 	xorq	%rsi, %rsi
-	call	gettimeofday
+	call	gettimeofday@plt
 /* create the multiplier */
 	movw	$77, 16(%rsp)
 	movw	$77, 18(%rsp)
@@ -3227,10 +3227,10 @@ mmxtr_nt_t0:
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
