$NetBSD: patch-thirdparty_cpustate.c,v 1.1 2025/12/28 05:42:55 ryoon Exp $

* Support NetBSD/amd64.

--- thirdparty/cpustate.c.orig	2025-12-24 09:15:22.124726860 +0000
+++ thirdparty/cpustate.c
@@ -154,6 +154,26 @@ void fill_cpu_state(struct cpu_state *cp
    cpu->regs[13] = uc->sc_r13;
    cpu->regs[14] = uc->sc_r14;
    cpu->regs[15] = uc->sc_r15;
+#elif defined __NetBSD__ && defined __x86_64__
+   cpu->pc = uc->uc_mcontext.__gregs[_REG_RIP];
+   cpu->sp = uc->uc_mcontext.__gregs[_REG_RSP];
+
+   cpu->regs[0]  = uc->uc_mcontext.__gregs[_REG_RAX];
+   cpu->regs[1]  = uc->uc_mcontext.__gregs[_REG_RCX];
+   cpu->regs[2]  = uc->uc_mcontext.__gregs[_REG_RDX];
+   cpu->regs[3]  = uc->uc_mcontext.__gregs[_REG_RBX];
+   cpu->regs[4]  = uc->uc_mcontext.__gregs[_REG_RSP];
+   cpu->regs[5]  = uc->uc_mcontext.__gregs[_REG_RBP];
+   cpu->regs[6]  = uc->uc_mcontext.__gregs[_REG_RSI];
+   cpu->regs[7]  = uc->uc_mcontext.__gregs[_REG_RDI];
+   cpu->regs[8]  = uc->uc_mcontext.__gregs[_REG_R8];
+   cpu->regs[9]  = uc->uc_mcontext.__gregs[_REG_R9];
+   cpu->regs[10] = uc->uc_mcontext.__gregs[_REG_R10];
+   cpu->regs[11] = uc->uc_mcontext.__gregs[_REG_R11];
+   cpu->regs[12] = uc->uc_mcontext.__gregs[_REG_R12];
+   cpu->regs[13] = uc->uc_mcontext.__gregs[_REG_R13];
+   cpu->regs[14] = uc->uc_mcontext.__gregs[_REG_R14];
+   cpu->regs[15] = uc->uc_mcontext.__gregs[_REG_R15];
 #elif defined __APPLE__ && defined __arm64__
    cpu->pc = uc->uc_mcontext->__ss.__pc;
    cpu->sp = uc->uc_mcontext->__ss.__sp;
