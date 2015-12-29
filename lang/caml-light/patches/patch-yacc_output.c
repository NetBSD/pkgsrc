$NetBSD: patch-yacc_output.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.
Mark private functions static.

--- yacc/output.c.orig	2012-10-20 13:08:10.000000000 +0000
+++ yacc/output.c
@@ -16,6 +16,9 @@ static short *check;
 static int lowzero;
 static int high;
 
+static void output_trailing_text(void);
+static void output_stored_text(void);
+static void save_column(int symbol, int default_state);
 
 output()
 {
@@ -323,9 +326,7 @@ int symbol;
 
 
 
-save_column(symbol, default_state)
-int symbol;
-int default_state;
+static void save_column(int symbol, int default_state)
 {
     register int i;
     register int m;
@@ -726,7 +727,7 @@ output_transl()
   fprintf(code_file, "    0|];;\n\n");
 }
 
-output_stored_text()
+static void output_stored_text(void)
 {
     register int c;
     register FILE *in, *out;
@@ -757,7 +758,7 @@ output_debug()
 {
 }
 
-output_trailing_text()
+void output_trailing_text()
 {
     register int c, last;
     register FILE *in, *out;
@@ -814,7 +815,7 @@ output_trailing_text()
 }
 
 
-copy_file(file, file_name)
+void copy_file(file, file_name)
      FILE ** file;
      char * file_name;
 {
