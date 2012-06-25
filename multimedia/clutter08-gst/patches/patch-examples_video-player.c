$NetBSD: patch-examples_video-player.c,v 1.1 2012/06/25 11:52:46 joerg Exp $

--- examples/video-player.c.orig	2012-06-18 16:44:11.000000000 +0000
+++ examples/video-player.c
@@ -139,7 +139,7 @@ input_cb (ClutterStage *stage, 
 	  if (actor == app->control_pause || actor == app->control_play)
 	    {
 	      toggle_pause_state (app);
-	      return;
+	      return FALSE;
 	    }
 
 	  if (actor == app->control_seek1 
