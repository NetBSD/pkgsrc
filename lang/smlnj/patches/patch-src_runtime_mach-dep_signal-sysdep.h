$NetBSD: patch-src_runtime_mach-dep_signal-sysdep.h,v 1.3 2024/12/09 14:07:09 ryoon Exp $

Support for NetBSD, and for NetBSD on PPC.

--- src/runtime/mach-dep/signal-sysdep.h.orig	2024-10-25 16:47:18.000000000 +0000
+++ src/runtime/mach-dep/signal-sysdep.h
@@ -172,7 +172,7 @@ extern void SetFSR(int);
   /* disable all FP exceptions */
 #  define SIG_InitFPE()    SetFSR(0)
 
-#  if defined(OPSYS_SOLARIS)
+#  if defined(OPSYS_SOLARIS) || defined(OPSYS_NETBSD)
     /** SPARC, SOLARIS **/
 #    define SIG_OVERFLOW        SIGFPE
 
@@ -251,6 +251,21 @@ extern void SetFSR(int);
 
     typedef void SigReturn_t;
 
+#  elif defined(OPSYS_NETBSD)
+   /** PPC, NetBSD **/
+
+#    define SIG_FAULT1          SIGTRAP
+
+#    define INT_DIVZERO(s, c)           ((s) == SIGTRAP)
+#    define INT_OVFLW(s, c)             ((s) == SIGTRAP)
+#    define SIG_GetPC(scp)             (_UC_MACHINE_PC(scp))
+#    define SIG_SetPC(scp, addr)       { _UC_MACHINE_SET_PC(scp, ((long) (addr))); }
+#    define SIG_ZeroLimitPtr(scp)       { \
+       (scp)->uc_mcontext.__gregs[_REG_R15] = 0; \
+       } /* limitptr = 15 (see src/runtime/mach-dep/PPC.prim.asm) */
+#    define SIG_GetCode(info,scp)       ((info)->si_code)
+     typedef void SigReturn_t;
+
 #  endif /* ARCH_PPC */
 
 #elif defined(ARCH_X86)
@@ -321,9 +336,9 @@ extern void SetFSR(int);
 #    define SIG_OVERFLOW                SIGFPE  /* maybe this should be SIGBUS? */
 
 #    define SIG_GetCode(info, scp)      (info)
-#    define SIG_GetPC(scp)              ((scp)->sc_pc)
-#    define SIG_SetPC(scp, addr)        { (scp)->sc_pc = (Addr_t)(addr); }
-#    define SIG_ZeroLimitPtr(scp)       { ML_X86Frame[LIMITPTR_X86OFFSET] = 0; }
+#    define SIG_GetPC(scp)              ((scp)->uc_mcontext.__gregs[_REG_RIP])
+#    define SIG_SetPC(scp, addr)         { (scp)->uc_mcontext.__gregs[_REG_RIP] = (Addr_t)(addr); }
+#    define SIG_ZeroLimitPtr(scp)       { (scp)->uc_mcontext.__gregs[_REG_R14] = 0; }
 
      typedef void SigReturn_t;
 
@@ -428,12 +443,10 @@ extern void SetFSR(int);
 #    define SIG_OVERFLOW                SIGFPE
 
 #    define SIG_GetCode(info, scp)      (info)
-#    define SIG_GetPC(scp)              ((uc)->uc_mcontext.__gregs[_REG_RIP])
-#    define SIG_SetPC(scp, addr)        { (uc)->uc_mcontext.__gregs[_REG_RIP] = (Addr_t)(addr); }
+#    define SIG_GetPC(scp)              ((scp)->uc_mcontext.__gregs[_REG_RIP])
+#    define SIG_SetPC(scp, addr)        { (scp)->uc_mcontext.__gregs[_REG_RIP] = (Addr_t)(addr); }
 #    define SIG_ZeroLimitPtr(scp)       { (scp)->uc_mcontext.__gregs[_REG_R14] = 0; }
 
-#    error NetBSD/AMD64 not supported yet
-
 #  elif defined(OPSYS_OPENBSD)
     /** amd64, OpenBSD **/
 #    define SIG_OVERFLOW                SIGFPE
