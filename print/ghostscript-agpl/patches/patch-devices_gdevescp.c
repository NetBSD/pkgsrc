$NetBSD: patch-devices_gdevescp.c,v 1.1 2024/08/06 18:27:23 tnn Exp $

gp_fwrite is clearly intended here, prn_stream is not FILE*

--- devices/gdevescp.c.orig	2024-08-06 17:49:28.646255812 +0000
+++ devices/gdevescp.c
@@ -162,7 +162,7 @@ escp2_print_page(gx_device_printer *pdev
         ** margin measured from the *top* of the page:
         */
 
-        fwrite("\033(U\001\0\n\033(C\002\0t\020\033(c\004\0\0\0t\020",
+        gp_fwrite("\033(U\001\0\n\033(C\002\0t\020\033(c\004\0\0\0t\020",
                                                         1, 22, prn_stream);
 #endif
 
