$NetBSD: patch-hotspot_src_cpu_aarch64_vm_pauth__aarch64.hpp,v 1.1 2022/07/17 03:03:41 tnn Exp $

Only supports pointer authentication on Linux.

--- hotspot/src/cpu/aarch64/vm/pauth_aarch64.hpp.orig	2022-04-23 02:23:55.000000000 +0000
+++ hotspot/src/cpu/aarch64/vm/pauth_aarch64.hpp
@@ -25,7 +25,13 @@
 #ifndef CPU_AARCH64_PAUTH_AARCH64_INLINE_HPP
 #define CPU_AARCH64_PAUTH_AARCH64_INLINE_HPP
 
+#if defined(__linux__)
 #include "pauth_linux_aarch64.inline.hpp"
+#else
+inline address pauth_strip_pointer(address ptr) {
+  return ptr;
+}
+#endif
 
 inline bool pauth_ptr_is_raw(address ptr) {
   // Confirm none of the high bits are set in the pointer.
