$NetBSD: patch-mono_utils_mono-sigcontext.h,v 1.4 2026/02/03 15:17:53 ryoon Exp $

NetBSD/aarch64 support.
Fix NetBSD/powerpc support.

--- mono/utils/mono-sigcontext.h.orig	2025-01-13 19:10:41.000000000 +0000
+++ mono/utils/mono-sigcontext.h
@@ -359,8 +359,8 @@ typedef struct ucontext {
 
 	#define UCONTEXT_REG_Rn(ctx, n)   (((os_ucontext*)(ctx))->uc_mcontext.__gregs [(n)])
 	#define UCONTEXT_REG_FPRn(ctx, n) (((os_ucontext*)(ctx))->uc_mcontext.__fpregs.__fpu_regs [(n)])
-	#define UCONTEXT_REG_NIP(ctx)     _UC_MACHINE_PC(ctx)
-	#define UCONTEXT_REG_LNK(ctx)     (((os_ucontext*)(ctx))->uc_mcontext.__gregs [_REG_LR])
+	#define UCONTEXT_REG_NIP(ctx)     _UC_MACHINE_PC((os_ucontext*)(ctx))
+	#define UCONTEXT_REG_LNK(ctx)     UCONTEXT_REG_Rn(ctx, _REG_LR)
 #elif defined(__FreeBSD__)
 	typedef ucontext_t os_ucontext;
 
@@ -486,6 +486,12 @@ typedef struct ucontext {
 	#define UCONTEXT_REG_SP(ctx) (((ucontext_t*)(ctx))->sc_sp)
 	#define UCONTEXT_REG_R0(ctx) (((ucontext_t*)(ctx))->sc_x [ARMREG_R0])
 	#define UCONTEXT_GREGS(ctx) (&(((ucontext_t*)(ctx))->sc_x))
+#elif defined(__NetBSD__)
+#include <ucontext.h>
+	#define UCONTEXT_REG_PC(ctx) _UC_MACHINE_PC((ucontext_t*)(ctx))
+	#define UCONTEXT_REG_SP(ctx) _UC_MACHINE_SP((ucontext_t*)(ctx))
+	#define UCONTEXT_REG_R0(ctx) _UC_MACHINE_INTRV((ucontext_t*)(ctx))
+	#define UCONTEXT_GREGS(ctx) (&(((ucontext_t*)(ctx))->uc_mcontext.__gregs))
 #elif !defined(HOST_WIN32)
 #include <ucontext.h>
 	#define UCONTEXT_REG_PC(ctx) (((ucontext_t*)(ctx))->uc_mcontext.pc)
