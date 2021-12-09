$NetBSD: patch-include_haproxy_queue.h,v 1.1 2021/12/09 10:36:07 jperkin Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/queue.h.orig	2021-11-23 14:40:21.000000000 +0000
+++ include/haproxy/queue.h
@@ -114,7 +114,7 @@ static inline int queue_limit_offset(int
  * has a valid proxy and NULL for the server queue. This is how they're
  * distinguished during operations.
  */
-static inline void queue_init(struct queue *queue, struct proxy *px, struct server *sv)
+static inline void queue_init(struct haqueue *queue, struct proxy *px, struct server *sv)
 {
 	queue->head = EB_ROOT;
 	queue->length = 0;
