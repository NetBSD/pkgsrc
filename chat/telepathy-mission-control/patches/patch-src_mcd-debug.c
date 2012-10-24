$NetBSD: patch-src_mcd-debug.c,v 1.1 2012/10/24 15:39:21 joerg Exp $

--- src/mcd-debug.c.orig	2012-10-24 13:23:51.000000000 +0000
+++ src/mcd-debug.c
@@ -119,7 +119,7 @@ void mcd_debug_init ()
 	mc_debug = atoi (mc_debug_str);
 }
 
-inline gint mcd_debug_get_level ()
+gint mcd_debug_get_level ()
 {
     return mc_debug;
 }
