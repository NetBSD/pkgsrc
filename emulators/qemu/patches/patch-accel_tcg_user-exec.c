$NetBSD: patch-accel_tcg_user-exec.c,v 1.2 2020/05/10 11:33:23 skrll Exp $

Fix building on NetBSD/arm by extracting the FSR value from the
correct siginfo_t field.

--- accel/tcg/user-exec.c.orig	2020-04-28 16:49:24.000000000 +0000
+++ accel/tcg/user-exec.c
@@ -492,6 +492,7 @@ int cpu_signal_handler(int host_signum, 
 
 #if defined(__NetBSD__)
 #include <ucontext.h>
+#include <sys/siginfo.h>
 #endif
 
 int cpu_signal_handler(int host_signum, void *pinfo,
@@ -500,6 +501,7 @@ int cpu_signal_handler(int host_signum, 
     siginfo_t *info = pinfo;
 #if defined(__NetBSD__)
     ucontext_t *uc = puc;
+    siginfo_t *si = pinfo;
 #else
     ucontext_t *uc = puc;
 #endif
@@ -514,15 +516,47 @@ int cpu_signal_handler(int host_signum, 
     pc = uc->uc_mcontext.arm_pc;
 #endif
 
+#if defined(__NetBSD__)
+    /* siginfo_t::si_trap is the FSR value, in which bit 11 is WnR
+     * (assuming a v6 or later processor; on v5 we will always report
+     * this as a read).
+     */
+    is_write = extract32(si->si_trap, 11, 1);
+#else
     /* error_code is the FSR value, in which bit 11 is WnR (assuming a v6 or
      * later processor; on v5 we will always report this as a read).
      */
     is_write = extract32(uc->uc_mcontext.error_code, 11, 1);
+#endif
     return handle_cpu_signal(pc, info, is_write, &uc->uc_sigmask);
 }
 
 #elif defined(__aarch64__)
 
+#if defined(__NetBSD__)
+
+#include <ucontext.h>
+#include <sys/siginfo.h>
+
+int cpu_signal_handler(int host_signum, void *pinfo, void *puc)
+{
+    ucontext_t *uc = puc;
+    siginfo_t *si = pinfo;
+    unsigned long pc;
+    int is_write;
+    uint32_t esr;
+
+    pc = uc->uc_mcontext.__gregs[_REG_PC];
+    esr = si->si_trap;
+
+    /* siginfo_t::si_trap is the ESR value, for data aborts ESR.EC
+     * is 0b10010x: then bit 6 is the WnR bit
+     */
+    is_write = extract32(esr, 27, 5) == 0x12 && extract32(esr, 6, 1) == 1;
+    return handle_cpu_signal(pc, si, is_write, &uc->uc_sigmask);
+}
+
+#else
 #ifndef ESR_MAGIC
 /* Pre-3.16 kernel headers don't have these, so provide fallback definitions */
 #define ESR_MAGIC 0x45535201
@@ -585,6 +619,7 @@ int cpu_signal_handler(int host_signum, 
     }
     return handle_cpu_signal(pc, info, is_write, &uc->uc_sigmask);
 }
+#endif
 
 #elif defined(__s390__)
 
