$NetBSD: patch-absl_debugging_internal_vdso__support.cc,v 1.2 2022/03/06 09:34:06 wiz Exp $

Support NetBSD.
https://github.com/abseil/abseil-cpp/pull/1121

--- absl/debugging/internal/vdso_support.cc.orig	2021-11-18 10:00:05.006467401 +0000
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
@@ -104,8 +108,13 @@ const void *VDSOSupport::Init() {
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
