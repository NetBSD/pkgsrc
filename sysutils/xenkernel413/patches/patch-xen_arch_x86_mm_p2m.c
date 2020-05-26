$NetBSD: patch-xen_arch_x86_mm_p2m.c,v 1.1 2020/05/26 11:12:10 bouyer Exp $

silent a noisy warning

--- xen/arch/x86/mm/p2m.c.orig	2020-05-03 21:13:56.173269058 +0200
+++ xen/arch/x86/mm/p2m.c	2020-05-03 21:15:38.477174874 +0200
@@ -1367,10 +1367,13 @@
             ret = 0;
         else
             ret = -EBUSY;
-        printk(XENLOG_G_WARNING
+
+	if (gfn_l != mfn_x(mfn)) {
+            printk(XENLOG_G_WARNING
                "Cannot setup identity map d%d:%lx,"
                " gfn already mapped to %lx.\n",
                d->domain_id, gfn_l, mfn_x(mfn));
+	}
     }
 
     gfn_unlock(p2m, gfn, 0);
