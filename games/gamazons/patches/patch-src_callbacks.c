$NetBSD: patch-src_callbacks.c,v 1.1 2013/03/02 18:11:33 joerg Exp $

--- src/callbacks.c.orig	2013-03-01 12:27:35.000000000 +0000
+++ src/callbacks.c
@@ -359,17 +359,17 @@ int board_press_cb (GnomeCanvasItem *ite
    if (bstate_get_moving_piece())
      {
       //printf("Can't do that while a piece is moving\n");
-      return;
+      return 0;
      }
    if (bstate_get_open_dialog())
      {
       //printf("Can't do that while another window is open\n");
-      return;
+      return 0;
      }
    if (bstate_get_what_next() == NEW_GAME)
      {
       //printf("Can't do that while I'm expecting a new game to start\n");
-      return;
+      return 0;
      }
    if (bstate_get_replay_mode())
       return 0;
