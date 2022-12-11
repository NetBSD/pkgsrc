$NetBSD: patch-lib_dns_request.c,v 1.1 2022/12/11 01:57:55 sekiya Exp $

* Take from NetBSD base.

--- lib/dns/request.c.orig	2022-11-08 07:17:42.040257986 +0900
+++ lib/dns/request.c	2022-12-10 10:41:02.459958123 +0900
@@ -1136,7 +1136,7 @@
 	request->event->ev_sender = request;
 	request->event->result = result;
 
-	isc_task_sendanddetach(&task, (isc_event_t **)&request->event);
+	isc_task_sendanddetach(&task, (isc_event_t **)(void *)&request->event);
 }
 
 static void
@@ -1193,7 +1193,7 @@
 		isc_buffer_free(&request->answer);
 	}
 	if (request->event != NULL) {
-		isc_event_free((isc_event_t **)&request->event);
+		isc_event_free((isc_event_t **)(void *)&request->event);
 	}
 	if (request->dispentry != NULL) {
 		dns_dispatch_done(&request->dispentry);
