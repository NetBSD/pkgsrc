$NetBSD: patch-include_haproxy_queue-t.h,v 1.1 2021/12/09 10:36:07 jperkin Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/queue-t.h.orig	2021-11-23 14:40:21.000000000 +0000
+++ include/haproxy/queue-t.h
@@ -28,19 +28,19 @@
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
 	struct eb_root head;                    /* queued pendconnds */
 	struct proxy  *px;                      /* the proxy we're waiting for, never NULL in queue */
 	struct server *sv;                      /* the server we are waiting for, may be NULL if don't care */
