$NetBSD: patch-servers_slapd_back-sql_delete.c,v 1.1 2021/08/23 09:58:58 adam Exp $

SQL_NO_DATA is called SQL_NO_DATA_FOUND in ODBC versions >= 3.0,
as provided by databases/iodbc and databases/unixodbc.

--- servers/slapd/back-sql/delete.c.orig	2021-07-27 17:44:47.000000000 +0000
+++ servers/slapd/back-sql/delete.c
@@ -207,7 +207,7 @@ backsql_delete_int(
 
 	rc = SQLExecute( sth );
 	switch ( rc ) {
-	case SQL_NO_DATA:
+	case SQL_NO_DATA_FOUND:
 		/* apparently there were no "auxiliary" objectClasses
 		 * for this entry... */
 	case SQL_SUCCESS:
