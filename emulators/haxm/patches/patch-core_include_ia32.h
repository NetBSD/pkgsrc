$NetBSD: patch-core_include_ia32.h,v 1.1 2019/02/13 05:20:15 kamil Exp $

Cherry-pick from upstream review:
 - Fix FPU DNA exception on NetBSD
   https://github.com/intel/haxm/pull/168

--- core/include/ia32.h.orig	2019-02-12 09:24:47.000000000 +0000
+++ core/include/ia32.h
@@ -72,6 +72,7 @@ void ASMCALL set_kernel_fs(uint16_t val)
 
 void ASMCALL asm_btr(uint8_t *addr, uint bit);
 void ASMCALL asm_bts(uint8_t *addr, uint bit);
+void ASMCALL asm_clts(void);
 void ASMCALL asm_fxinit(void);
 void ASMCALL asm_fxsave(mword *addr);
 void ASMCALL asm_fxrstor(mword *addr);
@@ -85,6 +86,8 @@ void ia32_wrmsr(uint32_t reg, uint64_t v
 
 uint64_t ia32_rdtsc(void);
 
+void hax_clts(void);
+
 void hax_fxinit(void);
 void hax_fxsave(mword *addr);
 void hax_fxrstor(mword *addr);
