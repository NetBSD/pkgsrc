$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_vm__version__bsd__aarch64.cpp,v 1.1 2026/08/16 11:54:29 tnn Exp $

Add runtime CPU detection support for NetBSD.

--- src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp.orig	2026-08-16 10:56:39.893223726 +0000
+++ src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp
@@ -27,6 +27,13 @@
 #include "precompiled.hpp"
 #include "runtime/os.hpp"
 #include "vm_version_aarch64.hpp"
+#if defined(__NetBSD__)
+#include "register_aarch64.hpp" // for FloatRegister
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <machine/armreg.h>
+#include <stdio.h>
+#endif
 
 void VM_Version::get_compatible_board(char *buf, int buflen) {
   assert(buf != nullptr, "invalid argument");
@@ -541,6 +548,98 @@ void VM_Version::get_os_cpu_info() {
   }
 #endif // __FreeBSD__
 #endif // __FreeBSD__ || __OpenBSD__
+
+#if defined(__NetBSD__)
+  size_t len;
+  int curcpu;
+  int mib[] = { CTL_HW, HW_NCPU };
+  int ncpu;
+  struct aarch64_sysctl_cpu_id id;
+  char path[32];
+  int num_fp = 0;
+  int num_asimd = 0;
+  int num_aes = 0;
+  int num_pmull = 0;
+  int num_sha1 = 0;
+  int num_sha2 = 0;
+  int num_crc32 = 0;
+  int num_lse = 0;
+  int num_dcpop = 0;
+  int num_sha3 = 0;
+  int num_sha512 = 0;
+  int num_sve = 0;
+  int num_paca = 0;
+  len = sizeof(ncpu);
+  if (sysctl(mib, 2, &ncpu, &len, NULL, 0) < 0)
+    return;
+  for (curcpu = 0; curcpu < ncpu; curcpu++) {
+    len = sizeof(id);
+    snprintf(path, sizeof(path), "machdep.cpu%d.cpu_id", curcpu);
+    if (sysctlbyname(path, &id, &len, NULL, 0) < 0)
+      continue;
+
+    if (__SHIFTOUT(id.ac_aa64pfr0,  ID_AA64PFR0_EL1_FP) == ID_AA64PFR0_EL1_FP_IMPL)
+      num_fp++;
+    if (__SHIFTOUT(id.ac_aa64pfr0,  ID_AA64PFR0_EL1_ADVSIMD) == ID_AA64PFR0_EL1_ADV_SIMD_IMPL)
+     num_asimd++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_AES) >= ID_AA64ISAR0_EL1_AES_AES)
+     num_aes++;
+    if ( __SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_AES) >= ID_AA64ISAR0_EL1_AES_PMUL)
+      num_pmull++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA1) >= ID_AA64ISAR0_EL1_SHA1_SHA1CPMHSU)
+      num_sha1++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA2) >= ID_AA64ISAR0_EL1_SHA2_SHA256HSU)
+      num_sha2++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_CRC32) >= ID_AA64ISAR0_EL1_CRC32_CRC32X)
+      num_crc32++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_ATOMIC) >= ID_AA64ISAR0_EL1_ATOMIC_SWP)
+      num_lse++;
+    if (__SHIFTOUT(id.ac_aa64isar1, ID_AA64ISAR1_EL1_DPB) >= ID_AA64ISAR1_EL1_DPB_CVAP)
+      num_dcpop++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA3) >= ID_AA64ISAR0_EL1_SHA3_EOR3)
+      num_sha3++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA2) >= ID_AA64ISAR0_EL1_SHA2_SHA512HSU)
+      num_sha512++;
+    if (__SHIFTOUT(id.ac_aa64pfr0,  ID_AA64PFR0_EL1_SVE) >= ID_AA64PFR0_EL1_SVE_IMPL)
+      num_sve++;
+    if (__SHIFTOUT(id.ac_aa64isar1, ID_AA64ISAR1_EL1_APA) >= ID_AA64ISAR1_EL1_APA_QARMA ||
+        __SHIFTOUT(id.ac_aa64isar1, ID_AA64ISAR1_EL1_API) >= ID_AA64ISAR1_EL1_API_SUPPORTED)
+     num_paca++;
+    // TODO: SVE2 and SVE_BITPERM live in id.ac_aa64zfr0 but shiftout macros are not yet added to armreg.h
+  }
+  _features = 0;
+  if (num_fp == ncpu)
+    _features |= CPU_FP;
+  if (num_asimd == ncpu)
+    _features |= CPU_ASIMD;
+  if (num_aes == ncpu)
+    _features |= CPU_AES;
+  if (num_pmull == ncpu)
+     _features |= CPU_PMULL;
+  if (num_sha1 == ncpu)
+     _features |= CPU_SHA1;
+  if (num_sha2 == ncpu)
+     _features |= CPU_SHA2;
+  if (num_crc32 == ncpu)
+    _features |= CPU_CRC32;
+  if (num_lse == ncpu)
+    _features |= CPU_LSE;
+  if (num_dcpop == ncpu)
+    _features |= CPU_DCPOP;
+  if (num_sha3 == ncpu)
+    _features |= CPU_SHA3;
+  if (num_sha512 == ncpu)
+    _features |= CPU_SHA512;
+  if (num_sve == ncpu)
+    _features |= CPU_SVE;
+  if (num_paca == ncpu)
+    _features |= CPU_PACA;
+
+  _cpu = CPU_IMPL(id.ac_midr);
+  _model = CPU_PART(id.ac_midr);
+  _variant = CPU_VAR(id.ac_midr);
+  _revision = CPU_REV(id.ac_midr);
+#endif
 
   /*
    * Step 3: Get cache line sizes and _zva_length using same approach as Linux.
