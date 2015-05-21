$NetBSD: patch-memcached.c,v 1.1 2015/05/21 14:07:10 rodent Exp $

Silences: format specifies type 'int' but the argument has type 'long'

--- memcached.c.orig	2015-01-01 07:50:52.000000000 +0000
+++ memcached.c
@@ -2765,7 +2765,7 @@ static void process_stats_conns(ADD_STAT
                 APPEND_NUM_STAT(i, "state", "%s",
                         state_text(conns[i]->state));
                 APPEND_NUM_STAT(i, "secs_since_last_cmd", "%d",
-                        current_time - conns[i]->last_cmd_time);
+                        (int)(current_time - conns[i]->last_cmd_time));
             }
         }
     }
