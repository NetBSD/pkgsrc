$NetBSD: patch-gst_parse_grammar.y,v 1.1 2013/08/03 04:07:49 ryoon Exp $

* Fix build with bison-3.0.

--- gst/parse/grammar.y.orig	2012-10-25 10:54:57.000000000 +0000
+++ gst/parse/grammar.y
@@ -659,6 +659,7 @@ static int yyerror (void *scanner, graph
 
 %parse-param { void *scanner }
 %parse-param { graph_t *graph }
+%lex-param {void *scanner}
 %pure-parser
 
 %start graph
