$NetBSD: patch-hotspot_src_os__cpu_solaris__x86_vm_os__solaris__x86.inline.hpp,v 1.1 2021/07/23 12:18:23 jperkin Exp $

Support GCC.

--- hotspot/src/os_cpu/solaris_x86/vm/os_solaris_x86.inline.hpp.orig	2021-05-14 21:52:06.000000000 +0000
+++ hotspot/src/os_cpu/solaris_x86/vm/os_solaris_x86.inline.hpp
@@ -27,8 +27,16 @@
 
 #include "runtime/os.hpp"
 
+#ifdef _GNU_SOURCE
+inline jlong os::rdtsc() {
+  uint64_t res;
+  __asm__ __volatile__ ("rdtsc" : "=A" (res));
+  return (jlong)res;
+}
+#else
 extern "C" jlong _raw_rdtsc(); // In .il file
 
 inline jlong os::rdtsc() { return _raw_rdtsc(); }
+#endif
 
 #endif // OS_CPU_SOLARIS_X86_VM_OS_SOLARIS_X86_INLINE_HPP
