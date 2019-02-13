$NetBSD: patch-core_ia32__ops.asm,v 1.1 2019/02/13 05:20:15 kamil Exp $

Cherry-pick from upstream review:
 - Fix FPU DNA exception on NetBSD
   https://github.com/intel/haxm/pull/168

--- core/ia32_ops.asm.orig	2019-02-12 09:24:47.000000000 +0000
+++ core/ia32_ops.asm
@@ -213,6 +213,10 @@ function asm_enable_irq, 0
     sti
     ret
 
+function asm_clts, 0
+    clts
+    ret
+
 function asm_fxinit, 0
     finit
     ret
