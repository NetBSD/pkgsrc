$NetBSD: patch-lex.c,v 1.3 2023/06/19 20:31:02 tnn Exp $

Assign rl_catch_signals only if HAVE_RL_CATCH_SIGNALS.

--- lex.c.orig	2023-06-18 16:30:02.000000000 +0000
+++ lex.c
@@ -888,8 +888,10 @@ LexInit (void)
     rl_getc_function = ReadlineGetChar;
     rl_prep_term_function = (void *) my_prep_terminal;
     rl_deprep_term_function = my_deprep_terminal;
+#if HAVE_RL_CATCH_SIGNALS
     rl_catch_signals = 0;
 #endif
+#endif
     LexInputReference = NewReference ((void **) &lexInput);
     MemAddRoot (LexInputReference);
     EXIT ();
