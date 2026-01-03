$NetBSD: patch-contrib-gdevlx32.c,v 1.1 2026/01/03 03:50:17 dholland Exp $

Need some explicit upcasts for the struct inheritance scheme
they're using. Fixes build with gcc14.

--- contrib/gdevlx32.c~	2012-08-08 08:01:36.000000000 +0000
+++ contrib/gdevlx32.c
@@ -742,7 +742,7 @@ lxm3200_print_page(gx_device_printer *pd
         if(gendata.scanbuf == NULL ||
                  gendata.outdata == NULL)
         {
-                freeresources(pdev);
+                freeresources((gx_device *)pdev);
                 return_error(gs_error_VMerror);
         }
 
@@ -773,7 +773,7 @@ lxm3200_print_page(gx_device_printer *pd
         outputepilogue();
 
         /* Free the allocated resources */
-        freeresources(pdev);
+        freeresources((gx_device *)pdev);
 
         /* Done. Bye bye, see you on next page. */
         return(0);
