$NetBSD: patch-dlls_ntdll_signal__x86__64.c,v 1.1 2014/06/28 21:20:06 dholland Exp $

Teach this how to set %gs on NetBSD. Not actually tested as so far
Wine doesn't actually run, but fixes a build failure.

--- dlls/ntdll/signal_x86_64.c~	2014-01-17 19:48:48.000000000 +0000
+++ dlls/ntdll/signal_x86_64.c
@@ -199,8 +199,9 @@ extern int arch_prctl(int func, void *pt
 #define FPU_sig(context)   ((XMM_SAVE_AREA32 *)((context)->uc_mcontext.mc_fpstate))
 
 #elif defined(__NetBSD__)
-#include <sys/ucontext.h>
 #include <sys/types.h>
+#include <sys/sysarch.h>
+#include <sys/ucontext.h>
 #include <signal.h>
 
 #define RAX_sig(context)    ((context)->uc_mcontext.__gregs[_REG_RAX])
@@ -2457,6 +2458,8 @@ void signal_init_thread( TEB *teb )
     arch_prctl( ARCH_SET_GS, teb );
 #elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
     amd64_set_gsbase( teb );
+#elif defined (__NetBSD__)
+    sysarch(X86_SET_GSBASE, &teb);
 #else
 # error Please define setting %gs for your architecture
 #endif
