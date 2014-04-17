$NetBSD: patch-src_input.c,v 1.1 2014/04/17 20:27:33 joerg Exp $

--- src/input.c.orig	2002-02-15 11:09:09.000000000 +0000
+++ src/input.c
@@ -200,9 +200,9 @@ void input_init(void)
 	rl_outstream = stderr;
     /* Allow conditional parsing of the ~/.inputrc file. */
     rl_readline_name = PACKAGE;
-    rl_completion_entry_function = (rl_compentry_func_t *)no_completion_function;
+    rl_completion_entry_function = no_completion_function;
     /* Tell the completer that we want a crack first. */
-    rl_attempted_completion_function = (CPPFunction *)the_complete_function;
+    rl_attempted_completion_function = the_complete_function;
 
 	rl_completer_word_break_characters = " \t\n\"\';";
 	rl_completer_quote_characters = "'\"\\";
@@ -210,7 +210,7 @@ void input_init(void)
 	/* characters that need to be quoted when appearing in filenames. */
 	rl_filename_quote_characters = " \t\n\\\"'@<>=;|&()#$`?*[]!:";
 	rl_filename_quoting_function = bash_quote_filename;
-	rl_filename_dequoting_function = (rl_dequote_func_t *)bash_dequote_filename;
+	rl_filename_dequoting_function = bash_dequote_filename;
 	rl_char_is_quoted_p = char_is_quoted;
 #endif
 
