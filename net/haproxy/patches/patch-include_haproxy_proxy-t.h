$NetBSD: patch-include_haproxy_proxy-t.h,v 1.2 2024/05/29 20:27:50 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/proxy-t.h.orig	2024-05-29 12:43:38.000000000 +0000
+++ include/haproxy/proxy-t.h
@@ -350,7 +350,7 @@ struct proxy {
 	__decl_thread(HA_RWLOCK_T lock);        /* may be taken under the server's lock */
 
 	char *id, *desc;			/* proxy id (name) and description */
-	struct queue queue;			/* queued requests (pendconns) */
+	struct haqueue queue;			/* queued requests (pendconns) */
 	int totpend;				/* total number of pending connections on this instance (for stats) */
 	unsigned int feconn, beconn;		/* # of active frontend and backends streams */
 	unsigned int fe_sps_lim;		/* limit on new sessions per second on the frontend */
