$NetBSD: patch-src_cmd3.c,v 1.2 2020/03/11 15:01:54 pho Exp $

Fix an error on 64-bits platforms.

--- src/cmd3.c.orig	2020-03-11 14:36:27.328921818 +0000
+++ src/cmd3.c
@@ -53,7 +53,7 @@ void do_cmd_inven(void)
 #else
 	sprintf(out_val, "Inventory: carrying %d.%d pounds (%ld%% of capacity). Command: ",
 	    (int)(p_ptr->total_weight / 10), (int)(p_ptr->total_weight % 10),
-	    (p_ptr->total_weight * 100) / weight_limit());
+	    (long int)((p_ptr->total_weight * 100) / weight_limit()));
 #endif
 
 
