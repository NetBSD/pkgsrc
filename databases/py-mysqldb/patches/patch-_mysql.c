$NetBSD: patch-_mysql.c,v 1.2 2021/10/06 18:00:12 tron Exp $

Use official MySQL API to fix build with latest version of MariaDB

--- _mysql.c.orig	2017-01-04 12:47:08.000000000 +0000
+++ _mysql.c	2021-10-06 18:21:05.978598645 +0100
@@ -1908,7 +1908,11 @@
 	int r, reconnect = -1;
 	if (!PyArg_ParseTuple(args, "|I", &reconnect)) return NULL;
 	check_connection(self);
-	if ( reconnect != -1 ) self->connection.reconnect = reconnect;
+	if ( reconnect != -1 ) {
+        	my_bool my_reconnect = reconnect != 0;
+        	mysql_options(&self->connection, MYSQL_OPT_RECONNECT,
+			      &my_reconnect);
+        }
 	Py_BEGIN_ALLOW_THREADS
 	r = mysql_ping(&(self->connection));
 	Py_END_ALLOW_THREADS
