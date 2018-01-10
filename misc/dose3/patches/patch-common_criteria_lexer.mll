$NetBSD: patch-common_criteria_lexer.mll,v 1.1 2018/01/10 16:31:34 jaapb Exp $

Compatibility updates for safe-string (and ocaml 4.06)
--- common/criteria_lexer.mll.orig	2016-07-20 11:45:05.000000000 +0000
+++ common/criteria_lexer.mll
@@ -18,7 +18,7 @@
     let c = Lexing.lexeme_char lexbuf 2 in (* the delimiter can be any character *)
     (* find the terminating delimiter *)
     let endpos =
-      try String.index_from lexbuf.lex_buffer (lexbuf.lex_start_pos + 3) c with
+      try Bytes.index_from lexbuf.lex_buffer (lexbuf.lex_start_pos + 4) c with
       |Invalid_argument _ ->
           raise (Format822.Syntax_error (
             Format822.error lexbuf "String too short"))
@@ -27,9 +27,9 @@
             Format822.error lexbuf (Printf.sprintf "cannot find: %c" c)))
     in
     let len = endpos - (lexbuf.lex_start_pos + 3) in
-    let s = String.sub lexbuf.lex_buffer (lexbuf.lex_start_pos + 3) len in
-    lexbuf.Lexing.lex_curr_pos <- lexbuf.Lexing.lex_start_pos + ((String.length s)+4);
-    s
+    let s = Bytes.sub lexbuf.lex_buffer (lexbuf.lex_start_pos + 3) len in
+    lexbuf.Lexing.lex_curr_pos <- lexbuf.Lexing.lex_start_pos + ((Bytes.length s)+4);
+    Bytes.to_string s
 
 }
 
