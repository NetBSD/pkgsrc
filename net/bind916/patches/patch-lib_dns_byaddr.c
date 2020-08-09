$NetBSD: patch-lib_dns_byaddr.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* C syntax.

--- lib/dns/byaddr.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/byaddr.c
@@ -160,7 +160,7 @@ lookup_done(isc_task_t *task, isc_event_
 		byaddr->event->result = levent->result;
 	}
 	isc_event_free(&event);
-	isc_task_sendanddetach(&byaddr->task, (isc_event_t **)&byaddr->event);
+	isc_task_sendanddetach(&byaddr->task, (isc_event_t **)(void *)&byaddr->event);
 }
 
 static void
