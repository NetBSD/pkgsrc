$NetBSD: patch-libcx_xc__dom__boot.c,v 1.1.2.2 2013/04/24 21:11:06 tron Exp $

--- libxc/xc_dom_boot.c.orig	2013-03-25 10:12:30.000000000 +0000
+++ libxc/xc_dom_boot.c
@@ -265,7 +265,7 @@ int xc_dom_boot_image(struct xc_dom_imag
         return rc;
 
     /* let the vm run */
-    memset(ctxt, 0, sizeof(ctxt));
+    memset(ctxt, 0, sizeof(*ctxt));
     if ( (rc = dom->arch_hooks->vcpu(dom, ctxt)) != 0 )
         return rc;
     xc_dom_unmap_all(dom);
