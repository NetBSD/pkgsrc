$NetBSD: patch-src_error.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Use standard headers.
Avoid implicit int.
Use C89.

--- src/error.c.orig	2012-10-26 12:50:41.000000000 +0000
+++ src/error.c
@@ -34,16 +34,15 @@
 #include "extspec.h"
 #include "mapline.h"
 
-#if STDC_HEADERS
+#include <ctype.h>
 #include <stdlib.h>
-#endif
+#include <string.h>
 
 int anterror;
 
 /******************************************************************************
                                                                   STARTERROR */
-static starterror (line)
-     long line;
+static void starterror (long line)
 {
   anterror++;
   if (line == 0)
@@ -57,8 +56,7 @@ static starterror (line)
 
 /* Feil som oppdages av LEX */
 
-lerror (errcode)
-     int errcode;
+void lerror(int errcode)
 {
   if (option_nowarning && (errcode == 8 || errcode == 32))
     return;
@@ -179,10 +177,7 @@ lerror (errcode)
 
 /* Feil som oppdages av YACC */
 
-/*VARARGS1 */
-yerror (errcode, txt)
-     int errcode;
-     char *txt;
+void yerror (int errcode, char *txt)
 {
   char c;
   starterror (lineno);
@@ -215,7 +210,7 @@ yerror (errcode, txt)
       exit (TRUE);
       break;
     case 21:
-      c = toupper ((int) txt[0]);
+      c = toupper ((unsigned char) txt[0]);
       txt++;
       fprintf (stderr, "%c%s.\n", c, txt);
       break;
@@ -250,9 +245,7 @@ yerror (errcode, txt)
 /* Feil som oppdages av DECL PASS 1 */
 
 /*VARARGS1 */
-d1error (errcode, name)
-     int errcode;
-     char *name;
+void d1error (int errcode, char *name)
 {
   starterror (lineno);
   switch (errcode)
@@ -293,10 +286,7 @@ d1error (errcode, name)
 /* Feil som oppdages av DECL PASS 2 */
 
 /*VARARGS1 */
-d2error (errcode, rd1, rd2)
-     int errcode;
-     struct DECL *rd1,
-      *rd2;
+void d2error (int errcode, struct DECL *rd1, struct DECL *rd2)
 {
   char *name1 = rd1->ident;
   starterror (errcode == 79 ? lineno : rd1->line);
@@ -460,10 +450,7 @@ textnumber (i)
 /* Feil som oppdages av SJEKKEREN */
 
 /*VARARGS1 */
-serror (errcode, name, ant)
-     int errcode,
-       ant;
-     char *name;
+void serror (int errcode, char *name, int ant)
 {
   char *antt;
   if (option_nowarning && errcode >= 81 && errcode <= 83 )
@@ -684,9 +671,7 @@ gerror (errcode, name)
 /* Feil som oppdages under innlesing av eksterne moduler */
 
 /*VARARGS1 */
-merror (errcode, name)
-     int errcode;
-     char *name;
+void merror (int errcode, char *name)
 {
   if (option_nowarning && errcode == 3 && option_atr)
     return;
