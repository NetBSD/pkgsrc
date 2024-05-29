$NetBSD: patch-include_haproxy_server-t.h,v 1.3 2024/05/29 20:27:50 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/server-t.h.orig	2024-05-29 12:43:38.000000000 +0000
+++ include/haproxy/server-t.h
@@ -347,7 +347,7 @@ struct server {
 	unsigned int max_used_conns;            /* Max number of used connections (the counter is reset at each connection purges */
 	unsigned int est_need_conns;            /* Estimate on the number of needed connections (max of curr and previous max_used) */
 
-	struct queue queue;			/* pending connections */
+	struct haqueue queue;			/* pending connections */
 	struct mt_list sess_conns;		/* list of private conns managed by a session on this server */
 
 	/* Element below are usd by LB algorithms and must be doable in
