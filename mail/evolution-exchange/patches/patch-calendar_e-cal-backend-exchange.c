$NetBSD: patch-calendar_e-cal-backend-exchange.c,v 1.1 2018/05/17 09:03:09 jperkin Exp $

Catch up with latest libical API.

--- calendar/e-cal-backend-exchange.c.orig	2011-02-06 04:54:00.000000000 +0000
+++ calendar/e-cal-backend-exchange.c
@@ -614,7 +614,7 @@ find_instance (ECalBackendExchange *cbex
 		e_cal_component_get_recurid (comp, &recur_id);
 
 		rtime = e2k_parse_timestamp (rid);
-		new_rid = icaltime_from_timet (rtime, FALSE);
+		new_rid = icaltime_from_timet_with_zone (rtime, FALSE, NULL);
 
 		f_zone = (recur_id.datetime.tzid && *recur_id.datetime.tzid) ? internal_get_timezone ((ECalBackend *) cbex, recur_id.datetime.tzid) : icaltimezone_get_utc_timezone ();
 		recur_id.datetime.value->zone = f_zone;
