$NetBSD: patch-sslh-select.c,v 1.2 2022/01/01 16:47:21 rhialto Exp $

Avoid queue variable conflict.

--- sslh-select.c.orig	2021-08-28 14:33:20.000000000 +0000
+++ sslh-select.c
@@ -129,7 +129,7 @@ static struct connection* accept_new_con
 static int connect_queue(struct connection* cnx,
                          struct select_info* fd_info)
 {
-    struct queue *q = &cnx->q[1];
+    struct sslhqueue *q = &cnx->q[1];
 
     q->fd = connect_addr(cnx, cnx->q[0].fd, NON_BLOCKING);
     if ((q->fd != -1) && fd_is_in_range(q->fd)) {
@@ -153,7 +153,7 @@ static int connect_queue(struct connecti
  */
 static void shovel(struct connection *cnx, int active_fd, struct select_info* fd_info)
 {
-    struct queue *read_q, *write_q;
+    struct sslhqueue *read_q, *write_q;
 
     read_q = &cnx->q[active_fd];
     write_q = &cnx->q[1-active_fd];
