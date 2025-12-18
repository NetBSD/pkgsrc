$NetBSD: patch-xymond_do__rrd.c,v 1.1 2025/12/18 10:09:22 wiz Exp $

Adapt for recent rrdtool.

--- xymond/do_rrd.c.orig	2025-12-18 09:56:14.972038243 +0000
+++ xymond/do_rrd.c
@@ -216,7 +216,7 @@ static void setupinterval(int intvl)
 static int flush_cached_updates(updcacheitem_t *cacheitem, char *newdata)
 {
 	/* Flush any updates we've cached */
-	char *updparams[5+CACHESZ+1] = { "rrdupdate", filedir, "-t", NULL, NULL, NULL, };
+	const char *updparams[5+CACHESZ+1] = { "rrdupdate", filedir, "-t", NULL, NULL, NULL, };
 	int i, pcount, result;
 
 	dbgprintf("Flushing '%s' with %d updates pending, template '%s'\n", 
@@ -378,7 +378,7 @@ static int create_and_update_rrd(char *h
 		 * we MUST reset this before every call.
 		 */
 		optind = opterr = 0; rrd_clear_error();
-		result = rrd_create(4+pcount, rrdcreate_params);
+		result = rrd_create(4+pcount, (const char **)rrdcreate_params);
 		xfree(rrdcreate_params);
 		if (rrakey) xfree(rrakey);
 
@@ -590,7 +590,7 @@ static int rrddatasets(char *hostname, c
 	struct stat st;
 
 	int result;
-	char *fetch_params[] = { "rrdfetch", filedir, "AVERAGE", "-s", "-30m", NULL };
+	const char *fetch_params[] = { "rrdfetch", filedir, "AVERAGE", "-s", "-30m", NULL };
 	time_t starttime, endtime;
 	unsigned long steptime, dscount;
 	rrd_value_t *rrddata;
