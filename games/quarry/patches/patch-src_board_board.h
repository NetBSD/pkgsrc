$NetBSD: patch-src_board_board.h,v 1.1 2012/11/16 00:50:39 joerg Exp $

--- src/board/board.h.orig	2012-11-15 15:13:35.000000000 +0000
+++ src/board/board.h
@@ -208,24 +208,24 @@ int		board_adjust_color_to_play (const B
 int		board_is_game_over (const Board *board, BoardRuleSet rule_set,
 				    int color_to_play);
 
-inline int	board_is_legal_move (const Board *board, BoardRuleSet rule_set,
+int	board_is_legal_move (const Board *board, BoardRuleSet rule_set,
 				     int color, ...);
 
-inline void	board_play_move (Board *board, int color, ...);
+void	board_play_move (Board *board, int color, ...);
 void		board_apply_changes
 		  (Board *board,
 		   const BoardPositionList *const
 		     change_lists[NUM_ON_GRID_VALUES]);
-inline void	board_add_dummy_move_entry (Board *board);
+void	board_add_dummy_move_entry (Board *board);
 
-inline int	board_undo (Board *board, int num_moves);
+int	board_undo (Board *board, int num_moves);
 
 int		board_get_move_number (const Board *board,
 				       int num_moves_backward);
 
 
-inline void	board_dump (const Board *board);
-inline void	board_validate (const Board *board);
+void	board_dump (const Board *board);
+void	board_validate (const Board *board);
 
 
 BoardPositionList *  board_position_list_new (const int *positions,
@@ -299,7 +299,7 @@ int		game_parse_move (Game game, int boa
 				 BoardAbstractMoveData *move_data);
 
 
-inline int	game_get_default_setup (Game game, int width, int height,
+int	game_get_default_setup (Game game, int width, int height,
 					BoardPositionList **black_stones,
 					BoardPositionList **white_stones);
 
