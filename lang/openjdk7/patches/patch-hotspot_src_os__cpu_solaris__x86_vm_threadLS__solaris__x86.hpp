$NetBSD: patch-hotspot_src_os__cpu_solaris__x86_vm_threadLS__solaris__x86.hpp,v 1.1 2013/06/15 09:31:05 jperkin Exp $

GCC support.

--- hotspot/src/os_cpu/solaris_x86/vm/threadLS_solaris_x86.hpp.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/src/os_cpu/solaris_x86/vm/threadLS_solaris_x86.hpp
@@ -65,7 +65,10 @@ public:
     __asm__ __volatile__ ("movq %%fs:0, %0" : "=r"(rv));
     return rv;
 #else
-    return gs_thread();
+    uintptr_t rv;
+    __asm__ __volatile__ ("movl %%gs:0, %0" : "=r"(rv));
+    return rv;
+//    return gs_thread();
 #endif // AMD64
 #else  //_GNU_SOURCE
     return _raw_thread_id();
