$NetBSD: patch-Drivers_Postgre7.1_info.c,v 1.1 2024/08/05 13:20:08 tnn Exp $

info.c:1868:63: error: passing argument 6 of 'PG_SQLBindCol' from incompatible pointer type [-Wincompatible-pointer-types]
info.c:1934:44: error: passing argument 6 of 'PG_SQLBindCol' from incompatible pointer type [-Wincompatible-pointer-types]
info.c:2220:51: error: passing argument 6 of 'PG_SQLBindCol' from incompatible pointer type [-Wincompatible-pointer-types]

--- Drivers/Postgre7.1/info.c.orig	2024-08-05 14:46:06.887870206 +0000
+++ Drivers/Postgre7.1/info.c
@@ -1779,14 +1779,14 @@ char *table_name;
 char index_name[MAX_INFO_STRING];
 short fields_vector[8];
 char isunique[10], isclustered[10];
-SDWORD index_name_len, fields_vector_len;
+SQLLEN index_name_len, fields_vector_len;
 TupleNode *row;
 int i;
 HSTMT hcol_stmt;
 StatementClass *col_stmt, *indx_stmt;
 char column_name[MAX_INFO_STRING], relhasrules[MAX_INFO_STRING];
 char **column_names = 0;
-Int4 column_name_len;
+SQLLEN column_name_len;
 int total_columns = 0;
 char error = TRUE;
 ConnInfo *ci;
@@ -2136,7 +2136,7 @@ HSTMT htbl_stmt;
 StatementClass *tbl_stmt;
 char tables_query[STD_STATEMENT_LEN];
 char attname[MAX_INFO_STRING];
-SDWORD attname_len;
+SQLLEN attname_len;
 char pktab[MAX_TABLE_LEN + 1];
 Int2 result_cols;
 
