$NetBSD: patch-test_ELF_gnustack.s,v 1.4 2019/11/03 12:10:29 kamil Exp $

Cherry-pick upstream patch commit 2a0fcae3d4d1fd85d6ae8378d7c6f12430c0087d
[lld] [ELF] Add '-z nognustack' opt to suppress emitting PT_GNU_STAC dummy option for an AArch64 erratum.

--- test/ELF/gnustack.s.orig	2019-05-01 05:49:01.000000000 +0000
+++ test/ELF/gnustack.s
@@ -10,6 +10,9 @@
 # RUN: ld.lld %t1 -o %t -z noexecstack
 # RUN: llvm-readobj --program-headers -S %t | FileCheck --check-prefix=RW %s
 
+# RUN: ld.lld %t1 -o %t -z nognustack
+# RUN: llvm-readobj --program-headers -s %t | FileCheck --check-prefix=NOGNUSTACK %s
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
