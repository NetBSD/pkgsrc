$NetBSD: patch-mono_utils_mono-sigcontext.h,v 1.1 2017/01/10 10:35:28 he Exp $

--- mono/utils/mono-sigcontext.h.orig	2015-08-25 20:33:40.000000000 +0000
+++ mono/utils/mono-sigcontext.h
@@ -201,6 +201,10 @@ typedef struct ucontext {
 	#define UCONTEXT_REG_RSI(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs [_REG_RSI])
 	#define UCONTEXT_REG_RDI(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs [_REG_RDI])
 	#define UCONTEXT_REG_RIP(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs [_REG_RIP])
+	#define UCONTEXT_REG_R8(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs [_REG_R8])
+	#define UCONTEXT_REG_R9(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs [_REG_R9])
+	#define UCONTEXT_REG_R10(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs [_REG_R10])
+	#define UCONTEXT_REG_R11(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs [_REG_R11])
 	#define UCONTEXT_REG_R12(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs [_REG_R12])
 	#define UCONTEXT_REG_R13(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs [_REG_R13])
 	#define UCONTEXT_REG_R14(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs [_REG_R14])
@@ -287,9 +291,9 @@ typedef struct ucontext {
 
 	#define UCONTEXT_REG_Rn(ctx, n)   (((os_ucontext*)(ctx))->uc_mcontext.__gregs [(n)])
 	#define UCONTEXT_REG_FPRn(ctx, n) (((os_ucontext*)(ctx))->uc_mcontext.__fpregs.__fpu_regs [(n)])
-	#define UCONTEXT_REG_NIP(ctx)     _UC_MACHINE_PC(ctx)
+	#define UCONTEXT_REG_NIP(ctx)     _UC_MACHINE_PC((os_ucontext*)(ctx))
 	#define UCONTEXT_REG_LNK(ctx)     (((os_ucontext*)(ctx))->uc_mcontext.__gregs [_REG_LR])
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 	typedef ucontext_t os_ucontext;
 
 	#define UCONTEXT_REG_Rn(ctx, n)   ((ctx)->uc_mcontext.mc_gpr [(n)])
@@ -351,6 +355,27 @@ typedef struct ucontext {
 	#define UCONTEXT_REG_R11(ctx) (((arm_ucontext*)(ctx))->sig_ctx.arm_fp)
 	#define UCONTEXT_REG_R12(ctx) (((arm_ucontext*)(ctx))->sig_ctx.arm_ip)
 	#define UCONTEXT_REG_CPSR(ctx) (((arm_ucontext*)(ctx))->sig_ctx.arm_cpsr)
+#elif defined(__NetBSD__)
+	typedef ucontext_t arm_ucontext;
+
+	#define UCONTEXT_REG_PC(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_PC])
+	#define UCONTEXT_REG_SP(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_SP])
+	#define UCONTEXT_REG_LR(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_LR])
+	#define UCONTEXT_REG_R0(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R0])
+	#define UCONTEXT_REG_R1(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R1])
+	#define UCONTEXT_REG_R2(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R2])
+	#define UCONTEXT_REG_R3(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R3])
+	#define UCONTEXT_REG_R4(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R4])
+	#define UCONTEXT_REG_R5(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R5])
+	#define UCONTEXT_REG_R6(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R6])
+	#define UCONTEXT_REG_R7(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R7])
+	#define UCONTEXT_REG_R8(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R8])
+	#define UCONTEXT_REG_R9(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R9])
+	#define UCONTEXT_REG_R10(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R10])
+	#define UCONTEXT_REG_R11(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R11])
+	#define UCONTEXT_REG_R12(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_R12])
+	#define UCONTEXT_REG_CPSR(ctx) (((ucontext_t*)(ctx))->uc_mcontext.__gregs[_REG_CPSR])
+	#define UCONTEXT_REG_VFPREGS(ctx) (double*)(&((ucontext_t*)(ctx))->uc_mcontext.__fpu)
 #endif
 
 #elif defined(TARGET_ARM64)
