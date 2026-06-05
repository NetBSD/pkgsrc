$NetBSD: patch-include_haproxy_queue-t.h,v 1.2 2026/06/05 08:14:34 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/queue-t.h.orig	2026-06-03 13:01:51.000000000 +0000
+++ include/haproxy/queue-t.h
@@ -29,19 +29,19 @@
 struct proxy;
 struct server;
 struct stream;
-struct queue;
+struct haqueue;
 
 struct pendconn {
 	int            strm_flags; /* stream flags */
 	unsigned int   queue_idx;  /* value of proxy/server queue_idx at time of enqueue */
 	struct stream *strm;
-	struct queue  *queue;      /* the queue the entry is queued into */
+	struct haqueue  *queue;      /* the queue the entry is queued into */
 	struct server *target;     /* the server that was assigned, = srv except if srv==NULL */
 	struct eb32_node node;
 	__decl_thread(HA_SPINLOCK_T del_lock);  /* use before removal, always under queue's lock */
 };
 
-struct queue {
+struct haqueue {
 	struct eb_root head;                    /* queued pendconns */
 	struct proxy  *px;                      /* the proxy we're waiting for, never NULL in queue */
 	struct server *sv;                      /* the server we are waiting for, may be NULL if don't care */
