$NetBSD: patch-asmrun_signals_osdep.h,v 1.3 2015/01/26 14:46:51 jaapb Exp $

Use correct data structures for power architecture; also do signal
handling correctly for i386
--- asmrun/signals_osdep.h.orig	2014-09-28 19:46:24.000000000 +0000
+++ asmrun/signals_osdep.h
@@ -161,7 +161,7 @@
 
 /****************** I386, BSD_ELF */
 
-#elif defined(TARGET_i386) && defined(SYS_bsd_elf)
+#elif defined(TARGET_i386) && defined(SYS_bsd_elf) && !defined(__NetBSD__)
 
  #define DECLARE_SIGNAL_HANDLER(name) \
  static void name(int sig, siginfo_t * info, struct sigcontext * context)
@@ -278,12 +278,21 @@
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
 
