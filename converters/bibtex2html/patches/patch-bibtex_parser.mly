$NetBSD: patch-bibtex_parser.mly,v 1.1 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- bibtex_parser.mly.orig	2014-07-04 07:51:21.000000000 +0000
+++ bibtex_parser.mly
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
@@ -40,7 +40,7 @@
 
 %}
 
-%token <string> Tident Tstring Tcomment 
+%token <string> Tident Tstring Tcomment
 %token <string * string> Tentry
 %token Tabbrev Tpreamble Tlbrace Trbrace Tcomma Tequal EOF Tsharp
 
@@ -67,19 +67,19 @@ command:
  | Tpreamble sharp_string_list Trbrace
      { Preamble $2 }
  | Tabbrev Tident Tequal sharp_string_list Trbrace
-     { Abbrev (String.lowercase $2,$4) }
+     { Abbrev (String.lowercase_ascii $2,$4) }
  | entry Tcomma comma_field_list Trbrace
-     { let et,key = $1 in Entry (String.lowercase et, key, $3) }
+     { let et,key = $1 in Entry (String.lowercase_ascii et, key, $3) }
 ;
 
-entry: 
- | Tentry  
+entry:
+ | Tentry
      { let et,key = $1 in Bibtex.current_key := key; (et,key) }
 
 comma_field_list:
    field Tcomma comma_field_list
      { $1::$3 }
- | field 
+ | field
      { [$1] }
  | field Tcomma
      { [$1] }
@@ -91,7 +91,7 @@ field:
      { ($1,[String ""]) }
 ;
 field_name:
-   Tident   { String.lowercase $1 }
+   Tident   { String.lowercase_ascii $1 }
  | Tcomment { "comment" }
 ;
 sharp_string_list:
@@ -102,7 +102,7 @@ sharp_string_list:
 ;
 atom:
    Tident
-     { Id (String.lowercase $1) }
+     { Id (String.lowercase_ascii $1) }
  | Tstring
      { String $1 }
 ;
