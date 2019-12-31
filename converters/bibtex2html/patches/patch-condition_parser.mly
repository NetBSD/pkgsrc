$NetBSD: patch-condition_parser.mly,v 1.1 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- condition_parser.mly.orig	2014-07-04 07:51:21.000000000 +0000
+++ condition_parser.mly
@@ -17,15 +17,15 @@
 /*
  * bibtex2html - A BibTeX to HTML translator
  * Copyright (C) 1997 Jean-Christophe FILLIATRE
- * 
+ *
  * This software is free software; you can redistribute it and/or
  * modify it under the terms of the GNU General Public
  * License version 2, as published by the Free Software Foundation.
- * 
+ *
  * This software is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
- * 
+ *
  * See the GNU General Public License version 2 for more details
  * (enclosed in the file GPL).
  */
@@ -39,7 +39,7 @@
 %}
 
 %token <string> IDENT STRING COMP
-%token <string> INT 
+%token <string> INT
 %token COLON AND OR NOT LPAR RPAR DOLLAR_KEY DOLLAR_TYPE EXISTS EOF
 
 %start condition_start
@@ -64,19 +64,17 @@ condition:
 ;
 
 atom:
-| cte COLON STRING           
+| cte COLON STRING
     { let s = Latex_accents.normalize true $3 in
     (*i
       Printf.printf "regexp = %s\n" s;
       i*)
     Match($1, Str.regexp_case_fold s) }
-| cte COMP cte               
+| cte COMP cte
     { Comp($1,$2,$3) }
-| EXISTS IDENT               
-    { Exists(String.lowercase $2) }
+| EXISTS IDENT
+    { Exists(String.lowercase_ascii $2) }
 ;
 
-cte: IDENT { Field(String.lowercase $1) } | INT { Cte($1) } | STRING {
+cte: IDENT { Field(String.lowercase_ascii $1) } | INT { Cte($1) } | STRING {
   Cte($1) } | DOLLAR_KEY { Key } | DOLLAR_TYPE { Entrytype } ;
-
-
