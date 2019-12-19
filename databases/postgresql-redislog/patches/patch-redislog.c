$NetBSD: patch-redislog.c,v 1.1 2019/12/19 22:11:27 joerg Exp $

--- redislog.c.orig	2019-12-19 19:52:09.231017694 +0000
+++ redislog.c
@@ -65,8 +65,8 @@ int   Redislog_timeout = 1000;
 char  *Redislog_key = NULL;
 int   Redislog_min_error_statement = ERROR;
 int   Redislog_min_messages = WARNING;
-bool  Redislog_ship_to_redis_only = TRUE;
-bool  Redislog_shuffle_hosts = TRUE;
+bool  Redislog_ship_to_redis_only = true;
+bool  Redislog_shuffle_hosts = true;
 char  *Redislog_fields = NULL;
 
 static MemoryContext	redislog_cfg_memory_context;
@@ -1353,7 +1353,7 @@ _PG_init(void)
 	  "in case no Redis service is available. "
 	  "By default it is set to false.",
 	  &Redislog_ship_to_redis_only,
-	  FALSE,
+	  false,
 	  PGC_SUSET,
 	  GUC_NOT_IN_SAMPLE,
 	  NULL,
@@ -1365,7 +1365,7 @@ _PG_init(void)
 	  "Shuffle the list of available Redis server in order to"
 	  "balance events servers",
 	  &Redislog_shuffle_hosts,
-	  TRUE,
+	  true,
 	  PGC_SUSET,
 	  GUC_NOT_IN_SAMPLE,
 	  NULL,
