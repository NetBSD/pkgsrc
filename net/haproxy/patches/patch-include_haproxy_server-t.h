$NetBSD: patch-include_haproxy_server-t.h,v 1.5 2025/05/29 20:36:26 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/server-t.h.orig	2025-05-28 14:35:14.000000000 +0000
+++ include/haproxy/server-t.h
@@ -273,7 +273,7 @@ struct srv_per_thread {
 
 /* Each server will have one occurrence of this structure per thread group */
 struct srv_per_tgroup {
-	struct queue queue;			/* pending connections */
+	struct haqueue queue;			/* pending connections */
 	struct server *server;                  /* pointer to the corresponding server */
 	struct eb32_node lb_node;               /* node used for tree-based load balancing */
 	struct server *next_full;               /* next server in the temporary full list */
