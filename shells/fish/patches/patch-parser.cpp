$NetBSD: patch-parser.cpp,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- parser.cpp.orig	2015-03-17 21:50:15.000000000 +0000
+++ parser.cpp
@@ -446,7 +446,7 @@ const wchar_t *parser_t::get_block_desc(
 */
 static int parser_is_pipe_forbidden(const wcstring &word)
 {
-    return contains(word,
+    return contains(&word,
                     L"exec",
                     L"case",
                     L"break",
@@ -1726,7 +1726,7 @@ int parser_t::parse_job(process_t *p,
 
         mark = tok_get_pos(tok);
 
-        if (contains(nxt,
+        if (contains(&nxt,
                      L"command",
                      L"builtin",
                      L"not",
@@ -2398,9 +2398,9 @@ void parser_t::eval_job(tokenizer_t *tok
                 if (job_start_pos < tok_get_pos(tok))
                 {
                     long stop_pos = tok_get_pos(tok);
-                    const wchar_t *newline = wcschr(tok_string(tok)+start_pos, L'\n');
-                    if (newline)
-                        stop_pos = mini<long>(stop_pos, newline - tok_string(tok));
+                    const wchar_t *my_newline = wcschr(tok_string(tok)+start_pos, L'\n');
+                    if (my_newline)
+                        stop_pos = mini<long>(stop_pos, my_newline - tok_string(tok));
 
                     j->set_command(wcstring(tok_string(tok)+start_pos, stop_pos-start_pos));
                 }
@@ -3024,7 +3024,7 @@ int parser_t::test(const wchar_t *buff, 
                           command is needed, such as after 'and' or
                           'while'
                         */
-                        if (contains(command,
+                        if (contains(&command,
                                      L"end"))
                         {
                             err=1;
@@ -3129,7 +3129,7 @@ int parser_t::test(const wchar_t *buff, 
                         had_cmd = 0;
                     }
 
-                    if (contains(command,
+                    if (contains(&command,
                                  L"or",
                                  L"and"))
                     {
@@ -3255,7 +3255,7 @@ int parser_t::test(const wchar_t *buff, 
                     /*
                       Test that break and continue are only used within loop blocks
                     */
-                    if (contains(command, L"break", L"continue"))
+                    if (contains(&command, L"break", L"continue"))
                     {
                         bool found_loop = false;
                         size_t block_idx = block_infos.size();
