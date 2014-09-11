$NetBSD: patch-src_chess.h,v 1.1 2014/09/11 16:59:16 jperkin Exp $

Avoid 'move' conflict.

--- src/chess.h.orig	2014-08-17 11:03:08.000000000 +0000
+++ src/chess.h
@@ -30,7 +30,7 @@ struct move_t {
 // union of move_t and an integer to make comparison of 
 // moves easier.  (as suggested in Tom Kerrigans simple chess program)
 
-union move {
+union my_move {
   move_t b;
   int32_t t;           // assuming a 32 bit integer
 };
@@ -38,7 +38,7 @@ union move {
 // Add a score for sorting purposes to the move record
 
 struct move_rec {
-  move m;
+  my_move m;
   int score; 
 };
 
@@ -82,10 +82,10 @@ struct position {
 
   unsigned char threat_square;
 
-  move hmove;                // expected best move
-  move rmove;                // reply move               
-  move cmove;                // combination move
-  move pmove;                // pawn hash move  
+  my_move hmove;             // expected best move
+  my_move rmove;             // reply move               
+  my_move cmove;             // combination move
+  my_move pmove;             // pawn hash move  
 
   int8_t gstage;             // game stage, range 0-16 -- depends only  
                              //    upon pawn structure --> important for pawn hashing!
@@ -93,7 +93,7 @@ struct position {
                              //   -- should check this for all subtractions!  unsigned ints
                              //      may be converted incorrectly if they are negated.
   int8_t plist[2][7][10];    // piece lists
-  move last;                 // last move made
+  my_move last;              // last move made
   h_code hcode;              // hash code
   h_code pcode;              // pawn hash code
 
@@ -130,7 +130,7 @@ struct position {
   void rook_cc(move_list *list, int sqr, int ds);
 
   /* exmove.cpp */
-  int exec_move(move emove, int ply);
+  int exec_move(my_move emove, int ply);
 
   /* attacks.cpp */
   int simple_check(int move_sq);
@@ -159,8 +159,8 @@ struct position {
 
   /* support.cpp */
   void write_fen();
-  void print_move(move pmove, char mstring[10], ts_thread_data *temps);
-  move parse_move(char mstring[10], ts_thread_data *temps);
+  void print_move(my_move pmove, char mstring[10], ts_thread_data *temps);
+  my_move parse_move(char mstring[10], ts_thread_data *temps);
 
 };
 
@@ -187,7 +187,7 @@ struct search_node {
   cmove_rec *cmove;
   pawn_rec *phash;  // for getting a pawn hash move 
 
-  move smove;        // current move we are searching
+  my_move smove;     // current move we are searching
 
   int ply;           
   int mate_ext;      // did a mate extension occur?
@@ -227,7 +227,7 @@ struct ts_thread_data {
   int quit_thread;         // flag to tell thread to quit
 
   search_node n[MAXD+1];   // array of search positions
-  move pc[MAXD+1][MAXD+1]; // triangular array for search
+  my_move pc[MAXD+1][MAXD+1]; // triangular array for search
                            //    principle continuation
   h_code plist[MAX_GAME_PLY];   // hash codes of positions visited
 
@@ -269,7 +269,7 @@ struct ts_thread_data {
   }
 
   /* search.cpp */
-  inline void pc_update(move pcmove, int ply);
+  inline void pc_update(my_move pcmove, int ply);
 
 };
 
@@ -296,9 +296,9 @@ struct tree_search {
   int max_search_depth;         // search depth limit set by xboard   
   int max_search_time;          // search time limit set by xboard  
 
-  move bookm;                   // move from opening book
-  move ponder_move;             // move we are pondering
-  move last_displayed_move;     // best move from previous search display
+  my_move bookm;                // move from opening book
+  my_move ponder_move;          // move we are pondering
+  my_move last_displayed_move;  // best move from previous search display
 
   int tsuite, analysis_mode;    // flags to determine whether we are in
                                 //    analysis mode or a test suite
@@ -307,7 +307,7 @@ struct tree_search {
 
   // variables to support testsuite mode 
   float soltime;
-  unsigned int bmcount; move bmoves[256];
+  unsigned int bmcount; my_move bmoves[256];
   int best_score;
   char bmtype[3];      // "am" avoid move or "bm" best move string                              
 
@@ -315,7 +315,7 @@ struct tree_search {
   int no_book;                  // counter for positions with no book moves
 
   /* search.cpp */
-  move search(position p, int time_limit, int T, game_rec *gr);
+  my_move search(position p, int time_limit, int T, game_rec *gr);
   int search_threads(int alpha, int beta, int depth, int threads);
   void sort_root_moves();
 
@@ -352,9 +352,9 @@ struct game_rec {
   position reset;          // reset position for takebacks
  /* available moves */
   move_list movelist;      // list of pseudo-legal moves for current pos
-  move best;               // best move for current position
+  my_move best;               // best move for current position
  /* game history info */
-  move game_history[MAX_GAME_PLY];  // list of move played
+  my_move game_history[MAX_GAME_PLY];  // list of move played
 
  /* game control flags and counters */
   int T;                   // turn number
