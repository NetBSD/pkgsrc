$NetBSD: patch-include_haproxy_server-t.h,v 1.2 2022/12/06 08:18:17 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/server-t.h.orig	2022-12-01 14:16:46.000000000 +0000
+++ include/haproxy/server-t.h
@@ -289,7 +289,7 @@ struct server {
 	unsigned int max_used_conns;            /* Max number of used connections (the counter is reset at each connection purges */
 	unsigned int est_need_conns;            /* Estimate on the number of needed connections (max of curr and previous max_used) */
 
-	struct queue queue;			/* pending connections */
+	struct haqueue queue;			/* pending connections */
 
 	/* Element below are usd by LB algorithms and must be doable in
 	 * parallel to other threads reusing connections above.
