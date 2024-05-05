$NetBSD: patch-src_main.c,v 1.2 2024/05/05 14:31:32 ktnb Exp $

Fixed upstream bug where variable was defined without braces in
switch. Reported upstream: https://github.com/jubalh/nudoku/issues/61

--- src/main.c.orig	2024-05-05 01:37:03.380017435 +0000
+++ src/main.c
@@ -708,6 +708,7 @@ int main(int argc, char *argv[])
 				}
 				break;
 			case 'u': // Undo
+			{
 				move_t old_move;
 				if (undo_stack_pop(&old_move))
 				{	// Stack empty
@@ -720,7 +721,7 @@ int main(int argc, char *argv[])
 				user_board[posy*9+posx] = old_move.prev_val;
 				fill_grid(user_board, plain_board, x, y);
 				break;
-
+			}
 			default:
 				break;
 		}
