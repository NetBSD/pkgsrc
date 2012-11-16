$NetBSD: patch-src_board_board.c,v 1.1 2012/11/16 00:50:39 joerg Exp $

--- src/board/board.c.orig	2012-11-15 15:11:40.000000000 +0000
+++ src/board/board.c
@@ -281,7 +281,7 @@ board_is_game_over (const Board *board, 
 
 
 /* Determine if a move is legal according to specified rules. */
-inline int
+int
 board_is_legal_move (const Board *board, BoardRuleSet rule_set, int color, ...)
 {
   va_list move;
@@ -300,7 +300,7 @@ board_is_legal_move (const Board *board,
 
 
 /* Play the specified move on the given board. */
-inline void
+void
 board_play_move (Board *board, int color, ...)
 {
   va_list move;
@@ -388,7 +388,7 @@ board_apply_changes
  * tracking unexpectedly changing move number (i.e. with MN[] SGF
  * property that doesn't correspond a real move).
  */
-inline void
+void
 board_add_dummy_move_entry (Board *board)
 {
   assert (board);
@@ -409,7 +409,7 @@ board_add_dummy_move_entry (Board *board
  * changes.  If not moves or changes are in the stack yet, return
  * zero.
  */
-inline int
+int
 board_undo (Board *board, int num_undos)
 {
   int k;
@@ -467,7 +467,7 @@ board_get_move_number (const Board *boar
 }
 
 
-inline void
+void
 board_undo_changes (Board *board, int num_changes)
 {
   int k;
@@ -553,7 +553,7 @@ determine_position_delta (int delta_x, i
 
 
 /* Dump the contents of given board's grid to stderr. */
-inline void
+void
 board_dump (const Board *board)
 {
   assert (board);
@@ -562,7 +562,7 @@ board_dump (const Board *board)
 }
 
 
-inline void
+void
 board_validate (const Board *board)
 {
   assert (board);
@@ -1059,7 +1059,7 @@ game_parse_move (Game game, int board_wi
  * If the default setup is not empty, nonzero is returned and zero
  * otherwise.
  */
-inline int
+int
 game_get_default_setup (Game game, int width, int height,
 			BoardPositionList **black_stones,
 			BoardPositionList **white_stones)
