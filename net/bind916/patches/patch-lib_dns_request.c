$NetBSD: patch-lib_dns_request.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/dns/request.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/request.c
@@ -1443,7 +1443,7 @@ req_sendevent(dns_request_t *request, is
 	task = request->event->ev_sender;
 	request->event->ev_sender = request;
 	request->event->result = result;
-	isc_task_sendanddetach(&task, (isc_event_t **)&request->event);
+	isc_task_sendanddetach(&task, (isc_event_t **)(void *)&request->event);
 }
 
 static void
@@ -1460,7 +1460,7 @@ req_destroy(dns_request_t *request) {
 		isc_buffer_free(&request->answer);
 	}
 	if (request->event != NULL) {
-		isc_event_free((isc_event_t **)&request->event);
+		isc_event_free((isc_event_t **)(void *)&request->event);
 	}
 	if (request->dispentry != NULL) {
 		dns_dispatch_removeresponse(&request->dispentry, NULL);
