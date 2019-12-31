$NetBSD: patch-bbl_lexer.mll,v 1.1 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml
git commit 8f25afb95a839c9f9522a34013d5c905af14378b

--- bbl_lexer.mll.orig	2014-07-04 07:51:21.000000000 +0000
+++ bbl_lexer.mll
@@ -39,7 +39,7 @@ rule biblio_header = parse
       { biblio_name lexbuf }
   | eof
       { raise End_of_file }
-  | _ 
+  | _
       { biblio_header lexbuf }
 
 and biblio_name = parse
@@ -48,15 +48,15 @@ and biblio_name = parse
 	let s = String.sub l 1 (String.length l - 2) in
         Some s }
   | _
-      { None } 
+      { None }
 
 and bibitem = parse
   | "\\end{thebibliography}"
       { raise End_of_biblio }
   | '\\' ['a'-'z']* "bibitem"
       { brace_depth := 0;
-	begin try bibitem1 lexbuf 
-	      with Failure "lexing: empty token" -> opt_ref := None end;
+	begin try bibitem1 lexbuf
+	      with Failure _ -> opt_ref := None end;
         bibitem2 lexbuf }
   | _ { bibitem lexbuf }
 
@@ -70,7 +70,7 @@ and bibitem1_body = parse
   | eof   { raise End_of_file }
 
 and bibitem2 = parse
-  | '{' { Buffer.reset buf; 
+  | '{' { Buffer.reset buf;
 	  key := bibitem2_body lexbuf;
 	  skip_end_of_line lexbuf;
 	  Buffer.reset buf;
