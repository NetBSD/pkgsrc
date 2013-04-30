$NetBSD: patch-parse.cpp,v 1.2 2013/04/30 22:20:58 joerg Exp $

--- parse.cpp.orig	2000-04-01 07:46:06.000000000 +0000
+++ parse.cpp
@@ -7,18 +7,18 @@
 #include "chess.h"
 #include "funct.h"
 #include "const.h"
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 #include <string.h>
 
 extern int ics;
 // Function to parse a move from the human player
 // This move is checked then checked to see if it is legal
-move parse_move(position p, char mstring[10])
+my_move parse_move(position p, char mstring[10])
 {
   int legal = 0, piece, to_sq = -1, from_sq = -1, promote = QUEEN;
   int from_file = -1, from_row = -1, match_count = 0;
-  move play, mplay[4], nomove; nomove.t = 0;
+  my_move play, mplay[4], nomove; nomove.t = 0;
   mplay[0].t = 0; mplay[1].t = 0; mplay[2].t = 0; mplay[3].t = 0;
   position t_pos;
   move_list list;
@@ -175,7 +175,7 @@ move parse_move(position p, char mstring
 // to a string in long algebraic format
 // This function works by simply adding the appropriate
 // characters to the move string;
-void print_move(position p, move pmove, char mstring[10])
+void print_move(position p, my_move pmove, char mstring[10])
 {
   char dummy[10];             // dummy character string
   int ptype, pfrom, pto, ppiece;
