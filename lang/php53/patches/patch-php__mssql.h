$NetBSD: patch-php__mssql.h,v 1.1 2011/09/12 16:24:32 taca Exp $

* Use definition in freetds.

--- ext/mssql/php_mssql.h.orig	2011-01-01 02:19:59.000000000 +0000
+++ ext/mssql/php_mssql.h
@@ -65,7 +65,6 @@ typedef short TDS_SHORT;
 #define dbfreelogin dbloginfree
 #endif
 #define dbrpcexec dbrpcsend
-typedef unsigned char	*LPBYTE;
 typedef float           DBFLT4;
 #else
 #define MSSQL_VERSION "7.0"
