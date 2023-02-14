$NetBSD: patch-netbsd_trace.c,v 1.1 2023/02/14 15:45:58 he Exp $

Provide portability to powerpc.

--- netbsd/trace.c.orig	2020-07-22 21:04:55.000000000 +0000
+++ netbsd/trace.c
@@ -187,6 +187,8 @@ static size_t arch_getPC(
     *status_reg = r.regs[_REG_EFLAGS];
 #elif defined(__x86_64__)
     *status_reg = r.regs[_REG_RFLAGS];
+#elif defined(__powerpc__)
+    *status_reg = r.xer;
 #else
 #error unsupported CPU architecture
 #endif
@@ -225,6 +227,9 @@ static void arch_getInstrStr(pid_t pid, 
 #elif defined(__x86_64__)
     arch        = CS_ARCH_X86;
     mode        = CS_MODE_64;
+#elif defined(__powerpc__)
+    arch	= CS_ARCH_PPC;
+    mode	= CS_MODE_32;
 #else
 #error Unsupported CPU architecture
 #endif
