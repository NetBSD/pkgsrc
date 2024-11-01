$NetBSD: patch-dlls_ntdll_unix_signal__x86__64.c,v 1.1 2024/11/01 14:10:47 triaxx Exp $

Fix signal definition for NetBSD.

--- dlls/ntdll/unix/signal_x86_64.c.orig	2024-01-16 20:55:47.000000000 +0000
+++ dlls/ntdll/unix/signal_x86_64.c
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
