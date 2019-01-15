$NetBSD: patch-pkgindb.c,v 1.1 2019/01/15 09:49:40 wiz Exp $

pkgindb.c:280:1: error: function 'pkgindb_sqlfail' could be declared with attribute 'noreturn' [-Werror,-Wmissing-noreturn]

--- pkgindb.c.orig	2018-09-20 12:31:51.000000000 +0000
+++ pkgindb.c
@@ -275,6 +275,7 @@ pkgindb_close(void)
 	sqlite3_close(pdb);
 }
 
+__attribute__((noreturn))
 static void
 pkgindb_sqlfail(void)
 {
