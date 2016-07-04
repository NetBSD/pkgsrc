$NetBSD: patch-xen_common_page__alloc.c,v 1.1.1.1 2016/07/04 07:25:13 jnemeth Exp $

--- xen/common/page_alloc.c.orig	2015-09-13 17:37:09.000000000 +0000
+++ xen/common/page_alloc.c
@@ -1561,7 +1561,7 @@ void *alloc_xenheap_pages(unsigned int o
     ASSERT(!in_irq());
 
     if ( xenheap_bits && (memflags >> _MEMF_bits) > xenheap_bits )
-        memflags &= ~MEMF_bits(~0);
+        memflags &= ~MEMF_bits(~0U);
     if ( !(memflags >> _MEMF_bits) )
         memflags |= MEMF_bits(xenheap_bits);
 
