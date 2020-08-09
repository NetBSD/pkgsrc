$NetBSD: patch-lib_dns_lookup.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/dns/lookup.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/lookup.c
@@ -339,7 +339,7 @@ lookup_find(dns_lookup_t *lookup, dns_fe
 		lookup->event->result = result;
 		lookup->event->ev_sender = lookup;
 		isc_task_sendanddetach(&lookup->task,
-				       (isc_event_t **)&lookup->event);
+				       (isc_event_t **)(void *)&lookup->event);
 		dns_view_detach(&lookup->view);
 	}
 
