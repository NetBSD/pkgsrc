$NetBSD: patch-xen_arch_x86_mm.c,v 1.1 2019/08/30 13:23:09 bouyer Exp $
remove assert, which fires when freeing a page table page

--- xen/arch/x86/mm.c.orig	2019-08-30 12:51:48.000000000 +0200
+++ xen/arch/x86/mm.c	2019-08-30 12:52:21.000000000 +0200
@@ -2590,7 +2590,7 @@
         rc = 0;
         break;
     case PGT_l2_page_table:
-        ASSERT(preemptible);
+        // ASSERT(preemptible);
         rc = free_l2_table(page);
         break;
     case PGT_l3_page_table:
