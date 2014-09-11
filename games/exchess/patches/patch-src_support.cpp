$NetBSD: patch-src_support.cpp,v 1.1 2014/09/11 16:59:16 jperkin Exp $

Avoid 'move' conflict.

--- src/support.cpp.orig	2014-08-17 11:03:08.000000000 +0000
+++ src/support.cpp
@@ -24,11 +24,11 @@
 // Function to parse a move from the human player
 // This move is checked then checked to see if it is legal
 //----------------------------------------------------------
-move position::parse_move(char mstring[10], ts_thread_data *temps)
+my_move position::parse_move(char mstring[10], ts_thread_data *temps)
 {
   int legal = 0, piece, to_sq = -1, from_sq = -1, promote = QUEEN;
   int from_file = -1, from_row = -1, match_count = 0;
-  move play, mplay[4], nomove; 
+  my_move play, mplay[4], nomove; 
   play.t = 0; nomove.t = 0;
   mplay[0].t = 0; mplay[1].t = 0; mplay[2].t = 0; mplay[3].t = 0;
   position t_pos;
@@ -200,7 +200,7 @@ move position::parse_move(char mstring[1
 // long algebraic format. This function works by simply 
 // adding the appropriate characters to the move string
 //----------------------------------------------------------
-void position::print_move(move pmove, char mstring[10], ts_thread_data *temps)
+void position::print_move(my_move pmove, char mstring[10], ts_thread_data *temps)
 {
   char dummy[10];             // dummy character string
   int ptype, pfrom, pto, ppiece;
