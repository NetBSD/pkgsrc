$NetBSD: patch-memcached.c,v 1.2 2015/05/21 22:21:08 rodent Exp $

Fix this the right way thanks to joerg@.

--- memcached.c.orig	2015-01-01 07:50:52.000000000 +0000
+++ memcached.c
@@ -2764,8 +2764,8 @@ static void process_stats_conns(ADD_STAT
                 APPEND_NUM_STAT(i, "addr", "%s", conn_name);
                 APPEND_NUM_STAT(i, "state", "%s",
                         state_text(conns[i]->state));
-                APPEND_NUM_STAT(i, "secs_since_last_cmd", "%d",
-                        current_time - conns[i]->last_cmd_time);
+                APPEND_NUM_STAT(i, "secs_since_last_cmd", "%jd",
+                        (intmax_t)(current_time - conns[i]->last_cmd_time));
             }
         }
     }
