$NetBSD: patch-sql.c,v 1.1 2022/02/20 20:43:31 gavan Exp $

--- sql.c.orig	2019-02-24 14:53:23.000000000 +0000
+++ sql.c
@@ -229,7 +229,7 @@ void db_connect(int type, MYSQL *mysql) 
 	timeout = 5;
 	rtimeout = 10;
 	wtimeout = 20;
-	my_bool reconnect = 1;
+	bool reconnect = 1;
 
 	mysql_init(mysql);
 
