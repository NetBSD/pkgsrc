$NetBSD: patch-res_res__config__pgsql.c,v 1.1 2014/07/02 03:06:24 jnemeth Exp $

--- res/res_config_pgsql.c.orig	2014-05-02 19:50:07.000000000 +0000
+++ res/res_config_pgsql.c
@@ -247,12 +247,14 @@ static int pgsql_exec(const char *databa
 	return -1;
 }
 
+RAII_DECL(PGresult *, result, PQclear);
+
 static struct tables *find_table(const char *database, const char *orig_tablename)
 {
 	struct columns *column;
 	struct tables *table;
 	struct ast_str *sql = ast_str_thread_get(&findtable_buf, 330);
-	RAII_VAR(PGresult *, result, NULL, PQclear);
+	RAII_VAR(PGresult *, result, NULL);
 	int exec_result;
 	char *fname, *ftype, *flen, *fnotnull, *fdef;
 	int i, rows;
@@ -416,7 +418,7 @@ static struct columns *find_column(struc
 
 static struct ast_variable *realtime_pgsql(const char *database, const char *tablename, va_list ap)
 {
-	RAII_VAR(PGresult *, result, NULL, PQclear);
+	RAII_VAR(PGresult *, result, NULL);
 	int num_rows = 0, pgresult;
 	struct ast_str *sql = ast_str_thread_get(&sql_buf, 100);
 	struct ast_str *escapebuf = ast_str_thread_get(&escapebuf_buf, 100);
@@ -531,7 +533,7 @@ static struct ast_variable *realtime_pgs
 
 static struct ast_config *realtime_multi_pgsql(const char *database, const char *table, va_list ap)
 {
-	RAII_VAR(PGresult *, result, NULL, PQclear);
+	RAII_VAR(PGresult *, result, NULL);
 	int num_rows = 0, pgresult;
 	struct ast_str *sql = ast_str_thread_get(&sql_buf, 100);
 	struct ast_str *escapebuf = ast_str_thread_get(&escapebuf_buf, 100);
@@ -688,7 +690,7 @@ static struct ast_config *realtime_multi
 static int update_pgsql(const char *database, const char *tablename, const char *keyfield,
 						const char *lookup, va_list ap)
 {
-	RAII_VAR(PGresult *, result, NULL, PQclear);
+	RAII_VAR(PGresult *, result, NULL);
 	int numrows = 0, pgresult;
 	const char *newparam, *newval;
 	struct ast_str *sql = ast_str_thread_get(&sql_buf, 100);
@@ -819,7 +821,7 @@ static int update_pgsql(const char *data
 
 static int update2_pgsql(const char *database, const char *tablename, va_list ap)
 {
-	RAII_VAR(PGresult *, result, NULL, PQclear);
+	RAII_VAR(PGresult *, result, NULL);
 	int numrows = 0, pgresult, first = 1;
 	struct ast_str *escapebuf = ast_str_thread_get(&escapebuf_buf, 16);
 	const char *newparam, *newval;
@@ -933,7 +935,7 @@ static int update2_pgsql(const char *dat
 
 static int store_pgsql(const char *database, const char *table, va_list ap)
 {
-	RAII_VAR(PGresult *, result, NULL, PQclear);
+	RAII_VAR(PGresult *, result, NULL);
 	int numrows;
 	struct ast_str *buf = ast_str_thread_get(&escapebuf_buf, 256);
 	struct ast_str *sql1 = ast_str_thread_get(&sql_buf, 256);
@@ -1014,7 +1016,7 @@ static int store_pgsql(const char *datab
 
 static int destroy_pgsql(const char *database, const char *table, const char *keyfield, const char *lookup, va_list ap)
 {
-	RAII_VAR(PGresult *, result, NULL, PQclear);
+	RAII_VAR(PGresult *, result, NULL);
 	int numrows = 0;
 	int pgresult;
 	struct ast_str *sql = ast_str_thread_get(&sql_buf, 256);
@@ -1096,7 +1098,7 @@ static struct ast_config *config_pgsql(c
 									   const char *file, struct ast_config *cfg,
 									   struct ast_flags flags, const char *suggested_incl, const char *who_asked)
 {
-	RAII_VAR(PGresult *, result, NULL, PQclear);
+	RAII_VAR(PGresult *, result, NULL);
 	long num_rows;
 	struct ast_variable *new_v;
 	struct ast_category *cur_cat = NULL;
