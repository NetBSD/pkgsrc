$NetBSD: patch-sslh-select.c,v 1.1 2017/08/15 13:13:36 jperkin Exp $

Avoid queue variable conflict.

--- sslh-select.c.orig	2016-03-29 19:19:05.000000000 +0000
+++ sslh-select.c
@@ -131,7 +131,7 @@ int accept_new_connection(int listen_soc
 /* Connect queue 1 of connection to SSL; returns new file descriptor */
 int connect_queue(struct connection *cnx, fd_set *fds_r, fd_set *fds_w)
 {
-    struct queue *q = &cnx->q[1];
+    struct sslhqueue *q = &cnx->q[1];
 
     q->fd = connect_addr(cnx, cnx->q[0].fd);
     if ((q->fd != -1) && fd_is_in_range(q->fd)) {
@@ -156,7 +156,8 @@ int connect_queue(struct connection *cnx
 void shovel(struct connection *cnx, int active_fd, 
             fd_set *fds_r, fd_set *fds_w)
 {
-    struct queue *read_q, *write_q;
+    struct sslhqueue *read_q, *write_q;
+
 
     read_q = &cnx->q[active_fd];
     write_q = &cnx->q[1-active_fd];
