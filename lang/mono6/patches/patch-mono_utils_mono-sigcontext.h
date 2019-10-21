$NetBSD: patch-mono_utils_mono-sigcontext.h,v 1.1 2019/10/21 23:53:34 maya Exp $

NetBSD/aarch64 support.

--- mono/utils/mono-sigcontext.h.orig	2019-09-19 07:46:07.000000000 +0000
+++ mono/utils/mono-sigcontext.h
@@ -474,6 +474,12 @@ typedef struct ucontext {
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
