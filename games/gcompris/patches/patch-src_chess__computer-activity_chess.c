$NetBSD: patch-src_chess__computer-activity_chess.c,v 1.1 2012/04/08 21:07:06 wiz Exp $

--- src/chess_computer-activity/chess.c.orig	2012-01-02 20:31:05.000000000 +0000
+++ src/chess_computer-activity/chess.c
@@ -1150,7 +1150,7 @@ engine_local_cb (GIOChannel *source,
     g_warning("engine_local_cb line=%s\n", pbuf);
 
     /* parse for  NUMBER ... MOVE */
-    if (isdigit (*pbuf))
+    if (isdigit ((unsigned char)*pbuf))
       {
 	if ((p = strstr (pbuf, "...")) && (strlen(p) == 4) )
 	  {
