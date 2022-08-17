$NetBSD: patch-src_main_pgpool__logger.c,v 1.1 2022/08/17 17:05:14 tnn Exp $

Fix build on SunOS.

--- src/main/pgpool_logger.c.orig	2022-05-18 02:52:38.000000000 +0000
+++ src/main/pgpool_logger.c
@@ -1116,10 +1116,15 @@ set_next_rotation_time(void)
 	rotinterval = pool_config->log_rotation_age * SECS_PER_MINUTE;	/* convert to seconds */
 	now = (pg_time_t) time(NULL);
 	tm = localtime(&now);
-	now += tm->tm_gmtoff;
+#if defined(__sun__)
+	pg_time_t gmtoff = (pg_time_t)mktime(tm) - now;
+#else
+	pg_time_t gmtoff = (pg_time_t)tm->tm_gmtoff;
+#endif
+	now += gmtoff;
 	now -= now % rotinterval;
 	now += rotinterval;
-	now -= tm->tm_gmtoff;
+	now -= gmtoff;
 	next_rotation_time = now;
 }
 
