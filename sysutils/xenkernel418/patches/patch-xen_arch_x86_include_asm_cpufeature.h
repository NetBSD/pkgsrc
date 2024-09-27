$NetBSD: patch-xen_arch_x86_include_asm_cpufeature.h,v 1.1 2024/09/27 12:45:49 manu Exp $

Disable Indirect Branch Tracking, which requires endbr64 instructions
in Xen function's start. Current build fail to produce them, hence 
we crash if IBT is enabled.

--- ./xen/arch/x86/include/asm/cpufeature.h.orig	2024-06-27 15:00:35.531392406 +0000
+++ ./xen/arch/x86/include/asm/cpufeature.h	2024-06-27 15:02:49.643543717 +0000
@@ -215,9 +215,10 @@
 #define cpu_has_lfence_dispatch boot_cpu_has(X86_FEATURE_LFENCE_DISPATCH)
 #define cpu_has_nscb            boot_cpu_has(X86_FEATURE_NSCB)
 #define cpu_has_xen_lbr         boot_cpu_has(X86_FEATURE_XEN_LBR)
 #define cpu_has_xen_shstk       boot_cpu_has(X86_FEATURE_XEN_SHSTK)
-#define cpu_has_xen_ibt         boot_cpu_has(X86_FEATURE_XEN_IBT)
+/* Not ready: we need to make sure we use endbr64 instructions in Xen */
+#define cpu_has_xen_ibt         0 /* boot_cpu_has(X86_FEATURE_XEN_IBT) */
 
 #define cpu_has_msr_tsc_aux     (cpu_has_rdtscp || cpu_has_rdpid)
 
 /* Bugs. */
