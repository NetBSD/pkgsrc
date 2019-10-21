$NetBSD: patch-test_ELF_gnustack.s,v 1.3 2019/10/21 22:07:58 rjs Exp $

Add '-z nognustack' option to disable emitting PT_GNU_STACK.
https://reviews.llvm.org/D56554

--- test/ELF/gnustack.s.orig	2019-05-01 05:49:01.000000000 +0000
+++ test/ELF/gnustack.s
@@ -10,6 +10,9 @@
 # RUN: ld.lld %t1 -o %t -z noexecstack
 # RUN: llvm-readobj --program-headers -S %t | FileCheck --check-prefix=RW %s
 
+# RUN: ld.lld %t1 -o %t -z noexecstack
+# RUN: llvm-readobj --program-headers -S %t | FileCheck --check-prefix=NOGNUSTACK %s
+
 # RW:      Type: PT_GNU_STACK
 # RW-NEXT: Offset: 0x0
 # RW-NEXT: VirtualAddress: 0x0
@@ -35,5 +38,7 @@
 # RWX-NEXT: ]
 # RWX-NEXT: Alignment: 0
 
+# NOGNUSTACK-NOT: Type: PT_GNU_STACK
+
 .globl _start
 _start:
