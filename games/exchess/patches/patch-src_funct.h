$NetBSD: patch-src_funct.h,v 1.1 2014/09/11 16:59:16 jperkin Exp $

Avoid 'move' conflict.

--- src/funct.h.orig	2014-08-17 11:03:08.000000000 +0000
+++ src/funct.h
@@ -22,7 +22,7 @@ void write_out(const char *);   // write
 void performance();             // performance test function
 
 /* search.cpp */
-void pc_update(move pcmove, int ply);
+void pc_update(my_move pcmove, int ply);
 
 /* setup.cpp */
 void set_search_param();
@@ -37,7 +37,7 @@ void QuickSortMove(move_rec *Lb, move_re
 void build_book(position ipos);
 void book_learn(int flag, game_rec *gr);
 int edit_book(h_code hash_code, position *p);
-move opening_book(h_code hash_code, position p, game_rec *gr);
+my_move opening_book(h_code hash_code, position p, game_rec *gr);
 
 /* util.cpp */
 int GetTime();
