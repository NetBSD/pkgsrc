$NetBSD: patch-asmrun_amd64.S,v 1.1 2018/07/18 00:09:12 joerg Exp $

--- asmrun/amd64.S.orig	2018-07-17 21:24:20.027817665 +0000
+++ asmrun/amd64.S
@@ -724,7 +724,7 @@ G(caml_system__spacetime_shapes):
 #elif defined(SYS_mingw64) || defined(SYS_cygwin)
         .section .rdata,"dr"
 #else
-        .section    .rodata.cst8,"a",@progbits
+        .section    .rodata.cst8,"aM",@progbits,8
 #endif
         .globl  G(caml_negf_mask)
         .align  SIXTEEN_ALIGN
