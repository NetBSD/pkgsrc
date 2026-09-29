$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_os__bsd__aarch64.cpp,v 1.3 2026/09/29 10:49:58 tnn Exp $

Work around SIGBUS on macOS

--- src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp.orig	2026-09-29 10:45:05.907015432 +0000
+++ src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp
@@ -472,6 +472,9 @@ static inline void atomic_copy64(const v
 
 extern "C" {
   int SpinPause() {
+#if defined(__APPLE__)
+   return 0; // XXX stub broken; See JDK-8278241, JDK-8321371
+#endif
     using spin_wait_func_ptr_t = void (*)();
     spin_wait_func_ptr_t func = CAST_TO_FN_PTR(spin_wait_func_ptr_t, StubRoutines::aarch64::spin_wait());
     assert(func != nullptr, "StubRoutines::aarch64::spin_wait must not be null.");
