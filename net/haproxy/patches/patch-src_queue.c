$NetBSD: patch-src_queue.c,v 1.1 2021/12/09 10:36:07 jperkin Exp $

Avoid 'struct queue' conflict.

--- src/queue.c.orig	2021-11-23 14:40:21.000000000 +0000
+++ src/queue.c
@@ -178,7 +178,7 @@ static inline void pendconn_queue_unlock
  */
 void pendconn_unlink(struct pendconn *p)
 {
-	struct queue  *q  = p->queue;
+	struct haqueue  *q  = p->queue;
 	struct proxy  *px = q->px;
 	struct server *sv = q->sv;
 	uint oldidx;
@@ -423,7 +423,7 @@ struct pendconn *pendconn_add(struct str
 	struct pendconn *p;
 	struct proxy    *px;
 	struct server   *srv;
-	struct queue    *q;
+	struct haqueue    *q;
 	unsigned int *max_ptr;
 	unsigned int old_max, new_max;
 
