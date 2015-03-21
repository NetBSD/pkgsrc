$NetBSD: patch-reboot.c,v 1.1 2015/03/21 02:18:39 tnn Exp $

--- lib.c.orig	2013-08-10 02:01:58.000000000 +0000
+++ lib.c
@@ -33,7 +33,7 @@ struct ascii_map_str {
         int keycode;
 };
 
-inline void reboot(void)
+void reboot(void)
 {
 	
 	/* tell the BIOS to do a cold start */
