$NetBSD: patch-accel_tcg_user-exec.c,v 1.1 2019/07/03 14:38:13 thorpej Exp $

Fix building on NetBSD/arm by extracting the FSR value from the
correct siginfo_t field.

--- accel/tcg/user-exec.c.orig	2019-07-03 13:09:53.530028621 +0000
+++ accel/tcg/user-exec.c	2019-07-03 13:22:13.179596536 +0000
@@ -448,6 +448,7 @@ int cpu_signal_handler(int host_signum, 
 
 #if defined(__NetBSD__)
 #include <ucontext.h>
+#include <sys/siginfo.h>
 #endif
 
 int cpu_signal_handler(int host_signum, void *pinfo,
@@ -456,6 +457,7 @@ int cpu_signal_handler(int host_signum, 
     siginfo_t *info = pinfo;
 #if defined(__NetBSD__)
     ucontext_t *uc = puc;
+    siginfo_t *si = pinfo;
 #else
     ucontext_t *uc = puc;
 #endif
@@ -470,10 +472,18 @@ int cpu_signal_handler(int host_signum, 
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
 
