$NetBSD: patch-src_ppx_optcomp.ml,v 1.1 2017/01/04 00:10:43 jaapb Exp $

Changes to do with OCaml 4.04 (from 4.04 branch)
--- src/ppx_optcomp.ml.orig	2016-09-02 10:02:01.000000000 +0000
+++ src/ppx_optcomp.ml
@@ -617,7 +617,7 @@ end = struct
 
   let rec next_directive (lexer : lexer) lexbuf =
     match lexer lexbuf with
-    | SHARP -> parse_directive lexer lexbuf
+    | HASH -> parse_directive lexer lexbuf
     | EOL -> next_directive lexer lexbuf
     | EOF -> endif_missing lexbuf
     | _ -> skip_line lexer lexbuf; next_directive lexer lexbuf
@@ -712,7 +712,7 @@ end = struct
   (* Return the next token from a stream, interpreting directives. *)
   let rec lexer_internal (lexer : lexer) lexbuf : Parser.token =
     match lexer lexbuf with
-    | SHARP when at_bol lexbuf ->
+    | HASH when at_bol lexbuf ->
       interpret_directive lexer lexbuf (parse_directive lexer lexbuf);
       lexer_internal lexer lexbuf
     | EOF -> Stack.check_eof lexbuf; EOF
@@ -740,7 +740,7 @@ end = struct
         (* Special case for ifndef + define. If we fallback to [interpret_if], it will
            raise, because the variable is not defined. *)
         match lexer lexbuf with
-        | SHARP when at_bol lexbuf -> begin
+        | HASH when at_bol lexbuf -> begin
             match (parse_directive lexer lexbuf).txt with
             | Define (var', expr) when var'.txt = var.txt ->
               Stack.enqueue dir;
@@ -847,7 +847,7 @@ end = struct
     Location.init lexbuf fn;
     let rec loop pos acc =
       match Lexer.token lexbuf with
-      | SHARP when at_bol lexbuf ->
+      | HASH when at_bol lexbuf ->
         let acc = (pos, Lexing.lexeme_start lexbuf) :: acc in
         interpret_directive Lexer.token lexbuf (parse_directive Lexer.token lexbuf);
         loop (Lexing.lexeme_end lexbuf) acc
