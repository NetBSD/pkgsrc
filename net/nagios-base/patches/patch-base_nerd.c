$NetBSD: patch-base_nerd.c,v 1.3 2023/01/08 23:33:59 sekiya Exp $

64-bit time_t workaround

--- base/nerd.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ base/nerd.c	2023-01-09 06:59:24.364895991 +0900
@@ -359,7 +359,7 @@
 	} else
 		return 0;
 
-	asprintf(&buf, "%lu|%s|M|%s/%s|%06X\n", cr->finish_time.tv_sec,
+	asprintf(&buf, "%lu|%s|M|%s/%s|%06X\n", (unsigned long)cr->finish_time.tv_sec,
 			 check_result_source(cr), host_parent_path(h, '/'), name, color);
 	nerd_broadcast(chan_opath_checks_id, buf, strlen(buf));
 	free(buf);
