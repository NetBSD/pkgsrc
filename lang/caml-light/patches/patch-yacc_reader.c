$NetBSD: patch-yacc_reader.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.

--- yacc/reader.c.orig	2012-10-20 13:12:08.000000000 +0000
+++ yacc/reader.c
@@ -49,7 +49,7 @@ int c;
 }
 
 
-get_line()
+void get_line(void)
 {
     register FILE *f = input_file;
     register int c;
@@ -113,7 +113,7 @@ dup_line()
 }
 
 
-skip_comment()
+void skip_comment(void)
 {
     register char *s;
 
@@ -268,7 +268,7 @@ keyword()
 }
 
 
-copy_ident()
+void copy_ident(void)
 {
     register int c;
     register FILE *f = output_file;
@@ -297,7 +297,7 @@ copy_ident()
 }
 
 
-copy_text()
+void copy_text(void)
 {
     register int c;
     int quote;
@@ -414,7 +414,7 @@ loop:
 }
 
 
-copy_union()
+void copy_union(void)
 {
     register int c;
     int quote;
@@ -785,8 +785,7 @@ get_tag()
 }
 
 
-declare_tokens(assoc)
-int assoc;
+void declare_tokens(int assoc)
 {
     register int c;
     register bucket *bp;
@@ -852,7 +851,7 @@ int assoc;
 }
 
 
-declare_types()
+void declare_types(void)
 {
     register int c;
     register bucket *bp;
@@ -880,7 +879,7 @@ declare_types()
 }
 
 
-declare_start()
+void declare_start(void)
 {
     register int c;
     register bucket *bp;
@@ -900,7 +899,7 @@ declare_start()
 }
 
 
-read_declarations()
+void read_declarations(void)
 {
     register int c, k;
 
@@ -1124,7 +1123,7 @@ insert_empty_rule()
 }
 
 
-add_symbol()
+void add_symbol(void)
 {
     register int c;
     register bucket *bp;
@@ -1155,7 +1154,7 @@ add_symbol()
 }
 
 
-copy_action()
+void copy_action(void)
 {
     register int c;
     register int i, n;
@@ -1397,7 +1396,7 @@ read_grammar()
 }
 
 
-free_tags()
+void free_tags(void)
 {
     register int i;
 
@@ -1696,7 +1695,7 @@ pack_grammar()
 }
 
 
-print_grammar()
+void print_grammar(void)
 {
     register int i, j, k;
     int spacing;
