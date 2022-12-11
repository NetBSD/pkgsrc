$NetBSD: patch-lib_dns_validator.c,v 1.1 2022/12/11 01:57:55 sekiya Exp $

* Take from NetBSD base.

--- lib/dns/validator.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/validator.c
@@ -221,7 +221,7 @@ validator_done(dns_validator_t *val, isc
 	val->event->ev_type = DNS_EVENT_VALIDATORDONE;
 	val->event->ev_action = val->action;
 	val->event->ev_arg = val->arg;
-	isc_task_sendanddetach(&task, (isc_event_t **)&val->event);
+	isc_task_sendanddetach(&task, (isc_event_t **)(void *)&val->event);
 }
 
 /*
