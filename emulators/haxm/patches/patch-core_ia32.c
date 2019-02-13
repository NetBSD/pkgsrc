$NetBSD: patch-core_ia32.c,v 1.1 2019/02/13 05:20:15 kamil Exp $

Cherry-pick from upstream review:
 - Fix FPU DNA exception on NetBSD
   https://github.com/intel/haxm/pull/168

--- core/ia32.c.orig	2019-02-12 09:24:47.000000000 +0000
+++ core/ia32.c
@@ -81,6 +81,11 @@ uint64_t ia32_rdtsc(void)
 #endif
 }
 
+void hax_clts(void)
+{
+    asm_clts();
+}
+
 void hax_fxinit(void)
 {
     asm_fxinit();
