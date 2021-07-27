$NetBSD: patch-_mysql.c,v 1.1 2021/07/27 23:21:23 tron Exp $

Use official MySQL API to fix build with latest version of MariaDB

--- _mysql.c.orig	2014-01-02 13:52:50.000000000 +0000
+++ _mysql.c	2021-07-28 00:17:13.849678370 +0100
@@ -40,8 +40,6 @@
 #include "structmember.h"
 #if defined(MS_WINDOWS)
 #include <config-win.h>
-#else
-#include "my_config.h"
 #endif
 #include "mysql.h"
 #include "mysqld_error.h"
@@ -2002,7 +2000,11 @@
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
