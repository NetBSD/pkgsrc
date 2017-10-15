$NetBSD: patch-asmrun_signals__osdep.h,v 1.1.6.1 2017/10/15 11:49:07 spz Exp $

Provide necessary glue to do this on NetBSD/powerpc.

--- asmrun/signals_osdep.h.orig	2017-07-13 08:56:44.000000000 +0000
+++ asmrun/signals_osdep.h
@@ -303,27 +303,30 @@
   #define CONTEXT_YOUNG_PTR (context->regs->gpr[31])
   #define CONTEXT_SP (context->regs->gpr[1])
 
-/****************** s390x, ELF (Linux) */
-#elif defined(TARGET_s390x) && defined(SYS_elf)
+/****************** PowerPC, NetBSD */
 
-  #define DECLARE_SIGNAL_HANDLER(name) \
-    static void name(int sig, struct sigcontext * context)
+#elif defined(TARGET_power) && defined (SYS_netbsd)
 
-  #define SET_SIGACT(sigact,name) \
-     sigact.sa_handler = (void (*)(int)) (name); \
-     sigact.sa_flags = 0
+ #include <ucontext.h>
+ #define DECLARE_SIGNAL_HANDLER(name) \
+ static void name(int sig, siginfo_t * info, ucontext_t * context)
 
-  typedef unsigned long context_reg;
-  #define CONTEXT_PC (context->sregs->regs.psw.addr)
-  #define CONTEXT_EXCEPTION_POINTER (context->sregs->regs.gprs[13])
-  #define CONTEXT_YOUNG_LIMIT (context->sregs->regs.gprs[10])
-  #define CONTEXT_YOUNG_PTR (context->sregs->regs.gprs[11])
-  #define CONTEXT_SP (context->sregs->regs.gprs[15])
+ #define SET_SIGACT(sigact,name) \
+ sigact.sa_sigaction = (void (*)(int,siginfo_t *,void *)) (name); \
+ sigact.sa_flags = SA_SIGINFO
+
+ #define CONTEXT_PC (_UC_MACHINE_PC(context))
+ #define CONTEXT_EXCEPTION_POINTER (context->uc_mcontext.__gregs[_REG_R29])
+ #define CONTEXT_YOUNG_PTR (context->uc_mcontext.__gregs[_REG_R31])
+ #define CONTEXT_SP (_UC_MACHINE_SP(context))
+ #define CONTEXT_FAULTING_ADDRESS ((char *) info->si_addr)
 
-/****************** PowerPC, BSD */
+/* #define CONTEXT_YOUNG_LIMIT (CONTEXT_STATE.CONTEXT_REG(r30)) */
+
+/****************** PowerPC, other BSDs */
 
 #elif defined(TARGET_power) && \
-    (defined(SYS_bsd) || defined(SYS_bsd_elf) || defined(SYS_netbsd))
+    (defined(SYS_bsd) || defined(SYS_bsd_elf))
 
   #define DECLARE_SIGNAL_HANDLER(name) \
     static void name(int sig, int code, struct sigcontext * context)
@@ -339,6 +342,23 @@
   #define CONTEXT_YOUNG_PTR (context->sc_frame.fixreg[31])
   #define CONTEXT_SP (context->sc_frame.fixreg[1])
 
+/****************** s390x, ELF (Linux) */
+#elif defined(TARGET_s390x) && defined(SYS_elf)
+
+  #define DECLARE_SIGNAL_HANDLER(name) \
+    static void name(int sig, struct sigcontext * context)
+
+  #define SET_SIGACT(sigact,name) \
+     sigact.sa_handler = (void (*)(int)) (name); \
+     sigact.sa_flags = 0
+
+  typedef unsigned long context_reg;
+  #define CONTEXT_PC (context->sregs->regs.psw.addr)
+  #define CONTEXT_EXCEPTION_POINTER (context->sregs->regs.gprs[13])
+  #define CONTEXT_YOUNG_LIMIT (context->sregs->regs.gprs[10])
+  #define CONTEXT_YOUNG_PTR (context->sregs->regs.gprs[11])
+  #define CONTEXT_SP (context->sregs->regs.gprs[15])
+
 /****************** SPARC, Solaris */
 
 #elif defined(TARGET_sparc) && defined(SYS_solaris)
