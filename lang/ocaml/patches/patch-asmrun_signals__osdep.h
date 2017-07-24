$NetBSD: patch-asmrun_signals__osdep.h,v 1.1.2.2 2017/07/24 16:27:15 spz Exp $

Provide required glue to make this work on the various 
NetBSD/powerpc ports.

--- asmrun/signals_osdep.h.orig	2016-11-04 16:08:24.000000000 +0000
+++ asmrun/signals_osdep.h
@@ -154,6 +154,26 @@
  #define CONTEXT_YOUNG_PTR (context->uc_mcontext.gregs[REG_R15])
  #define CONTEXT_FAULTING_ADDRESS ((char *) info->si_addr)
 
+/****************** PowerPC, NetBSD */
+
+#elif defined(TARGET_power) && defined (__NetBSD__)
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
+ #define CONTEXT_EXCEPTION_POINTER (context->uc_mcontext.__gregs[_REG_R29])
+ #define CONTEXT_YOUNG_PTR (context->uc_mcontext.__gregs[_REG_R31])
+ #define CONTEXT_SP (_UC_MACHINE_SP(context))
+ #define CONTEXT_FAULTING_ADDRESS ((char *) info->si_addr)
+
+/* #define CONTEXT_YOUNG_LIMIT (CONTEXT_STATE.CONTEXT_REG(r30)) */
+
 /****************** I386, Linux */
 
 #elif defined(TARGET_i386) && defined(SYS_linux_elf)
@@ -287,7 +307,7 @@
 
 /****************** PowerPC, ELF (Linux) */
 
-#elif defined(TARGET_power) && defined(SYS_elf)
+#elif defined(TARGET_power) && defined(SYS_elf) && !defined(__NetBSD__)
 
   #define DECLARE_SIGNAL_HANDLER(name) \
     static void name(int sig, struct sigcontext * context)
