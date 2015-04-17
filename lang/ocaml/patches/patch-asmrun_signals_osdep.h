$NetBSD: patch-asmrun_signals_osdep.h,v 1.5 2015/04/17 09:12:12 jaapb Exp $

Use correct data structures for power architecture; also do signal
handling correctly for i386/NetBSD.

First hunk taken from upstream tracker at:
  http://caml.inria.fr/mantis/view.php?id=6772

--- asmrun/signals_osdep.h.orig	2014-09-28 19:46:24.000000000 +0000
+++ asmrun/signals_osdep.h
@@ -146,6 +146,23 @@
  #define CONTEXT_YOUNG_PTR (context->sc_r15)
  #define CONTEXT_FAULTING_ADDRESS ((char *) info->si_addr)
 
+/****************** AMD64, NetBSD */
+
+#elif defined(TARGET_amd64) && defined (SYS_netbsd)
+
+ #include <ucontext.h>
+ #define DECLARE_SIGNAL_HANDLER(name) \
+ static void name(int sig, siginfo_t * info, ucontext_t * context)
+
+ #define SET_SIGACT(sigact,name) \
+ sigact.sa_sigaction = (void (*)(int,siginfo_t *,void *)) (name); \
+ sigact.sa_flags = SA_SIGINFO
+
+ #define CONTEXT_PC (_UC_MACHINE_PC(context))
+ #define CONTEXT_EXCEPTION_POINTER (context->uc_mcontext.gregs[REG_R14])
+ #define CONTEXT_YOUNG_PTR (context->uc_mcontext.gregs[REG_R15])
+ #define CONTEXT_FAULTING_ADDRESS ((char *) info->si_addr)
+
 /****************** I386, Linux */
 
 #elif defined(TARGET_i386) && defined(SYS_linux_elf)
@@ -163,14 +180,24 @@
 
 #elif defined(TARGET_i386) && defined(SYS_bsd_elf)
 
- #define DECLARE_SIGNAL_HANDLER(name) \
- static void name(int sig, siginfo_t * info, struct sigcontext * context)
+ #if defined (__NetBSD__)
+  #include <ucontext.h>
+  #define DECLARE_SIGNAL_HANDLER(name) \
+  static void name(int sig, siginfo_t * info, ucontext_t * context)
+ #else
+  #define DECLARE_SIGNAL_HANDLER(name) \
+  static void name(int sig, siginfo_t * info, struct sigcontext * context)
+ #endif
 
  #define SET_SIGACT(sigact,name) \
  sigact.sa_sigaction = (void (*)(int,siginfo_t *,void *)) (name); \
  sigact.sa_flags = SA_SIGINFO
 
- #define CONTEXT_PC (context->sc_eip)
+ #if defined (__NetBSD__)
+  #define CONTEXT_PC (_UC_MACHINE_PC(context))
+ #else
+  #define CONTEXT_PC (context->sc_eip)
+ #endif
  #define CONTEXT_FAULTING_ADDRESS ((char *) info->si_addr)
 
 /****************** I386, BSD */
@@ -278,12 +305,21 @@
      sigact.sa_handler = (void (*)(int)) (name); \
      sigact.sa_flags = 0
 
+#ifdef __NetBSD__
+  typedef register_t context_reg;
+  #define CONTEXT_PC (context->sc_frame.srr0)
+  #define CONTEXT_EXCEPTION_POINTER (context->sc_frame.fixreg[29])
+  #define CONTEXT_YOUNG_LIMIT (context->sc_frame.fixreg[30])
+  #define CONTEXT_YOUNG_PTR (context->sc_frame.fixreg[31])
+  #define CONTEXT_SP (context->sc_frame.fixreg[1])
+#else
   typedef unsigned long context_reg;
   #define CONTEXT_PC (context->regs->nip)
   #define CONTEXT_EXCEPTION_POINTER (context->regs->gpr[29])
   #define CONTEXT_YOUNG_LIMIT (context->regs->gpr[30])
   #define CONTEXT_YOUNG_PTR (context->regs->gpr[31])
   #define CONTEXT_SP (context->regs->gpr[1])
+#endif /* __NetBSD__ */
 
 /****************** PowerPC, BSD */
 
