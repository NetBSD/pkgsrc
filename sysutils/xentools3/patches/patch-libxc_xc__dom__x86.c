$NetBSD: patch-libxc_xc__dom__x86.c,v 1.1 2013/04/11 19:57:52 joerg Exp $

--- libxc/xc_dom_x86.c.orig	2013-03-25 20:08:33.000000000 +0000
+++ libxc/xc_dom_x86.c
@@ -418,7 +418,7 @@ static int start_info_x86_32(struct xc_d
     xc_dom_printf("%s: called\n", __FUNCTION__);
 
     memset(start_info, 0, sizeof(*start_info));
-    sprintf(start_info->magic, dom->guest_type);
+    snprintf(start_info->magic, sizeof(start_info->magic), "%s", dom->guest_type);
     start_info->nr_pages = dom->total_pages;
     start_info->shared_info = shinfo << PAGE_SHIFT_X86;
     start_info->pt_base = dom->pgtables_seg.vstart;
@@ -457,7 +457,7 @@ static int start_info_x86_64(struct xc_d
     xc_dom_printf("%s: called\n", __FUNCTION__);
 
     memset(start_info, 0, sizeof(*start_info));
-    sprintf(start_info->magic, dom->guest_type);
+    snprintf(start_info->magic, sizeof(start_info->magic), "%s", dom->guest_type);
     start_info->nr_pages = dom->total_pages;
     start_info->shared_info = shinfo << PAGE_SHIFT_X86;
     start_info->pt_base = dom->pgtables_seg.vstart;
