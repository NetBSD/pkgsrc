$NetBSD: patch-xen_arch_x86_extable.c,v 1.1 2023/11/21 11:38:26 bouyer Exp $

silent nosy debug output

--- xen/arch/x86/extable.c.orig	2023-10-06 19:17:42.000000000 +0200
+++ xen/arch/x86/extable.c	2023-10-10 16:20:56.285091628 +0200
@@ -202,7 +202,7 @@
         __start___pre_ex_table, __stop___pre_ex_table, addr);
     if ( fixup )
     {
-        dprintk(XENLOG_INFO, "Pre-exception: %p -> %p\n", _p(addr), _p(fixup));
+        // dprintk(XENLOG_INFO, "Pre-exception: %p -> %p\n", _p(addr), _p(fixup));
         perfc_incr(exception_fixed);
     }
     return fixup;
