$NetBSD: patch-include_haproxy_server-t.h,v 1.6 2026/06/05 08:14:34 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/server-t.h.orig	2026-06-03 13:01:51.000000000 +0000
+++ include/haproxy/server-t.h
@@ -286,7 +286,7 @@ struct srv_per_thread {
 
 /* Each server will have one occurrence of this structure per thread group */
 struct srv_per_tgroup {
-	struct queue queue;			/* pending connections */
+	struct haqueue queue;			/* pending connections */
 	struct server *server;                  /* pointer to the corresponding server */
 	struct eb32_node lb_node;               /* node used for tree-based load balancing */
 	char *extra_counters_storage;           /* storage for extra_counters */
