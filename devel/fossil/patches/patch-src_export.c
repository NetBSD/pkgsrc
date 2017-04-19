$NetBSD: patch-src_export.c,v 1.1 2017/04/19 12:23:34 joerg Exp $

--- src/export.c.orig	2017-04-19 12:13:17.766852878 +0000
+++ src/export.c
@@ -511,6 +511,7 @@ void export_cmd(void){
   db_multi_exec("CREATE TEMPORARY TABLE oldblob(rid INTEGER PRIMARY KEY)");
   db_multi_exec("CREATE TEMPORARY TABLE oldcommit(rid INTEGER PRIMARY KEY)");
   db_multi_exec("CREATE TEMP TABLE xmark(tname TEXT UNIQUE, trid INT, tuuid TEXT)");
+  db_multi_exec("CREATE INDEX xmark_trid ON xmark(trid)");
   if( markfile_in!=0 ){
     Stmt qb,qc;
     FILE *f;
