$NetBSD: patch-nbstart.S,v 1.1 2013/12/08 00:35:28 jakllsch Exp $

--- nbstart.S.orig	2013-12-08 00:26:53.000000000 +0000
+++ nbstart.S
@@ -0,0 +1,9 @@
+#include "defs.h"
+	.globl _start
+_start:
+	movl	$LOW_TEST_ADR, %edi
+	movl	$_binary_memtest_shared_bin_start, %esi
+	movl	$_binary_memtest_shared_bin_size, %ecx
+	movl	%edi, %eax
+	rep movsb %ds:(%esi),%es:(%edi)
+	jmp	*%eax
