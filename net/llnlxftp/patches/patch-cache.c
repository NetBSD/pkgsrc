$NetBSD: patch-cache.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- cache.c.orig	2013-03-01 13:51:06.000000000 +0000
+++ cache.c
@@ -122,7 +122,7 @@ construct_cache_filename()
 /*
  * save_cache - Write current cache entries to .xftpcache.
  */
-save_cache()
+void save_cache(void)
 {
 	static FILE *fp;
 	struct host_link *hptr;
@@ -155,7 +155,7 @@ save_cache()
 /*
  * read_cache_from_file - Initialize cache entries with info from .xftpcache.
  */
-read_cache_from_file()
+void read_cache_from_file(void)
 {
 	FILE *fp;
 	char cache_line[MAXCLINE+1];
@@ -339,11 +339,7 @@ char *value;
  *                  flag is set, then the list is returned sorted,
  *                  otherwise it is returned in order of last use.
  */
-retrieve_cache(cache_id, hostname, list, sort)
-int cache_id;
-char *hostname;
-struct sl_struct **list;
-int sort;
+void retrieve_cache(int cache_id, char *hostname, struct sl_struct **list, int sort)
 {
 	char **values;
 	int indx;
