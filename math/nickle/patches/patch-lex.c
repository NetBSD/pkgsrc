$NetBSD: patch-lex.c,v 1.1 2017/04/23 14:49:27 taca Exp $

Assign rl_catch_signals only if HAVE_RL_CATCH_SIGNALS.

--- lex.c.orig	2017-03-15 21:28:13.000000000 +0000
+++ lex.c
@@ -927,8 +927,10 @@ LexInit (void)
     rl_getc_function = ReadlineGetChar;
     rl_prep_term_function = my_prep_terminal;
     rl_deprep_term_function = my_deprep_terminal;
+#if HAVE_RL_CATCH_SIGNALS
     rl_catch_signals = 0;
 #endif
+#endif
     LexInputReference = NewReference ((void **) &lexInput);
     MemAddRoot (LexInputReference);
     EXIT ();
