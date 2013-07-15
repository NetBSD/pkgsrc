$NetBSD: patch-php__mssql.c,v 1.1.16.1 2013/07/15 22:32:24 tron Exp $

Fix with newer freetds:

* cast pointer => long => int, hoping values are ranges in int.
* Don't pass unsigned char ** to spprintf().

--- ext/mssql/php_mssql.c.orig	2013-07-10 17:43:08.000000000 +0000
+++ ext/mssql/php_mssql.c
@@ -764,7 +764,7 @@ static void php_mssql_do_connect(INTERNA
 				dbfreelogin(mssql.login);
 				RETURN_FALSE;
 			}
-			link = (int) index_ptr->ptr;
+			link = (int)(long) index_ptr->ptr;
 			ptr = zend_list_find(link,&type);   /* check if the link is still there */
 			if (ptr && (type==le_link || type==le_plink)) {
 				zend_list_addref(link);
@@ -1117,7 +1117,7 @@ static void php_mssql_get_column_content
 			}
 			
 			res_length = 19;
-			spprintf(&res_buf, 0, "%d-%02d-%02d %02d:%02d:%02d" , dateinfo.year, dateinfo.month, dateinfo.day, dateinfo.hour, dateinfo.minute, dateinfo.second);
+			spprintf((char **)&res_buf, 0, "%d-%02d-%02d %02d:%02d:%02d" , dateinfo.year, dateinfo.month, dateinfo.day, dateinfo.hour, dateinfo.minute, dateinfo.second);
 		}
 
 		ZVAL_STRINGL(result, res_buf, res_length, 0);
