$NetBSD: patch-libgnomeprint_grammar.y,v 1.1 2013/08/16 09:01:48 wiz Exp $

Fix build with bison-3.0.

--- libgnomeprint/grammar.y.orig	2010-02-09 12:32:51.000000000 +0000
+++ libgnomeprint/grammar.y
@@ -1,3 +1,4 @@
+%parse-param {graph_t *graph}
 %{
 #include <glib.h>
 
@@ -98,8 +99,6 @@ gnome_print_filter_parse_prop (GnomePrin
 	g_value_unset (&v);
 }
 
-static int yylex (void *lvalp);
-static int yyerror (const char *s);
 %}
 
 %union {
@@ -184,7 +183,7 @@ graph: filter {
 
 %%
 
-static int
+int
 yyerror (const char *s)
 {
 	return -1;
@@ -194,7 +193,7 @@ int                     _gnome_print_fil
 struct yy_buffer_state *_gnome_print_filter_parse_yy_scan_string   (char *);
 void                    _gnome_print_filter_parse_yy_delete_buffer (struct yy_buffer_state *);
 
-static int
+int
 yylex (void *lvalp)
 {
 	return _gnome_print_filter_parse_yylex ((YYSTYPE *) lvalp);
