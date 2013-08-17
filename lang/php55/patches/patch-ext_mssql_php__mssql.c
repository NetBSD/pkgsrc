$NetBSD: patch-ext_mssql_php__mssql.c,v 1.2 2013/08/17 13:15:21 taca Exp $

--- ext/mssql/php_mssql.c.orig	2013-08-15 20:42:04.000000000 +0000
+++ ext/mssql/php_mssql.c
@@ -769,7 +769,7 @@ static void php_mssql_do_connect(INTERNA
 				dbfreelogin(mssql.login);
 				RETURN_FALSE;
 			}
-			link = (int) index_ptr->ptr;
+			link = (int)(long) index_ptr->ptr;
 			ptr = zend_list_find(link,&type);   /* check if the link is still there */
 			if (ptr && (type==le_link || type==le_plink)) {
 				zend_list_addref(link);
@@ -1122,7 +1122,7 @@ static void php_mssql_get_column_content
 			}
 			
 			res_length = 19;
-			spprintf(&res_buf, 0, "%d-%02d-%02d %02d:%02d:%02d" , dateinfo.year, dateinfo.month, dateinfo.day, dateinfo.hour, dateinfo.minute, dateinfo.second);
+			spprintf((char **)&res_buf, 0, "%d-%02d-%02d %02d:%02d:%02d" , dateinfo.year, dateinfo.month, dateinfo.day, dateinfo.hour, dateinfo.minute, dateinfo.second);
 		}
 
 		ZVAL_STRINGL(result, res_buf, res_length, 0);
