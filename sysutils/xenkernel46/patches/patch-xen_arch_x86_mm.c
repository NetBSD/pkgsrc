$NetBSD: patch-xen_arch_x86_mm.c,v 1.1 2017/02/14 21:38:34 joerg Exp $

From e0a97098e20d8fe334b76b37dd6fb0a358a6953c.

--- xen/arch/x86/mm.c.orig	2017-02-10 22:44:48.124078150 +0000
+++ xen/arch/x86/mm.c
@@ -517,7 +517,7 @@ void update_cr3(struct vcpu *v)
     make_cr3(v, cr3_mfn);
 }
 
-static const char __section(".bss.page_aligned") zero_page[PAGE_SIZE];
+static const char __section(".bss.page_aligned.const") zero_page[PAGE_SIZE];
 
 static void invalidate_shadow_ldt(struct vcpu *v, int flush)
 {
