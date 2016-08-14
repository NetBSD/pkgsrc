$NetBSD: patch-src_eparse.y,v 1.1 2016/08/14 18:27:05 scole Exp $

Rename strtonum to strtonumber so will not get errors about duplicate functions.

--- src/eparse.y.orig	2008-02-04 23:11:38.000000000 -0500
+++ src/eparse.y	2016-04-17 13:31:45.000000000 -0400
@@ -34,7 +34,7 @@
 extern int yylex (void );
 static REG convert(char);
 static REG rd8(REG);
-static REG strtonum(char *, int);
+static REG strtonumber(char *, int);
 static void yyerror(char *);
 
 %}
@@ -164,18 +164,18 @@
         ;
 
 count   : based
-        | NOBASE                { $$ = strtonum($1, 10); }
+        | NOBASE                { $$ = strtonumber($1, 10); }
         ;
 
 number  : based
-        | NOBASE                { $$ = strtonum($1, 16); }
-        | NPFXHEX               { $$ = strtonum($1, 16); }
+        | NOBASE                { $$ = strtonumber($1, 16); }
+        | NPFXHEX               { $$ = strtonumber($1, 16); }
         ;
 
-based   : BIN                   { $$ = strtonum($1, 2); }
-        | OCT                   { $$ = strtonum($1, 8); }
-        | DEC                   { $$ = strtonum($1, 10); }
-        | HEX                   { $$ = strtonum($1, 16); }
+based   : BIN                   { $$ = strtonumber($1, 2); }
+        | OCT                   { $$ = strtonumber($1, 8); }
+        | DEC                   { $$ = strtonumber($1, 10); }
+        | HEX                   { $$ = strtonumber($1, 16); }
         ;
 
 %%
@@ -197,7 +197,7 @@
     return memMRd(0, addr, 8, &dval) ? dval : 0;
 }
 
-static REG strtonum(char *str, int base)
+static REG strtonumber(char *str, int base)
 {
     REG num = 0;
 
