$NetBSD: patch-include_haproxy_server-t.h,v 1.4 2024/09/30 17:09:27 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/server-t.h.orig	2024-09-19 12:07:01.000000000 +0000
+++ include/haproxy/server-t.h
@@ -347,7 +347,7 @@ struct server {
 	unsigned int max_used_conns;            /* Max number of used connections (the counter is reset at each connection purges */
 	unsigned int est_need_conns;            /* Estimate on the number of needed connections (max of curr and previous max_used) */
 
-	struct queue queue;			/* pending connections */
+	struct haqueue queue;			/* pending connections */
 	struct mt_list sess_conns;		/* list of private conns managed by a session on this server */
 	unsigned int dequeuing;                 /* non-zero = dequeuing in progress (atomic) */
 
