$NetBSD: patch-src_ev__evports.c,v 1.1 2021/12/09 10:36:07 jperkin Exp $

Upstream patch to remove deleted FD_UPDT_DEAD.

--- src/ev_evports.c.orig	2021-11-23 14:40:21.000000000 +0000
+++ src/ev_evports.c
@@ -250,10 +250,6 @@ static void _do_poll(struct poller *p, i
 		 */
 		ret = fd_update_events(fd, n);
 
-		/* If the FD was already dead , skip it */
-		if (ret == FD_UPDT_DEAD)
-			continue;
-
 		/* disable polling on this instance if the FD was migrated */
 		if (ret == FD_UPDT_MIGRATED) {
 			if (!HA_ATOMIC_BTS(&fdtab[fd].update_mask, tid))
