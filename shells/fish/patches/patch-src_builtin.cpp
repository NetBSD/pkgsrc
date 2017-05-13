$NetBSD: patch-src_builtin.cpp,v 1.1 2017/05/13 01:19:05 wen Exp $

--- src/builtin.cpp.orig	2017-04-29 23:41:45.000000000 +0000
+++ src/builtin.cpp
@@ -190,11 +190,11 @@ void builtin_print_help(parser_t &parser
         bool is_short = false;
         if (is_stderr) {
             // Interactive mode help to screen - only print synopsis if the rest won't fit.
-            int screen_height, lines;
+            int screen_height, my_lines;
 
             screen_height = common_get_height();
-            lines = count_char(str, L'\n');
-            if (!shell_is_interactive() || (lines > 2 * screen_height / 3)) {
+            my_lines = count_char(str, L'\n');
+            if (!shell_is_interactive() || (my_lines > 2 * screen_height / 3)) {
                 wchar_t *pos;
                 int cut = 0;
                 int i;
