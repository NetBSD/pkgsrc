$NetBSD: patch-absl_debugging_internal_vdso__support.cc,v 1.5 2022/07/06 15:27:01 wiz Exp $

No support for SunOS yet, so disable for the time being.

--- absl/debugging/internal/vdso_support.cc.orig	2022-06-23 18:22:47.000000000 +0000
+++ absl/debugging/internal/vdso_support.cc
@@ -101,6 +101,9 @@ const void *VDSOSupport::Init() {
     }
   }
 #endif  // ABSL_HAVE_GETAUXVAL
+#if defined(__sun)
+      return nullptr;
+#else // !__sun
   if (vdso_base_.load(std::memory_order_relaxed) == kInvalidBase) {
     int fd = open("/proc/self/auxv", O_RDONLY);
     if (fd == -1) {
@@ -140,6 +143,7 @@ const void *VDSOSupport::Init() {
   // from assigning to getcpu_fn_ more than once.
   getcpu_fn_.store(fn, std::memory_order_relaxed);
   return vdso_base_.load(std::memory_order_relaxed);
+#endif // __sun
 }
 
 const void *VDSOSupport::SetBase(const void *base) {
