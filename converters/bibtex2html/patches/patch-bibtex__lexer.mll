$NetBSD: patch-bibtex__lexer.mll,v 1.1 2018/03/14 08:28:44 dholland Exp $

Silence deprecation warning.

--- bibtex_lexer.mll~	2014-07-04 07:51:21.000000000 +0000
+++ bibtex_lexer.mll
@@ -60,7 +60,7 @@ rule token = parse
     (('{' | '(') as delim) space*
        { serious := true; 
 	 start_delim := delim; 
-	 match String.lowercase entry_type with 
+	 match String.lowercase_ascii entry_type with 
 	   | "string" -> 
 	       Tabbrev
 	   | "comment" -> 
