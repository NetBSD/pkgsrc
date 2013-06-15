$NetBSD: patch-hotspot_src_os__cpu_solaris__x86_vm_prefetch__solaris__x86.inline.hpp,v 1.1 2013/06/15 09:31:05 jperkin Exp $

GCC compatability.

--- hotspot/src/os_cpu/solaris_x86/vm/prefetch_solaris_x86.inline.hpp.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/src/os_cpu/solaris_x86/vm/prefetch_solaris_x86.inline.hpp
@@ -34,14 +34,28 @@ extern "C" {
 
 inline void Prefetch::read (void *loc, intx interval) {
 #ifdef AMD64
+#ifdef SPARC_WORKS
   _Prefetch_read(loc, interval);
+#else
+#ifdef _GNU_SOURCE
+  __asm__ ("prefetcht0 (%0,%1,1)" : : "r" (loc), "r" (interval));
+#endif // _GNU_SOURCE
+#endif // SPARC_WORKS
 #endif // AMD64
 }
 
 // Use of this method should be gated by VM_Version::has_prefetchw.
 inline void Prefetch::write(void *loc, intx interval) {
 #ifdef AMD64
+#ifdef SPARC_WORKS
   _Prefetch_write(loc, interval);
+#else
+#ifdef _GNU_SOURCE
+  // Do not use the 3dnow prefetchw instruction.  It isn't supported on em64t.
+  //  __asm__ ("prefetchw (%0,%1,1)" : : "r" (loc), "r" (interval));
+  __asm__ ("prefetcht0 (%0,%1,1)" : : "r" (loc), "r" (interval));
+#endif // _GNU_SOURCE
+#endif // SPARC_WORKS
 #endif // AMD64
 }
 
