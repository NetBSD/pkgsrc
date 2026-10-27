$NetBSD: patch-dlls_ntdll_unix_signal__x86__64.c,v 1.2 2026/10/27 14:43:42 wiz Exp $

1. chunk:
Workaround for PR kern/60539: XSAVE changes break ucontext userspace API.

2. chunk:
Fix signal definition for NetBSD.

--- dlls/ntdll/unix/signal_x86_64.c.orig	2024-01-16 20:55:47.000000000 +0000
+++ dlls/ntdll/unix/signal_x86_64.c
@@ -203,7 +203,7 @@ __ASM_GLOBAL_FUNC( alloc_fs_sel,
 #define RSP_sig(context)    (*((unsigned long*)&(context)->uc_mcontext.__gregs[_REG_URSP]))
 #define TRAP_sig(context)   ((context)->uc_mcontext.__gregs[_REG_TRAPNO])
 #define ERROR_sig(context)  ((context)->uc_mcontext.__gregs[_REG_ERR])
-#define FPU_sig(context)    ((XMM_SAVE_AREA32 *)((context)->uc_mcontext.__fpregs))
+#define FPU_sig(context)    ((XMM_SAVE_AREA32 *)(&(context)->uc_mcontext.__fpregs))
 #define XState_sig(context) NULL
 
 #elif defined (__APPLE__)
@@ -316,8 +316,13 @@ enum i386_trap_code
     TRAP_x86_PAGEFLT    = T_PAGEFLT,    /* Page fault */
     TRAP_x86_ARITHTRAP  = T_ARITHTRAP,  /* Floating point exception */
     TRAP_x86_ALIGNFLT   = T_ALIGNFLT,   /* Alignment check exception */
+#if defined(__NetBSD__)
+    TRAP_x86_MCHK       = T_MCA,        /* Machine check exception */
+    TRAP_x86_CACHEFLT   = T_XMM         /* Cache flush exception */
+#else
     TRAP_x86_MCHK       = T_MCHK,       /* Machine check exception */
     TRAP_x86_CACHEFLT   = T_XMMFLT      /* Cache flush exception */
+#endif
 #else
     TRAP_x86_DIVIDE     = 0,   /* Division by zero exception */
     TRAP_x86_TRCTRAP    = 1,   /* Single-step exception */
