$NetBSD: patch-lib_dns_resolver.c,v 1.1.2.2 2012/05/03 18:13:43 tron Exp $

Prevent segmentation fault in resolver.c: https://kb.isc.org/article/AA-00664

--- lib/dns/resolver.c.orig	2012-02-14 23:46:49.000000000 +0000
+++ lib/dns/resolver.c
@@ -2166,7 +2166,6 @@ fctx_finddone(isc_task_t *task, isc_even
 	isc_boolean_t want_try = ISC_FALSE;
 	isc_boolean_t want_done = ISC_FALSE;
 	isc_boolean_t bucket_empty = ISC_FALSE;
-	isc_boolean_t destroy = ISC_FALSE;
 	unsigned int bucketnum;
 
 	find = event->ev_sender;
@@ -2205,17 +2204,12 @@ fctx_finddone(isc_task_t *task, isc_even
 		}
 	} else if (SHUTTINGDOWN(fctx) && fctx->pending == 0 &&
 		   fctx->nqueries == 0 && ISC_LIST_EMPTY(fctx->validators)) {
-		/*
-		 * Note that we had to wait until we had the lock before
-		 * looking at fctx->references.
-		 */
+
 		if (fctx->references == 0)
-			destroy = ISC_TRUE;
+			bucket_empty = fctx_destroy(fctx);
 	}
 	UNLOCK(&res->buckets[bucketnum].lock);
 
-	if (destroy)
-		bucket_empty = fctx_destroy(fctx);
 	isc_event_free(&event);
 	dns_adb_destroyfind(&find);
 
