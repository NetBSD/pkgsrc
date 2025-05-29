$NetBSD: patch-src_backend.c,v 1.1 2025/05/29 20:36:50 adam Exp $

Avoid 'struct queue' conflict.

--- src/backend.c.orig	2025-05-29 17:49:16.686886918 +0000
+++ src/backend.c
@@ -1037,7 +1037,7 @@ int assign_server_and_queue(struct strea
 		 * not full, in which case we have to return FULL.
 		 */
 		if (srv->maxconn) {
-			struct queue *queue = &srv->per_tgrp[tgid - 1].queue;
+			struct haqueue *queue = &srv->per_tgrp[tgid - 1].queue;
 			int served;
 			int got_it = 0;
 
