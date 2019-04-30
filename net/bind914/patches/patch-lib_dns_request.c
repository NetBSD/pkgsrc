$NetBSD: patch-lib_dns_request.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- lib/dns/request.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/request.c
@@ -1421,7 +1421,7 @@ req_sendevent(dns_request_t *request, is
 	task = request->event->ev_sender;
 	request->event->ev_sender = request;
 	request->event->result = result;
-	isc_task_sendanddetach(&task, (isc_event_t **)&request->event);
+	isc_task_sendanddetach(&task, (isc_event_t **)(void *)&request->event);
 }
 
 static void
@@ -1438,7 +1438,7 @@ req_destroy(dns_request_t *request) {
 	if (request->answer != NULL)
 		isc_buffer_free(&request->answer);
 	if (request->event != NULL)
-		isc_event_free((isc_event_t **)&request->event);
+		isc_event_free((isc_event_t **)(void *)&request->event);
 	if (request->dispentry != NULL)
 		dns_dispatch_removeresponse(&request->dispentry, NULL);
 	if (request->dispatch != NULL)
