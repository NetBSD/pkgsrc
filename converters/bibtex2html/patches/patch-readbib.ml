$NetBSD: patch-readbib.ml,v 1.1 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- readbib.ml.orig	2014-07-04 07:51:21.000000000 +0000
+++ readbib.ml
@@ -21,10 +21,10 @@ open Printf
 
 let read_entries_from_file f =
   if not !Options.quiet then begin
-    if f = "" then 
+    if f = "" then
       eprintf "Reading from standard input...\n"
     else
-      eprintf "Reading %s..." f; 
+      eprintf "Reading %s..." f;
     flush stderr
   end;
   let chan = if f = "" then stdin else open_in f in
@@ -36,9 +36,9 @@ let read_entries_from_file f =
       eprintf "ok (%d entries).\n" (Bibtex.size el); flush stderr
     end;
     el
-  with Parsing.Parse_error | Failure "unterminated string" ->
+  with Parsing.Parse_error | Failure _ ->
     if f <> "" then close_in chan;
-    eprintf "Parse error character %d, in or after entry '%s'.\n" 
+    eprintf "Parse error character %d, in or after entry '%s'.\n"
       (Lexing.lexeme_start lb) !Bibtex.current_key;
     flush stderr;
-    exit 1 
+    exit 1
