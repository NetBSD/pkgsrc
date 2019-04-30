$NetBSD: patch-lib_dns_validator.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- lib/dns/validator.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/validator.c
@@ -211,7 +211,7 @@ validator_done(dns_validator_t *val, isc
 	val->event->ev_type = DNS_EVENT_VALIDATORDONE;
 	val->event->ev_action = val->action;
 	val->event->ev_arg = val->arg;
-	isc_task_sendanddetach(&task, (isc_event_t **)&val->event);
+	isc_task_sendanddetach(&task, (isc_event_t **)(void *)&val->event);
 }
 
 static inline bool
