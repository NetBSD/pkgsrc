$NetBSD: patch-user-exec.c,v 1.4 2014/01/15 18:26:20 wiz Exp $

Add OS dependent code for NetBSD/arm.

--- user-exec.c.orig	2013-11-27 22:15:55.000000000 +0000
+++ user-exec.c
@@ -434,19 +434,31 @@ int cpu_signal_handler(int host_signum, 
 
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
 
     /* error_code is the FSR value, in which bit 11 is WnR (assuming a v6 or
      * later processor; on v5 we will always report this as a read).
