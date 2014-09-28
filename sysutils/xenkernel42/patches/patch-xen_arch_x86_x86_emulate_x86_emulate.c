$NetBSD: patch-xen_arch_x86_x86_emulate_x86_emulate.c,v 1.1.2.2 2014/09/28 13:28:58 tron Exp $

patch for XSA-105/CVE-2014-7155 and XSA-106/CVE-2014-7156,
from Xen Security Advisory

--- xen/arch/x86/x86_emulate/x86_emulate.c.orig	2014-09-26 11:53:50.000000000 +0200
+++ xen/arch/x86/x86_emulate/x86_emulate.c	2014-09-26 11:53:43.000000000 +0200
@@ -2616,6 +2616,7 @@
     case 0xcd: /* int imm8 */
         src.val = insn_fetch_type(uint8_t);
     swint:
+        fail_if(!in_realmode(ctxt, ops)); /* XSA-106 */
         fail_if(ops->inject_sw_interrupt == NULL);
         rc = ops->inject_sw_interrupt(src.val, _regs.eip - ctxt->regs->eip,
                                       ctxt) ? : X86EMUL_EXCEPTION;
@@ -3296,6 +3297,7 @@
         goto swint;
 
     case 0xf4: /* hlt */
+        generate_exception_if(!mode_ring0(), EXC_GP, 0);
         ctxt->retire.flags.hlt = 1;
         break;
 
@@ -3721,6 +3723,7 @@
             break;
         case 2: /* lgdt */
         case 3: /* lidt */
+            generate_exception_if(!mode_ring0(), EXC_GP, 0);
             generate_exception_if(ea.type != OP_MEM, EXC_UD, -1);
             fail_if(ops->write_segment == NULL);
             memset(&reg, 0, sizeof(reg));
@@ -3749,6 +3752,7 @@
         case 6: /* lmsw */
             fail_if(ops->read_cr == NULL);
             fail_if(ops->write_cr == NULL);
+            generate_exception_if(!mode_ring0(), EXC_GP, 0);
             if ( (rc = ops->read_cr(0, &cr0, ctxt)) )
                 goto done;
             if ( ea.type == OP_REG )
