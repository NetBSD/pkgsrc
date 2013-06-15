$NetBSD: patch-hotspot_src_os__cpu_solaris__x86_vm_os__solaris__x86.cpp,v 1.1 2013/06/15 09:31:05 jperkin Exp $

GCC support.

--- hotspot/src/os_cpu/solaris_x86/vm/os_solaris_x86.cpp.orig	2012-08-10 16:24:45.000000000 +0000
+++ hotspot/src/os_cpu/solaris_x86/vm/os_solaris_x86.cpp
@@ -237,7 +237,22 @@ frame os::get_sender_for_C_frame(frame*
   return frame(fr->sender_sp(), fr->link(), fr->sender_pc());
 }
 
+#ifdef AMD64
+#define SPELL_REG_FP "rbp"
+#else
+#define SPELL_REG_FP "ebp"
+#endif
+
+#ifdef SPARC_WORKS
 extern "C" intptr_t *_get_current_fp();  // in .il file
+#else
+#ifdef _GNU_SOURCE
+extern "C" intptr_t *_get_current_fp() {
+  register intptr_t **rbp __asm__ (SPELL_REG_FP);
+  return (intptr_t*) *rbp;   // we want what it points to.
+}
+#endif // _GNU_SOURCE
+#endif // SPARC_WORKS
 
 frame os::current_frame() {
   intptr_t* fp = _get_current_fp();  // it's inlined so want current fp
@@ -951,6 +966,11 @@ add_func_t*          os::atomic_add_func
 extern "C" void _solaris_raw_setup_fpu(address ptr);
 void os::setup_fpu() {
   address fpu_cntrl = StubRoutines::addr_fpu_cntrl_wrd_std();
+#ifndef _GNU_SOURCE
   _solaris_raw_setup_fpu(fpu_cntrl);
+#else
+  // same as hotspot/src/os_cpu/linux_x86/vm/os_linux_x86.cpp : os::setup_fpu()
+  __asm__ volatile("fldcw (%0)"::"r"(fpu_cntrl):"memory");
+#endif
 }
 #endif // AMD64
