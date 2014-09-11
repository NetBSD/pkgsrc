$NetBSD: patch-src_search.cpp,v 1.1 2014/09/11 16:59:16 jperkin Exp $

Avoid 'move' conflict.

--- src/search.cpp.orig	2014-08-17 11:03:08.000000000 +0000
+++ src/search.cpp
@@ -39,7 +39,7 @@ unsigned __int64 attempts=0, successes=0
 /*----------------------- Search function ---------------------*/
 // Driver for the search process.  1st initialize important data
 // structures, then do iterative deeping until time runs out.
-move tree_search::search(position p, int time_limit, int T, game_rec *gr)
+my_move tree_search::search(position p, int time_limit, int T, game_rec *gr)
 {
    char outstring[400], mstring[10];
    int g, done, pvi;
@@ -47,7 +47,7 @@ move tree_search::search(position p, int
    int last_mate_score = 0, mate_iteration_count = 0; 
    int limit_search_depth = max_search_depth;
    position pv_pos; 
-   move nomove; nomove.t = NOMOVE;
+   my_move nomove; nomove.t = NOMOVE;
 
 #if DEBUG_SEARCH
  search_outfile.open("search_debug.log");
@@ -527,7 +527,7 @@ move tree_search::search(position p, int
 // It is updated by doing a mem-copy of the principle continuation
 // found at deeper depths to this depth + the move at this depth
 // is stuffed in first.
-inline void ts_thread_data::pc_update(move pcmove, int ply)
+inline void ts_thread_data::pc_update(my_move pcmove, int ply)
 {
  int pci;
  pc[ply][ply].t = pcmove.t;
