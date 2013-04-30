$NetBSD: patch-main.h,v 1.1 2013/04/30 22:20:58 joerg Exp $

--- main.h.orig	2013-04-30 20:07:34.000000000 +0000
+++ main.h
@@ -16,7 +16,7 @@ position last_pos;                      
 
 
 
-move game_history[600];                 // game move history
+my_move game_history[600];                 // game move history
 
 h_code p_list[600];                     // game position list
 
@@ -36,9 +36,9 @@ int both = 0;                           
 
 
 
-move best;                              // best move - will be made
+my_move best;                              // best move - will be made
 
-extern move pc[MAXD+1][MAXD+1];         // principle continuation
+extern my_move pc[MAXD+1][MAXD+1];         // principle continuation
 
 
 
