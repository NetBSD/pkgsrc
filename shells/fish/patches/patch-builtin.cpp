$NetBSD: patch-builtin.cpp,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- builtin.cpp.orig	2015-03-17 21:48:35.000000000 +0000
+++ builtin.cpp
@@ -268,11 +268,11 @@ static void builtin_print_help(parser_t 
               the rest won't fit
             */
 
-            int screen_height, lines;
+            int screen_height, my_lines;
 
             screen_height = common_get_height();
-            lines = count_char(str, L'\n');
-            if (!get_is_interactive() || (lines > 2*screen_height/3))
+            my_lines = count_char(str, L'\n');
+            if (!get_is_interactive() || (my_lines > 2*screen_height/3))
             {
                 wchar_t *pos;
                 int cut=0;
