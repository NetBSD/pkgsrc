$NetBSD: patch-target_i386_hvf_x86__cpuid.c,v 1.1 2025/05/16 02:11:10 schmonz Exp $

Fix booting HVF x86 guests with 2 or more CPUs.

Bug report: <https://gitlab.com/qemu-project/qemu/-/issues/2938>

Patch: <https://lore.kernel.org/qemu-devel/20250514031652.838763-3-xiaoyao.li@intel.com/>

--- target/i386/hvf/x86_cpuid.c.orig	2025-05-16 01:40:12.741037957 +0000
+++ target/i386/hvf/x86_cpuid.c
@@ -73,7 +73,7 @@ uint32_t hvf_get_supported_cpuid(uint32_
              CPUID_MSR | CPUID_PAE | CPUID_MCE | CPUID_CX8 | CPUID_APIC |
              CPUID_SEP | CPUID_MTRR | CPUID_PGE | CPUID_MCA | CPUID_CMOV |
              CPUID_PAT | CPUID_PSE36 | CPUID_CLFLUSH | CPUID_MMX |
-             CPUID_FXSR | CPUID_SSE | CPUID_SSE2 | CPUID_SS;
+             CPUID_FXSR | CPUID_SSE | CPUID_SSE2 | CPUID_SS | CPUID_HT;
         ecx &= CPUID_EXT_SSE3 | CPUID_EXT_PCLMULQDQ | CPUID_EXT_SSSE3 |
              CPUID_EXT_FMA | CPUID_EXT_CX16 | CPUID_EXT_PCID |
              CPUID_EXT_SSE41 | CPUID_EXT_SSE42 | CPUID_EXT_MOVBE |
