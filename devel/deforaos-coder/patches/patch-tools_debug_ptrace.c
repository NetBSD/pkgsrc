$NetBSD: patch-tools_debug_ptrace.c,v 1.1 2016/03/14 23:42:47 tnn Exp $

fix struct reg usage according to /usr/include/i386/reg.h

--- tools/debug/ptrace.c.orig	2016-02-20 01:27:00.000000000 +0000
+++ tools/debug/ptrace.c
@@ -329,15 +329,15 @@ static void _ptrace_get_registers(Ptrace
 	helper->set_register(helper->debugger, "rbp", regs.regs[_REG_RBP]);
 	helper->set_register(helper->debugger, "rip", regs.regs[_REG_RIP]);
 # elif defined(__i386__)
-	helper->set_register(helper->debugger, "eax", regs.regs[_REG_EAX]);
-	helper->set_register(helper->debugger, "ecx", regs.regs[_REG_ECX]);
-	helper->set_register(helper->debugger, "edx", regs.regs[_REG_EDX]);
-	helper->set_register(helper->debugger, "ebx", regs.regs[_REG_EBX]);
-	helper->set_register(helper->debugger, "esi", regs.regs[_REG_ESI]);
-	helper->set_register(helper->debugger, "edi", regs.regs[_REG_EDI]);
-	helper->set_register(helper->debugger, "esp", regs.regs[_REG_ESP]);
-	helper->set_register(helper->debugger, "ebp", regs.regs[_REG_EBP]);
-	helper->set_register(helper->debugger, "eip", regs.regs[_REG_EIP]);
+	helper->set_register(helper->debugger, "eax", regs.r_eax);
+	helper->set_register(helper->debugger, "ecx", regs.r_ecx);
+	helper->set_register(helper->debugger, "edx", regs.r_edx);
+	helper->set_register(helper->debugger, "ebx", regs.r_ebx);
+	helper->set_register(helper->debugger, "esi", regs.r_esi);
+	helper->set_register(helper->debugger, "edi", regs.r_edi);
+	helper->set_register(helper->debugger, "esp", regs.r_esp);
+	helper->set_register(helper->debugger, "ebp", regs.r_ebp);
+	helper->set_register(helper->debugger, "eip", regs.r_eip);
 # endif
 #endif
 }
