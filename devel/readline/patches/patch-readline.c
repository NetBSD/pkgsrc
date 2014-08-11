$NetBSD: patch-readline.c,v 1.1 2014/08/11 21:29:00 markd Exp $

Readline-6.3 Official Patch 1

The `.' command in vi mode cannot undo multi-key commands beginning with
`c', `d', and `y' (command plus motion specifier).

Readline-6.3 Official Patch 2

When in callback mode, some readline commands can cause readline to seg
fault by passing invalid contexts to callback functions.

--- readline.c.orig	2013-10-28 18:58:06.000000000 +0000
+++ readline.c
@@ -744,7 +744,8 @@ _rl_dispatch_callback (cxt)
     r = _rl_subseq_result (r, cxt->oldmap, cxt->okey, (cxt->flags & KSEQ_SUBSEQ));
 
   RL_CHECK_SIGNALS ();
-  if (r == 0)			/* success! */
+  /* We only treat values < 0 specially to simulate recursion. */
+  if (r >= 0 || (r == -1 && (cxt->flags & KSEQ_SUBSEQ) == 0)) /* success! or failure! */
     {
       _rl_keyseq_chain_dispose ();
       RL_UNSETSTATE (RL_STATE_MULTIKEY);
@@ -964,7 +965,7 @@ _rl_dispatch_subseq (key, map, got_subse
 #if defined (VI_MODE)
   if (rl_editing_mode == vi_mode && _rl_keymap == vi_movement_keymap &&
       key != ANYOTHERKEY &&
-      rl_key_sequence_length == 1 &&	/* XXX */
+      _rl_dispatching_keymap == vi_movement_keymap &&
       _rl_vi_textmod_command (key))
     _rl_vi_set_last (key, rl_numeric_arg, rl_arg_sign);
 #endif
