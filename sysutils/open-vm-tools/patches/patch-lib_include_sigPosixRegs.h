$NetBSD: patch-lib_include_sigPosixRegs.h,v 1.3 2024/04/09 01:12:36 pho Exp $

Support NetBSD/i386, NetBSD/amd64, and NetBSD/aarch64.

--- lib/include/sigPosixRegs.h.orig	2024-02-06 15:08:43.000000000 +0000
+++ lib/include/sigPosixRegs.h
@@ -233,6 +233,38 @@ extern "C" {
 #define SC_ESP(uc) ((unsigned long) (uc)->uc_mcontext.gregs[ESP])
 #define SC_EIP(uc) ((unsigned long) (uc)->uc_mcontext.gregs[EIP])
 #endif
+#elif defined (__NetBSD__)
+#if defined(__x86_64__)
+#define SC_EAX(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_RAX])
+#define SC_EBX(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_RBX])
+#define SC_ECX(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_RCX])
+#define SC_EDX(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_RDX])
+#define SC_EDI(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_RDI])
+#define SC_ESI(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_RSI])
+#define SC_EBP(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_RBP])
+#define SC_ESP(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_RSP])
+#define SC_EIP(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_RIP])
+#define SC_R8(uc)  ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_R8])
+#define SC_R9(uc)  ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_R9])
+#define SC_R10(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_R10])
+#define SC_R11(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_R11])
+#define SC_R12(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_R12])
+#define SC_R13(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_R13])
+#define SC_R14(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_R14])
+#define SC_R15(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_R15])
+#elif defined(__aarch64__)
+#define SC_X(uc,n) ((unsigned long) (uc)->uc_mcontext.__gregs[n])
+#else
+#define SC_EAX(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_EAX])
+#define SC_EBX(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_EBX])
+#define SC_ECX(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_ECX])
+#define SC_EDX(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_EDX])
+#define SC_EDI(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_EDI])
+#define SC_ESI(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_ESI])
+#define SC_EBP(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_EBP])
+#define SC_ESP(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_ESP])
+#define SC_EIP(uc) ((unsigned long) (uc)->uc_mcontext.__gregs[_REG_EIP])
+#endif
 #elif defined(ANDROID_X86)
 #define SC_EAX(uc) ((unsigned long) (uc)->uc_mcontext.gregs[REG_EAX])
 #define SC_EBX(uc) ((unsigned long) (uc)->uc_mcontext.gregs[REG_EBX])
