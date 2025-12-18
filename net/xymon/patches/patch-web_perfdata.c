$NetBSD: patch-web_perfdata.c,v 1.1 2025/12/18 10:09:22 wiz Exp $

Adapt for recent rrdtool.

--- web/perfdata.c.orig	2025-12-18 10:01:33.866390199 +0000
+++ web/perfdata.c
@@ -111,7 +111,7 @@ int oneset(char *hostname, char *rrdname
 	rrdargs[9] = NULL;
 
 	optind = opterr = 0; rrd_clear_error();
-	result = rrd_fetch(9, rrdargs,
+	result = rrd_fetch(9, (const char **)rrdargs,
 			   &start, &end, &step, &dscount, &dsnames, &data);
 
 	if (result != 0) {
