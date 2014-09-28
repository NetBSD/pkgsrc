$NetBSD: patch-xen_arch_x86_mm_shadow_common.c,v 1.1.2.2 2014/09/28 13:28:58 tron Exp $

patch for XSA-104/CVE-2014-7154, from Xen Security Advisory

--- xen/arch/x86/mm/shadow/common.c.orig	2014-09-02 08:22:57.000000000 +0200
+++ xen/arch/x86/mm/shadow/common.c	2014-09-26 11:18:02.000000000 +0200
@@ -3601,7 +3601,7 @@
     int flush_tlb = 0;
     unsigned long i;
     p2m_type_t t;
-    struct sh_dirty_vram *dirty_vram = d->arch.hvm_domain.dirty_vram;
+    struct sh_dirty_vram *dirty_vram;
     struct p2m_domain *p2m = p2m_get_hostp2m(d);
 
     if ( end_pfn < begin_pfn || end_pfn > p2m->max_mapped_pfn + 1 )
@@ -3611,6 +3611,8 @@
     p2m_lock(p2m_get_hostp2m(d));
     paging_lock(d);
 
+    dirty_vram = d->arch.hvm_domain.dirty_vram;
+
     if ( dirty_vram && (!nr ||
              ( begin_pfn != dirty_vram->begin_pfn
             || end_pfn   != dirty_vram->end_pfn )) )
