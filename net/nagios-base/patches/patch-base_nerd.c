$NetBSD: patch-base_nerd.c,v 1.1.2.2 2016/02/08 10:12:10 bsiegert Exp $

64bit time_t workaround

--- base/nerd.c.orig	2016-02-07 21:13:59.000000000 +0100
+++ base/nerd.c	2016-02-07 21:14:15.000000000 +0100
@@ -337,7 +337,7 @@
 	} else
 		return 0;
 
-	asprintf(&buf, "%lu|%s|M|%s/%s|%06X\n", cr->finish_time.tv_sec,
+	asprintf(&buf, "%lu|%s|M|%s/%s|%06X\n", (unsigned long)cr->finish_time.tv_sec,
 			 check_result_source(cr), host_parent_path(h, '/'), name, color);
 	nerd_broadcast(chan_opath_checks_id, buf, strlen(buf));
 	free(buf);
