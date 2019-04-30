$NetBSD: patch-lib_dns_byaddr.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- lib/dns/byaddr.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/byaddr.c
@@ -170,7 +170,7 @@ lookup_done(isc_task_t *task, isc_event_
 	} else
 		byaddr->event->result = levent->result;
 	isc_event_free(&event);
-	isc_task_sendanddetach(&byaddr->task, (isc_event_t **)&byaddr->event);
+	isc_task_sendanddetach(&byaddr->task, (isc_event_t **)(void *)&byaddr->event);
 }
 
 static void
