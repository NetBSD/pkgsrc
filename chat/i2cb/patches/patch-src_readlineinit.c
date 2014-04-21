$NetBSD: patch-src_readlineinit.c,v 1.1 2014/04/21 18:16:13 joerg Exp $

--- src/readlineinit.c.orig	2014-04-20 18:25:41.000000000 +0000
+++ src/readlineinit.c
@@ -20,9 +20,9 @@ char *editor;
  * bind the tab key
  */
 
-rl_bind_key_in_map('\t', (Function *)handletab, vi_insertion_keymap);
-rl_bind_key_in_map('\t', (Function *)handletab, vi_movement_keymap);
-rl_bind_key_in_map('\t', (Function *)handletab, emacs_standard_keymap);
+rl_bind_key_in_map('\t', handletab, vi_insertion_keymap);
+rl_bind_key_in_map('\t', handletab, vi_movement_keymap);
+rl_bind_key_in_map('\t', handletab, emacs_standard_keymap);
 
 rl_vi_editing_mode(0, ' '); /* default to vi, dammit. */
 gv.editmode = "vi";
