$NetBSD: patch-user-exec.c,v 1.2 2013/07/09 17:00:58 tsutsui Exp $

Add OS dependent code for NetBSD/arm.

--- user-exec.c.orig	2013-06-26 21:47:30.000000000 +0000
+++ user-exec.c
@@ -428,19 +428,31 @@ int cpu_signal_handler(int host_signum, 
 
 #elif defined(__arm__)
 
+#if defined(__NetBSD__)
+#include <ucontext.h>
+#endif
+
 int cpu_signal_handler(int host_signum, void *pinfo,
                        void *puc)
 {
     siginfo_t *info = pinfo;
+#if defined(__NetBSD__)
+    ucontext_t *uc = puc;
+#else
     struct ucontext *uc = puc;
+#endif
     unsigned long pc;
     int is_write;
 
+#if defined(__NetBSD__)
+    pc = uc->uc_mcontext.__gregs[_REG_R15];
+#else
 #if defined(__GLIBC__) && (__GLIBC__ < 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ <= 3))
     pc = uc->uc_mcontext.gregs[R15];
 #else
     pc = uc->uc_mcontext.arm_pc;
 #endif
+#endif
     /* XXX: compute is_write */
     is_write = 0;
     return handle_cpu_signal(pc, (unsigned long)info->si_addr,
