$NetBSD: patch-absl_debugging_internal_vdso__support.cc,v 1.3 2022/03/26 22:50:18 tnn Exp $

Support NetBSD.
https://github.com/abseil/abseil-cpp/pull/1121
No support for SunOS yet, so disable for the time being.

--- absl/debugging/internal/vdso_support.cc.orig	2021-11-03 15:26:14.000000000 +0000
+++ absl/debugging/internal/vdso_support.cc
@@ -50,6 +50,10 @@
 #define AT_SYSINFO_EHDR 33  // for crosstoolv10
 #endif
 
+#if defined(__NetBSD__)
+using Elf32_auxv_t = Aux32Info;
+using Elf64_auxv_t = Aux64Info;
+#endif
 #if defined(__FreeBSD__)
 using Elf64_auxv_t = Elf64_Auxinfo;
 using Elf32_auxv_t = Elf32_Auxinfo;
@@ -93,6 +97,9 @@ const void *VDSOSupport::Init() {
     }
   }
 #endif  // ABSL_HAVE_GETAUXVAL
+#if defined(__sun)
+      return nullptr;
+#else // !__sun
   if (vdso_base_.load(std::memory_order_relaxed) == kInvalidBase) {
     int fd = open("/proc/self/auxv", O_RDONLY);
     if (fd == -1) {
@@ -104,8 +111,13 @@ const void *VDSOSupport::Init() {
     ElfW(auxv_t) aux;
     while (read(fd, &aux, sizeof(aux)) == sizeof(aux)) {
       if (aux.a_type == AT_SYSINFO_EHDR) {
+#if defined(__NetBSD__)
+        vdso_base_.store(reinterpret_cast<void *>(aux.a_v),
+                         std::memory_order_relaxed);
+#else
         vdso_base_.store(reinterpret_cast<void *>(aux.a_un.a_val),
                          std::memory_order_relaxed);
+#endif
         break;
       }
     }
@@ -127,6 +139,7 @@ const void *VDSOSupport::Init() {
   // from assigning to getcpu_fn_ more than once.
   getcpu_fn_.store(fn, std::memory_order_relaxed);
   return vdso_base_.load(std::memory_order_relaxed);
+#endif // __sun
 }
 
 const void *VDSOSupport::SetBase(const void *base) {
