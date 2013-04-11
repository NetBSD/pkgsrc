$NetBSD: patch-xen_arch_x86_hvm_io.c,v 1.1 2013/04/11 19:57:51 joerg Exp $

--- xen/arch/x86/hvm/io.c.orig	2013-03-25 12:44:51.000000000 +0000
+++ xen/arch/x86/hvm/io.c
@@ -338,7 +338,7 @@ static inline void set_eflags_OF(int siz
 
     if ( instr == INSTR_ADD )
     {
-        if ((src ^ result) & (dst ^ result) & mask);
+        if ((src ^ result) & (dst ^ result) & mask)
             regs->eflags |= X86_EFLAGS_OF;
     }
     else
