$NetBSD: patch-include_haproxy_proxy-t.h,v 1.1 2021/12/09 10:36:07 jperkin Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/proxy-t.h.orig	2021-11-23 14:40:21.000000000 +0000
+++ include/haproxy/proxy-t.h
@@ -341,7 +341,7 @@ struct proxy {
 	__decl_thread(HA_RWLOCK_T lock);        /* may be taken under the server's lock */
 
 	char *id, *desc;			/* proxy id (name) and description */
-	struct queue queue;			/* queued requests (pendconns) */
+	struct haqueue queue;			/* queued requests (pendconns) */
 	int totpend;				/* total number of pending connections on this instance (for stats) */
 	unsigned int feconn, beconn;		/* # of active frontend and backends streams */
 	struct freq_ctr fe_req_per_sec;		/* HTTP requests per second on the frontend */
