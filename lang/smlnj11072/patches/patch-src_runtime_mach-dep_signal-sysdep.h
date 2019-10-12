$NetBSD: patch-src_runtime_mach-dep_signal-sysdep.h,v 1.1 2019/10/12 20:00:06 he Exp $

Support NetBSD and modernize the NetBSD ppc entry.

--- src/runtime/mach-dep/signal-sysdep.h.orig	2010-02-03 16:40:32.000000000 +0000
+++ src/runtime/mach-dep/signal-sysdep.h
@@ -175,7 +175,7 @@ extern void SetFSR(int);
   /* disable all FP exceptions */
 #  define SIG_InitFPE()    SetFSR(0)
 
-#  if defined(OPSYS_SUNOS)
+#  if defined(OPSYS_SUNOS) || defined(OPSYS_NETBSD)
     /** SPARC, SUNOS **/
 #    define USE_ZERO_LIMIT_PTR_FN
 #    define SIG_FAULT1		SIGFPE
@@ -344,6 +344,22 @@ extern void SetFSR();
 #    define SIG_ResetFPE(scp)           { (scp)->regs->gpr[PT_FPSCR] = 0x0; }
      typedef void SigReturn_t;
 
+#  elif (defined(TARGET_PPC) && defined(OPSYS_NETBSD))
+    /* PPC, NetBSD */
+
+#    define SIG_FAULT1          SIGTRAP
+
+#    define INT_DIVZERO(s, c)           ((s) == SIGTRAP)
+#    define INT_OVFLW(s, c)             ((s) == SIGTRAP)
+#    define SIG_GetPC(scp)              _UC_MACHINE_PC((scp))
+#    define SIG_SetPC(scp, addr)        { \
+	_UC_MACHINE_SET_PC((scp), (intptr_t)(addr)); }
+#    define SIG_ZeroLimitPtr(scp)       { \
+	(scp)->uc_mcontext.__gregs[_REG_R15] = 0; \
+	} /* limitptr = 15 (see src/runtime/mach-dep/PPC.prim.asm) */
+#    define SIG_GetCode(info,scp)       ((info)->si_code)
+     typedef void SigReturn_t;
+
 #  endif /* HOST_RS6000/HOST_PPC */
 
 #elif defined(HOST_HPPA)
