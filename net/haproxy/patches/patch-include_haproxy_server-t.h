$NetBSD: patch-include_haproxy_server-t.h,v 1.1 2021/12/09 10:36:07 jperkin Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/server-t.h.orig	2021-11-23 14:40:21.000000000 +0000
+++ include/haproxy/server-t.h
@@ -282,7 +282,7 @@ struct server {
 	unsigned int est_need_conns;            /* Estimate on the number of needed connections (max of curr and previous max_used) */
 	unsigned int next_takeover;             /* thread ID to try to steal connections from next time */
 
-	struct queue queue;			/* pending connections */
+	struct haqueue queue;			/* pending connections */
 
 	/* Element below are usd by LB algorithms and must be doable in
 	 * parallel to other threads reusing connections above.
