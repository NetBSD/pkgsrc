$NetBSD: patch-dbf.c,v 1.1 2017/03/30 15:54:03 adam Exp $

Avoid accessing elements past array's size.

--- dbf.c.orig	2017-03-30 15:50:09.000000000 +0000
+++ dbf.c
@@ -205,7 +205,7 @@ dbf_table *dbf_from_rdb(char *afname, ch
 		strcpy(rdb_f, afname);
 	else {
 		memcpy(rdb_f, afname, MAXPATH - 1);
-		rdb_f[MAXPATH] = '\0';
+		rdb_f[MAXPATH - 1] = '\0';
 	}
 
 
@@ -220,7 +220,7 @@ dbf_table *dbf_from_rdb(char *afname, ch
 			strcpy(t->filename, fname);
 		else {
 			memcpy(t->filename, fname, MAXPATH - 1);
-			t->filename[MAXPATH] = '\0';
+			t->filename[MAXPATH - 1] = '\0';
 		}
 
 		// first two lines are irrelevant
