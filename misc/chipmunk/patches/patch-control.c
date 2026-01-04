$NetBSD: patch-control.c,v 1.1 2026/01/04 11:45:03 wiz Exp $

--- control.c.orig	2026-01-04 11:43:53.729199470 +0000
+++ control.c
@@ -1255,8 +1255,8 @@ void initialize_readline (void) {
   /*  rl_basic_word_break_characters = " \t\n\"\\'`@><="; */
 
   rl_readline_name = "chipmunk";
-  rl_completion_entry_function=(Function *)dummy_filename_completion_function;
-  rl_attempted_completion_function = (Function *)completion;
+  rl_completion_entry_function=dummy_filename_completion_function;
+  rl_attempted_completion_function = completion;
 }
 
 
