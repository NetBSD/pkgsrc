$NetBSD: patch-asmrun_signals_osdep.h,v 1.8 2016/05/05 08:12:01 jaapb Exp $

Use correct data structures for power architecture; also do signal
handling correctly for i386 and amd64/NetBSD.
 
First hunk taken from upstream tracker at:
  http://caml.inria.fr/mantis/view.php?id=6772
--- asmrun/signals_osdep.h.orig	2016-04-01 12:53:41.000000000 +0000
+++ asmrun/signals_osdep.h
@@ -137,6 +137,23 @@
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
@@ -305,7 +322,7 @@
 
 /****************** PowerPC, BSD */
 
-#elif defined(TARGET_power) && (defined(SYS_bsd) || defined(SYS_bsd_elf))
+#elif defined(TARGET_power) && (defined(SYS_bsd) || defined(SYS_bsd_elf) || defined(SYS_netbsd))
 
   #define DECLARE_SIGNAL_HANDLER(name) \
     static void name(int sig, int code, struct sigcontext * context)
