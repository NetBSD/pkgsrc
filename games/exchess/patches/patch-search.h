$NetBSD: patch-search.h,v 1.1 2013/04/30 22:20:58 joerg Exp $

--- search.h.orig	2013-04-30 20:07:06.000000000 +0000
+++ search.h
@@ -25,7 +25,7 @@ int RAZOR_DEPTH = 192;
 position sp[MAXD];                  // array of search positions
 
 move_list slist[MAXD+1];            // array of search lists
-move pc[MAXD+1][MAXD+1];            // triangular array for search
+my_move pc[MAXD+1][MAXD+1];            // triangular array for search
                                     // principle continuation
 
 int max_ply;                        // max ply of current search
@@ -51,10 +51,10 @@ int g_last;                         // l
 
 int killer1[2], killer2[2], killer3[2]; // killer moves
 
-move nomove;                        // move for initization purposes   
-move hmove;                         // move from hash table
-move bookm;                         // move from opening book
-move ponder_move;                   // move we are pondering
+my_move nomove;                        // move for initization purposes   
+my_move hmove;                         // move from hash table
+my_move bookm;                         // move from opening book
+my_move ponder_move;                   // move we are pondering
 
 unsigned int history[64][64];      // table for history scores
 
