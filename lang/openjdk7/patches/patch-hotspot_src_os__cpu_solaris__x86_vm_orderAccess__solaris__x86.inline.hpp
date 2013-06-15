$NetBSD: patch-hotspot_src_os__cpu_solaris__x86_vm_orderAccess__solaris__x86.inline.hpp,v 1.1 2013/06/15 09:31:05 jperkin Exp $

GCC support.

--- hotspot/src/os_cpu/solaris_x86/vm/orderAccess_solaris_x86.inline.hpp.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/src/os_cpu/solaris_x86/vm/orderAccess_solaris_x86.inline.hpp
@@ -71,7 +71,11 @@ extern "C" {
   }
   inline void _OrderAccess_fence() {
     // Always use locked addl since mfence is sometimes expensive
+#ifdef AMD64
+    __asm__ volatile ("lock; addl $0,0(%%rsp)" : : : "cc", "memory");
+#else
     __asm__ volatile ("lock; addl $0,0(%%esp)" : : : "cc", "memory");
+#endif // AMD64
   }
 
 }
