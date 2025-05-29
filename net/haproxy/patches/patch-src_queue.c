$NetBSD: patch-src_queue.c,v 1.3 2025/05/29 20:36:26 adam Exp $

Avoid 'struct queue' conflict.

--- src/queue.c.orig	2025-05-28 14:35:14.000000000 +0000
+++ src/queue.c
@@ -177,7 +177,7 @@ static inline void pendconn_queue_unlock
  */
 void pendconn_unlink(struct pendconn *p)
 {
-	struct queue  *q  = p->queue;
+	struct haqueue  *q  = p->queue;
 	struct proxy  *px = q->px;
 	struct server *sv = q->sv;
 	uint oldidx;
@@ -555,7 +555,7 @@ struct pendconn *pendconn_add(struct str
 	struct pendconn *p;
 	struct proxy    *px;
 	struct server   *srv;
-	struct queue    *q;
+	struct haqueue    *q;
 	unsigned int *max_ptr;
 	unsigned int *queueslength;
 	unsigned int old_max, new_max;
@@ -628,7 +628,7 @@ int pendconn_redistribute(struct server
 		goto skip_srv_queue;
 
 	for (i = 0; i < global.nbtgroups; i++) {
-		struct queue *queue = &s->per_tgrp[i].queue;
+		struct haqueue *queue = &s->per_tgrp[i].queue;
 		int local_xferred = 0;
 
 		HA_SPIN_LOCK(QUEUE_LOCK, &queue->lock);
@@ -663,7 +663,7 @@ int pendconn_redistribute(struct server
 		goto done;
 
 	for (i = 0; i < global.nbtgroups; i++) {
-		struct queue *queue = &px->per_tgrp[i].queue;
+		struct haqueue *queue = &px->per_tgrp[i].queue;
 		int local_xferred = 0;
 
 		HA_SPIN_LOCK(QUEUE_LOCK, &queue->lock);
