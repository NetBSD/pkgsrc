$NetBSD: patch-spmd_fqdn__query.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Fix unused

--- spmd/fqdn_query.c.orig	2007-07-25 08:22:18.000000000 -0400
+++ spmd/fqdn_query.c	2018-05-28 19:43:35.179657737 -0400
@@ -163,10 +163,9 @@
 fqdn_query_response(struct task *t) 
 {
 	char data[MAX_UDP_DNS_SIZE];
-	int ret;
 
 	/* just discard */
-	ret = recvfrom(t->fd, data, sizeof(data), t->flags, t->sa, &(t->salen));
+	(void)recvfrom(t->fd, data, sizeof(data), t->flags, t->sa, &(t->salen));
 
 	spmd_free(t->sa);
 	close(t->fd);
@@ -178,9 +177,8 @@
 fqdn_query_send(struct task *t)
 {
 	struct task *newt = NULL;
-	int ret=0;
 
-	ret = sendto(t->fd, t->msg, t->len, t->flags, t->sa, t->salen);
+	(void)sendto(t->fd, t->msg, t->len, t->flags, t->sa, t->salen);
 
 	newt = task_alloc(0);
 	newt->fd = t->fd;
