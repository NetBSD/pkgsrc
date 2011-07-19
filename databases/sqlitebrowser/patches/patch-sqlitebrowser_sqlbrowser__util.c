$NetBSD: patch-sqlitebrowser_sqlbrowser__util.c,v 1.1 2011/07/19 00:34:17 ryoon Exp $

--- sqlitebrowser/sqlbrowser_util.c.orig	2005-03-23 14:56:39.000000000 +0000
+++ sqlitebrowser/sqlbrowser_util.c
@@ -358,7 +358,7 @@ static int _is_command_terminator(const 
 }
 
 
-char *getline(FILE *in){
+char *sbgetline(FILE *in){
   char *zLine;
   int nLine;
   int n;
@@ -402,7 +402,7 @@ void process_input(sqlite3 * db, FILE *i
   char * zErrMsg = 0;
   int nSql = 0;
   int rc;
-  while((zLine = getline(in))!=0 ){
+  while((zLine = sbgetline(in))!=0 ){
     if( (zSql==0 || zSql[0]==0) && _all_whitespace(zLine) ) continue;
 	(*lineErr)++;
     if( zSql==0 ){
