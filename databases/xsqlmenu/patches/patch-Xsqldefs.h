$NetBSD: patch-Xsqldefs.h,v 1.1 2020/05/09 15:19:33 joerg Exp $

mysql_connect is gone.

--- Xsqldefs.h.orig	2020-05-09 01:21:30.054455724 +0000
+++ Xsqldefs.h
@@ -34,7 +34,8 @@
 #define sql_list_tables(sock, wild)  mysql_list_tables(sock, wild)
 #define sql_list_fields(sock, table, wild)  mysql_list_fields(sock, table, wild)
 #define sql_select_db(sock, db)   mysql_select_db(sock, db)
-#define sql_connect(sock, server, user, pass) mysql_connect(sock, server, user, pass)
+#define sql_connect(sock, server, user, pass) mysql_real_connect(sock, server, user, pass, NULL, 0, NULL, 0)
+
 #define sql_query(sock, query)    mysql_query(sock, query)
 #define sql_close(sock)           mysql_close(sock)
 #define SQL_FIELD                 MYSQL_FIELD
