$NetBSD: patch-src_hotspot_cpu_aarch64_icache__aarch64.hpp,v 1.1 2020/05/04 20:46:11 tnn Exp $

Band-aid for bug in NetBSD's __clear_cache libc implementation.
Always feed it ranges in multiples of full cache lines to make
it behave more like __clear_cache on other operating systems.

--- src/hotspot/cpu/aarch64/icache_aarch64.hpp.orig	2020-04-15 22:35:23.000000000 +0000
+++ src/hotspot/cpu/aarch64/icache_aarch64.hpp
@@ -34,10 +34,19 @@ class ICache : public AbstractICache {
  public:
   static void initialize();
   static void invalidate_word(address addr) {
-    __clear_cache((char *)addr, (char *)(addr + 3));
+    invalidate_range(addr, 3);
   }
   static void invalidate_range(address start, int nbytes) {
+#if defined(__NetBSD__)
+    uint64_t ctr_el0, dc, ic, cl_mask;
+    __asm __volatile("mrs %0, ctr_el0" : "=r"(ctr_el0));
+    dc = (ctr_el0 & 0xf0000) >> 12;
+    ic = (ctr_el0 & 0xf) << 4;
+    cl_mask = ((ic > dc) ? ic : dc) - 1;
+    __clear_cache((void *)((uintptr_t)start & ~cl_mask), (void *)(((uintptr_t)start + nbytes) | cl_mask));
+#else
     __clear_cache((char *)start, (char *)(start + nbytes));
+#endif
   }
 };
 
