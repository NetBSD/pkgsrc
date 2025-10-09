$NetBSD: patch-example_medit.c,v 1.1 2025/10/09 16:27:57 ryoon Exp $

* For strict check by GCC 14.

--- example/medit.c.orig	2025-10-07 05:42:12.165030802 +0000
+++ example/medit.c
@@ -662,7 +662,7 @@ static void MenuHelpProc (Widget, XEvent
    off the current input method, otherwide turn on the input method
    input_method_table[$IDX].  */
 void
-select_input_method (idx)
+select_input_method (int idx)
 {
   int previous_input_method = current_input_method;
 
