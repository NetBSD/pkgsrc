$NetBSD: patch-memcached.c,v 1.3 2019/09/05 09:34:51 adam Exp $

time_t changes

--- memcached.c.orig	2019-08-29 22:13:13.000000000 +0000
+++ memcached.c
@@ -3593,8 +3593,8 @@ static void process_stats_conns(ADD_STAT
                 }
                 APPEND_NUM_STAT(i, "state", "%s",
                         state_text(conns[i]->state));
-                APPEND_NUM_STAT(i, "secs_since_last_cmd", "%d",
-                        current_time - conns[i]->last_cmd_time);
+                APPEND_NUM_STAT(i, "secs_since_last_cmd", "%jd",
+                        (intmax_t)(current_time - conns[i]->last_cmd_time));
             }
         }
     }
