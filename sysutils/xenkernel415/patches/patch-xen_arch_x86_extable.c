$NetBSD: patch-xen_arch_x86_extable.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

silent nosy debug output

--- xen/arch/x86/extable.c.orig	2020-12-08 18:32:35.707855990 +0100
+++ xen/arch/x86/extable.c	2020-12-08 18:32:05.786712864 +0100
@@ -199,7 +199,7 @@
         __start___pre_ex_table, __stop___pre_ex_table-1, addr);
     if ( fixup )
     {
-        dprintk(XENLOG_INFO, "Pre-exception: %p -> %p\n", _p(addr), _p(fixup));
+        // dprintk(XENLOG_INFO, "Pre-exception: %p -> %p\n", _p(addr), _p(fixup));
         perfc_incr(exception_fixed);
     }
     return fixup;
