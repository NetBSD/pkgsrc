$NetBSD: patch-libgst_input.c,v 1.1 2014/12/27 00:13:28 dholland Exp $

Update for readline API changes.

--- libgst/input.c~	2011-03-21 11:32:44.000000000 +0000
+++ libgst/input.c
@@ -1142,13 +1142,13 @@ _gst_initialize_readline (void)
   rl_special_prefixes = (char *) "+-=*<>~?%/@|&\\";
 
   /* Our rules for quoting are a bit different from the default */
-  rl_filename_quoting_function = (CPFunction *) readline_quote_filename;
+  rl_filename_quoting_function = (rl_quote_func_t *) readline_quote_filename;
   rl_filename_dequoting_function =
-    (CPFunction *) readline_dequote_filename;
+    (rl_dequote_func_t *) readline_dequote_filename;
 
   /* Try to match a symbol before a filename */
   rl_attempted_completion_function =
-    (CPPFunction *) readline_match_symbols;
+    (rl_completion_func_t *) readline_match_symbols;
 
   /* Since we have to sort the array to perform the binary search,
      remove duplicates and avoid that readline resorts the result.  */
