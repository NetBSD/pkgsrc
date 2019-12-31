$NetBSD: patch-bibtex__lexer.mll,v 1.2 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- bibtex_lexer.mll.orig	2014-07-04 07:51:21.000000000 +0000
+++ bibtex_lexer.mll
@@ -23,7 +23,7 @@
 open Lexing
 open Bibtex_parser
 
-let serious = ref false    (* if we are inside a command or not *) 
+let serious = ref false    (* if we are inside a command or not *)
 
 let brace_depth = ref 0
 
@@ -31,12 +31,12 @@ let brace_depth = ref 0
 
 let buffer = Buffer.create 8192
 
-let reset_string_buffer () = 
+let reset_string_buffer () =
   Buffer.reset buffer
 
-let store_string_char c = 
+let store_string_char c =
   Buffer.add_char buffer c
- 
+
 let get_stored_string () =
   let s = Buffer.contents buffer in
   Buffer.reset buffer;
@@ -55,23 +55,23 @@ let space = [' ' '\t' '\r' '\n']
 rule token = parse
   | space +
       { token lexbuf }
-  | '@' space* 
-    ([^ ' ' '\t' '\n' '\r' '{' '(']+ as entry_type) space* 
+  | '@' space*
+    ([^ ' ' '\t' '\n' '\r' '{' '(']+ as entry_type) space*
     (('{' | '(') as delim) space*
-       { serious := true; 
-	 start_delim := delim; 
-	 match String.lowercase entry_type with 
-	   | "string" -> 
+       { serious := true;
+	 start_delim := delim;
+	 match String.lowercase_ascii entry_type with
+	   | "string" ->
 	       Tabbrev
-	   | "comment" -> 
+	   | "comment" ->
 	       reset_string_buffer ();
                comment lexbuf;
                serious := false;
                Tcomment (get_stored_string ())
-	   | "preamble" -> 
+	   | "preamble" ->
 	       Tpreamble
-	   |  et -> 
-		Tentry (entry_type, key lexbuf) 
+	   |  et ->
+		Tentry (entry_type, key lexbuf)
        }
   | '=' { if !serious then Tequal else token lexbuf }
   | '#' { if !serious then Tsharp else token lexbuf }
@@ -110,7 +110,7 @@ and string = parse
       	brace lexbuf;
 	store_string_char '}';
 	string lexbuf
-      }  
+      }
   | '"'
       { () }
   | "\\\""
@@ -141,10 +141,10 @@ and brace = parse
         brace lexbuf }
 
 and key = parse
-  | [^ ' ' '\t' '\n' '\r' ',']+ 
+  | [^ ' ' '\t' '\n' '\r' ',']+
     { lexeme lexbuf }
-  | eof 
-  | _ 
+  | eof
+  | _
     { raise Parsing.Parse_error }
 
 and comment = parse
@@ -153,7 +153,7 @@ and comment = parse
   | [^ '}' '@'] as c
       { store_string_char c;
         comment lexbuf }
-  | eof 
+  | eof
       { () }
-  | _ 
+  | _
       { () }
