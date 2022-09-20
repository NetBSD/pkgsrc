$NetBSD: patch-mono_utils_mono-sigcontext.h,v 1.3 2022/09/20 15:59:33 he Exp $

NetBSD/aarch64 support.
Fix NetBSD/powerpc support.

--- mono/utils/mono-sigcontext.h.orig	2019-09-19 07:46:07.000000000 +0000
+++ mono/utils/mono-sigcontext.h
@@ -356,8 +356,8 @@ typedef struct ucontext {
 
 	#define UCONTEXT_REG_Rn(ctx, n)   (((os_ucontext*)(ctx))->uc_mcontext.__gregs [(n)])
 	#define UCONTEXT_REG_FPRn(ctx, n) (((os_ucontext*)(ctx))->uc_mcontext.__fpregs.__fpu_regs [(n)])
-	#define UCONTEXT_REG_NIP(ctx)     _UC_MACHINE_PC(ctx)
-	#define UCONTEXT_REG_LNK(ctx)     (((os_ucontext*)(ctx))->uc_mcontext.__gregs [_REG_LR])
+	#define UCONTEXT_REG_NIP(ctx)     _UC_MACHINE_PC((os_ucontext*)(ctx))
+	#define UCONTEXT_REG_LNK(ctx)     UCONTEXT_REG_Rn(ctx, _REG_LR)
 #elif defined(__FreeBSD__)
 	typedef ucontext_t os_ucontext;
 
@@ -472,6 +472,12 @@ typedef struct ucontext {
 	#define UCONTEXT_REG_SP(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_gpregs.gp_sp)
 	#define UCONTEXT_REG_R0(ctx) (((ucontext_t*)(ctx))->uc_mcontext.mc_gpregs.gp_x [ARMREG_R0])
 	#define UCONTEXT_GREGS(ctx) (&(((ucontext_t*)(ctx))->uc_mcontext.mc_gpregs.gp_x))
+#elif defined(__NetBSD__)
+#include <ucontext.h>
+	#define UCONTEXT_REG_PC(ctx) _UC_MACHINE_PC((ucontext_t*)(ctx))
+	#define UCONTEXT_REG_SP(ctx) _UC_MACHINE_SP((ucontext_t*)(ctx))
+	#define UCONTEXT_REG_R0(ctx) _UC_MACHINE_INTRV((ucontext_t*)(ctx))
+	#define UCONTEXT_GREGS(ctx) (&(((ucontext_t*)(ctx))->uc_mcontext.__gregs))
 #else
 #include <ucontext.h>
 	#define UCONTEXT_REG_PC(ctx) (((ucontext_t*)(ctx))->uc_mcontext.pc)
