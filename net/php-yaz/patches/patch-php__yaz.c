$NetBSD: patch-php__yaz.c,v 1.1 2012/06/16 02:58:00 taca Exp $

* Use modern data structure name.

--- php_yaz.c.orig	2011-05-31 09:09:20.000000000 +0000
+++ php_yaz.c
@@ -148,7 +148,7 @@ static unsigned char third_argument_forc
 #endif
 
 
-function_entry yaz_functions [] = {
+zend_function_entry yaz_functions [] = {
 	PHP_FE(yaz_connect, NULL)
 	PHP_FE(yaz_close, NULL)
 	PHP_FE(yaz_search, NULL)
@@ -177,7 +177,7 @@ function_entry yaz_functions [] = {
 	{NULL, NULL, NULL}
 };
 
-static void get_assoc(INTERNAL_FUNCTION_PARAMETERS, pval *id, Yaz_Association *assocp)
+static void get_assoc(INTERNAL_FUNCTION_PARAMETERS, zval *id, Yaz_Association *assocp)
 {
 	Yaz_Association *as = 0;
 	
@@ -209,7 +209,7 @@ static void release_assoc(Yaz_Associatio
 
 static const char *array_lookup_string(HashTable *ht, const char *idx)
 {
-	pval **pvalue;
+	zval **pvalue;
 
 	if (ht && zend_hash_find(ht, (char *) idx, strlen(idx) + 1, (void **) &pvalue) == SUCCESS) {
 		SEPARATE_ZVAL(pvalue);
@@ -221,7 +221,7 @@ static const char *array_lookup_string(H
 
 static long *array_lookup_long(HashTable *ht, const char *idx)
 {
-	pval **pvalue;
+	zval **pvalue;
 
 	if (ht && zend_hash_find(ht, (char *) idx, strlen(idx) + 1, (void **) &pvalue) == SUCCESS) {
 		SEPARATE_ZVAL(pvalue);
@@ -233,7 +233,7 @@ static long *array_lookup_long(HashTable
 
 static long *array_lookup_bool(HashTable *ht, const char *idx)
 {
-	pval **pvalue;
+	zval **pvalue;
 
 	if (ht && zend_hash_find(ht, (char *) idx, strlen(idx) + 1, (void **) &pvalue) == SUCCESS) {
 		SEPARATE_ZVAL(pvalue);
@@ -309,7 +309,7 @@ PHP_FUNCTION(yaz_connect)
 	const char *preferredMessageSize = 0;
 	int persistent = 1;
 	int piggyback = 1;
-	pval *zurl, *user = 0;
+	zval *zurl, *user = 0;
 	Yaz_Association as;
 	int max_links = YAZSG(max_links);
 
@@ -463,7 +463,7 @@ PHP_FUNCTION(yaz_connect)
 PHP_FUNCTION(yaz_close)
 {
 	Yaz_Association p;
-	pval *id;
+	zval *id;
 
 	if (ZEND_NUM_ARGS() != 1) {
 		WRONG_PARAM_COUNT;
@@ -487,7 +487,7 @@ PHP_FUNCTION(yaz_close)
 PHP_FUNCTION(yaz_search)
 {
 	char *query_str, *type_str;
-	pval *id, *type, *query;
+	zval *id, *type, *query;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() == 3) {
@@ -554,7 +554,7 @@ PHP_FUNCTION(yaz_search)
    Retrieve records */
 PHP_FUNCTION(yaz_present)
 {
-	pval *id;
+	zval *id;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 1) {
@@ -585,7 +585,7 @@ PHP_FUNCTION(yaz_present)
    Process events. */
 PHP_FUNCTION(yaz_wait)
 {
-	pval *pval_options = 0;
+	zval *pval_options = 0;
 	int event_mode = 0;
 	int no = 0;
 	ZOOM_connection conn_ar[MAX_ASSOC];
@@ -660,7 +660,7 @@ PHP_FUNCTION(yaz_wait)
    Return last error number (>0 for bib-1 diagnostic, <0 for other error, 0 for no error */
 PHP_FUNCTION(yaz_errno)
 {
-	pval *id;
+	zval *id;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 1 || GET_PARM1(&id) == FAILURE) {
@@ -679,7 +679,7 @@ PHP_FUNCTION(yaz_errno)
    Return last error message */
 PHP_FUNCTION(yaz_error)
 {
-	pval *id;
+	zval *id;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 1 ||	GET_PARM1(&id) == FAILURE) {
@@ -706,7 +706,7 @@ PHP_FUNCTION(yaz_error)
    Return additional info for last error (empty string if none) */
 PHP_FUNCTION(yaz_addinfo)
 {
-	pval *id;
+	zval *id;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 1 || GET_PARM1(&id) == FAILURE) {
@@ -729,7 +729,7 @@ PHP_FUNCTION(yaz_addinfo)
    Return number of hits (result count) for last search */
 PHP_FUNCTION(yaz_hits)
 {
-	pval *id, *searchresult = 0;
+	zval *id, *searchresult = 0;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() == 1) {
@@ -1339,7 +1339,7 @@ static void ext_grs1(zval *return_value,
    Return record information at given result set position */
 PHP_FUNCTION(yaz_record)
 {
-	pval *pval_id, *pval_pos, *pval_type;
+	zval *pval_id, *pval_pos, *pval_type;
 	Yaz_Association p;
 	int pos;
 	char *type;
@@ -1406,7 +1406,7 @@ PHP_FUNCTION(yaz_record)
    Set record syntax for retrieval */
 PHP_FUNCTION(yaz_syntax)
 {
-	pval *pval_id, *pval_syntax;
+	zval *pval_id, *pval_syntax;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 2 ||
@@ -1425,7 +1425,7 @@ PHP_FUNCTION(yaz_syntax)
    Set Element-Set-Name for retrieval */
 PHP_FUNCTION(yaz_element)
 {
-	pval *pval_id, *pval_element;
+	zval *pval_id, *pval_element;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 2 ||
@@ -1445,7 +1445,7 @@ PHP_FUNCTION(yaz_element)
    Set Schema for retrieval */
 PHP_FUNCTION(yaz_schema)
 {
-	pval *pval_id, *pval_element;
+	zval *pval_id, *pval_element;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 2 ||
@@ -1464,7 +1464,7 @@ PHP_FUNCTION(yaz_schema)
    Set Option(s) for connection */
 PHP_FUNCTION(yaz_set_option)
 {
-	pval *pval_ar, *pval_name, *pval_val, *pval_id;
+	zval *pval_ar, *pval_name, *pval_val, *pval_id;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() == 2) {
@@ -1519,7 +1519,7 @@ PHP_FUNCTION(yaz_set_option)
    Set Option(s) for connection */
 PHP_FUNCTION(yaz_get_option)
 {
-	pval *pval_id, *pval_name;
+	zval *pval_id, *pval_name;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 2) {
@@ -1553,7 +1553,7 @@ PHP_FUNCTION(yaz_get_option)
    Set result set start point and number of records to request */
 PHP_FUNCTION(yaz_range)
 {
-	pval *pval_id, *pval_start, *pval_number;
+	zval *pval_id, *pval_start, *pval_number;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 3 ||
@@ -1574,7 +1574,7 @@ PHP_FUNCTION(yaz_range)
    Set result set sorting criteria */
 PHP_FUNCTION(yaz_sort)
 {
-	pval *pval_id, *pval_criteria;
+	zval *pval_id, *pval_criteria;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 2 ||
@@ -1604,7 +1604,7 @@ const char *ill_array_lookup(void *handl
    Sends Item Order request */
 PHP_FUNCTION(yaz_itemorder)
 {
-	pval *pval_id, *pval_package;
+	zval *pval_id, *pval_package;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 2 ||
@@ -1636,7 +1636,7 @@ PHP_FUNCTION(yaz_itemorder)
    Sends Extended Services Request */
 PHP_FUNCTION(yaz_es)
 {
-	pval *pval_id, *pval_type, *pval_package;
+	zval *pval_id, *pval_type, *pval_package;
 	Yaz_Association p;
 	
 	if (ZEND_NUM_ARGS() != 3 ||
@@ -1673,7 +1673,7 @@ PHP_FUNCTION(yaz_es)
    Sends Scan Request */
 PHP_FUNCTION(yaz_scan)
 {
-	pval *pval_id, *pval_type, *pval_query, *pval_flags = 0;
+	zval *pval_id, *pval_type, *pval_query, *pval_flags = 0;
 	HashTable *flags_ht = 0;
 	Yaz_Association p;
 
@@ -1716,7 +1716,7 @@ PHP_FUNCTION(yaz_scan)
    Inspects Extended Services Result */
 PHP_FUNCTION(yaz_es_result)
 {
-	pval *pval_id;
+	zval *pval_id;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 1 ||	GET_PARM1(&pval_id) == FAILURE) {
@@ -1747,7 +1747,7 @@ PHP_FUNCTION(yaz_es_result)
    Inspects Scan Result */
 PHP_FUNCTION(yaz_scan_result)
 {
-	pval *pval_id, *pval_opt = 0;
+	zval *pval_id, *pval_opt = 0;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() == 2) {
@@ -1834,7 +1834,7 @@ PHP_FUNCTION(yaz_scan_result)
    Configure CCL package */
 PHP_FUNCTION(yaz_ccl_conf)
 {
-	pval *pval_id, *pval_package;
+	zval *pval_id, *pval_package;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 2 ||
@@ -1881,7 +1881,7 @@ PHP_FUNCTION(yaz_ccl_conf)
    Parse a CCL query */
 PHP_FUNCTION(yaz_ccl_parse)
 {
-	pval *pval_id, *pval_query, *pval_res = 0;
+	zval *pval_id, *pval_query, *pval_res = 0;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 3 || GET_PARM3( &pval_id, &pval_query, &pval_res)
@@ -1964,7 +1964,7 @@ PHP_FUNCTION(yaz_ccl_parse)
    Specify the databases within a session */
 PHP_FUNCTION(yaz_database)
 {
-	pval *pval_id, *pval_database;
+	zval *pval_id, *pval_database;
 	Yaz_Association p;
 
 	if (ZEND_NUM_ARGS() != 2 ||
