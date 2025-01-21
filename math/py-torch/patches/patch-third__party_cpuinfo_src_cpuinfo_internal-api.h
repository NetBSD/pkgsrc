$NetBSD: patch-third__party_cpuinfo_src_cpuinfo_internal-api.h,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* For NetBSD/i386 and amd64.

--- third_party/cpuinfo/src/cpuinfo/internal-api.h.orig	2025-01-20 07:59:15.308588507 +0000
+++ third_party/cpuinfo/src/cpuinfo/internal-api.h
@@ -50,6 +50,7 @@ extern CPUINFO_INTERNAL const struct cpu
 CPUINFO_PRIVATE void cpuinfo_x86_mach_init(void);
 CPUINFO_PRIVATE void cpuinfo_x86_linux_init(void);
 CPUINFO_PRIVATE void cpuinfo_x86_freebsd_init(void);
+CPUINFO_PRIVATE void cpuinfo_x86_netbsd_init(void);
 #if defined(_WIN32) || defined(__CYGWIN__)
 #if CPUINFO_ARCH_ARM64
 CPUINFO_PRIVATE BOOL CALLBACK cpuinfo_arm_windows_init(PINIT_ONCE init_once, PVOID parameter, PVOID* context);
