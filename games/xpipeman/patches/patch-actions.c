$NetBSD: patch-actions.c,v 1.1 2012/01/20 17:06:52 joerg Exp $

--- actions.c.orig	2012-01-20 13:52:23.000000000 +0000
+++ actions.c
@@ -65,7 +65,7 @@ move_here_action(w,event,params,num_para
   /* called to move a block to a specific place - does NOT place it */
   int tmp_block_x, tmp_block_y;
 
-  if((!game_active) || buttons_disabled) return;
+  if((!game_active) || buttons_disabled) return 0;
 
   tmp_block_x = coord_to_pos(event->x);
   tmp_block_y = coord_to_pos(event->y);
@@ -84,6 +84,7 @@ move_here_action(w,event,params,num_para
       show_movement();
     }
   XFlush(display);
+  return 0;
 }
 
 /*----------------------------------------------------------------------*/
@@ -107,8 +108,9 @@ fast_flow_action(w,event,params,num_para
   String *params;
   Cardinal *num_params;
 {
-  if((!game_active) || buttons_disabled) return;
+  if((!game_active) || buttons_disabled) return 0;
    speed_up_flow(); 
+  return 0;
 }
 
 /*----------------------------------------------------------------------*/
@@ -131,7 +133,7 @@ move_action(w,event,params,num_params)
 
   tmp_num_params= *num_params;
 
-  if((!game_active) || buttons_disabled) return;
+  if((!game_active) || buttons_disabled) return 0;
 
   while((tmp_num_params)--) {
 
@@ -156,6 +158,7 @@ move_action(w,event,params,num_params)
     show_movement();
   }
   XFlush(display);
+  return 0;
 }
 
 
@@ -173,8 +176,9 @@ place_action(w,event,params,num_params)
  */
   int diff_x, diff_y;
 
-  if((!game_active) || buttons_disabled) return;
+  if((!game_active) || buttons_disabled) return 0;
   if (!place_block()) XBell(XtDisplay(w),100);
+  return 0;
 }
 
 
@@ -186,6 +190,6 @@ pointer_moved(w, closure, event)
   XPointerMovedEvent *event;
 {
   if(game_active) ;
-
+  return 0;
 }
 
