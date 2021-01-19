$NetBSD: patch-c__src_sqlite3__drv.c,v 1.1 2021/01/19 15:47:11 nia Exp $

Argument to ctype functions must fit into unsigned char.

--- c_src/sqlite3_drv.c.orig	2020-12-10 14:32:23.000000000 +0000
+++ c_src/sqlite3_drv.c
@@ -75,7 +75,7 @@ static inline int sql_is_insert(const ch
   int i;
   char *insert = "insert";
   for (i = 0; i < 6; i++) {
-    if ((tolower(sql[i]) != insert[i]) && (sql[i] != ' ')) { return 0; }
+    if ((tolower((unsigned char)sql[i]) != insert[i]) && (sql[i] != ' ')) { return 0; }
   }
   return 1;
 }
