$NetBSD: patch-funct.h,v 1.1 2013/04/30 22:20:58 joerg Exp $

--- funct.h.orig	2013-04-30 20:06:16.000000000 +0000
+++ funct.h
@@ -22,23 +22,23 @@ void log_search(int score, long start_ti
 void setboard(char inboard[60], char ms, char castle[4], char ep[2]);    // setup the board
 
 /* parse.cpp */
-void print_move(position p, move pmove, char mstring[10]); // print a given move
-move parse_move(position p, char mstring[10]);
+void print_move(position p, my_move pmove, char mstring[10]); // print a given move
+my_move parse_move(position p, char mstring[10]);
 
 /* open.cpp */
-move opening_book(h_code hash_code, position p);
+my_move opening_book(h_code hash_code, position p);
 
 /* search.cpp */
-move search(position p, int time_limit, int T);
-void pc_update(move pcmove, int ply);
+my_move search(position p, int time_limit, int T);
+void pc_update(my_move pcmove, int ply);
 int pvs(int alpha, int beta, int depth, int ply);
 int qsearch(int ply, int alpha, int beta);
 
 /* emove.cpp */
-int exec_move(position *p, move emove, int ply);
-int qexec_move(position *p, move emove, int ply);
+int exec_move(position *p, my_move emove, int ply);
+int qexec_move(position *p, my_move emove, int ply);
 void gen_check_table();
-// int undo_move(position *p, move emove, int ply);
+// int undo_move(position *p, my_move emove, int ply);
 
 /* movelist.cpp */
 void legalmoves(position *p, move_list *list);
