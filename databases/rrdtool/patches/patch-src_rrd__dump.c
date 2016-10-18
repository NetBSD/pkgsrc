$NetBSD: patch-src_rrd__dump.c,v 1.1 2016/10/18 21:22:12 he Exp $

Fix a signedness / unsigned conversion bug, causing overflow
of the timestamp for all but the last sample dumped (when timer is negative).

--- src/rrd_dump.c.orig	2016-04-19 15:52:25.000000000 +0000
+++ src/rrd_dump.c
@@ -422,7 +422,7 @@ int rrd_dump_cb_r(
             now = (rrd.live_head->last_up
                    - rrd.live_head->last_up
                    % (rrd.rra_def[i].pdp_cnt * rrd.stat_head->pdp_step))
-                + (timer * rrd.rra_def[i].pdp_cnt * rrd.stat_head->pdp_step);
+                + (timer * (long)rrd.rra_def[i].pdp_cnt * (long)rrd.stat_head->pdp_step);
 
             timer++;
 #if HAVE_STRFTIME
