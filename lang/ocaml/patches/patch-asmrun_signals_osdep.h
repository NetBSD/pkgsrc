$NetBSD: patch-asmrun_signals_osdep.h,v 1.1 2012/10/08 15:05:32 jaapb Exp $

Use correct data structures for power architecture
--- asmrun/signals_osdep.h.orig	2012-02-04 10:15:24.000000000 +0000
+++ asmrun/signals_osdep.h
@@ -212,12 +212,22 @@
   #define SET_SIGACT(sigact,name) \
      sigact.sa_handler = (void (*)(int)) (name); \
      sigact.sa_flags = 0
+  
+ #ifdef __NetBSD__
+  typedef register_t context_reg;
+  #define CONTEXT_PC (context->sc_frame.srr0)
+  #define CONTEXT_EXCEPTION_POINTER (context->sc_frame.fixreg[29])
+  #define CONTEXT_YOUNG_LIMIT (context->sc_frame.fixreg[30])
+  #define CONTEXT_YOUNG_PTR (context->sc_frame.fixreg[31])
+ 
+ #else
 
   typedef unsigned long context_reg;
   #define CONTEXT_PC (context->regs->nip)
   #define CONTEXT_EXCEPTION_POINTER (context->regs->gpr[29])
   #define CONTEXT_YOUNG_LIMIT (context->regs->gpr[30])
   #define CONTEXT_YOUNG_PTR (context->regs->gpr[31])
+ #endif /* __NetBSD */
 
 /****************** PowerPC, BSD */
 
