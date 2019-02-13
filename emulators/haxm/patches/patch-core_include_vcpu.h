$NetBSD: patch-core_include_vcpu.h,v 1.1 2019/02/13 05:20:15 kamil Exp $

Cherry-pick from upstream review:
 - Fix FPU DNA exception on NetBSD
   https://github.com/intel/haxm/pull/168

--- core/include/vcpu.h.orig	2019-02-12 09:24:47.000000000 +0000
+++ core/include/vcpu.h
@@ -238,6 +238,7 @@ struct vcpu_t {
 #ifdef CONFIG_HAX_EPT2
     struct mmio_fetch_cache mmio_fetch;
 #endif  // CONFIG_HAX_EPT2
+    int cr0_ts;
 };
 
 #define vmx(v, field) v->vmx.field
