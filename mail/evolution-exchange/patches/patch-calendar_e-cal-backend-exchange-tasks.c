$NetBSD: patch-calendar_e-cal-backend-exchange-tasks.c,v 1.1 2018/05/17 09:03:09 jperkin Exp $

Catch up with latest libical API.

--- calendar/e-cal-backend-exchange-tasks.c.orig	2011-02-06 04:54:00.000000000 +0000
+++ calendar/e-cal-backend-exchange-tasks.c
@@ -192,10 +192,7 @@ calcomponentdatetime_to_string (ECalComp
 	g_return_val_if_fail (dt != NULL, NULL);
         g_return_val_if_fail (dt->value != NULL, NULL);
 
-	if (izone != NULL)
-                tt = icaltime_as_timet_with_zone (*dt->value, izone);
-        else
-                tt = icaltime_as_timet (*dt->value);
+        tt = icaltime_as_timet_with_zone (*dt->value, izone);
 
 	return e2k_make_timestamp (tt);
 }
@@ -648,7 +645,7 @@ get_changed_tasks (ECalBackendExchange *
 
 		e_cal_backend_exchange_add_timezone (cbex, icalcomp, NULL);
 
-		itt = icaltime_from_timet (e2k_parse_timestamp (modtime), 0);
+		itt = icaltime_from_timet_with_zone (e2k_parse_timestamp (modtime), 0, NULL);
 		if (!icaltime_is_null_time (itt)) {
 			e_cal_backend_exchange_ensure_utc_zone (E_CAL_BACKEND (cbex), &itt);
 			e_cal_component_set_last_modified (ecal, &itt);
@@ -681,7 +678,7 @@ get_changed_tasks (ECalBackendExchange *
 		/* Set DTSTAMP */
 		if ((str = e2k_properties_get_prop (result->props,
 				E2K_PR_HTTPMAIL_DATE))) {
-			itt = icaltime_from_timet (e2k_parse_timestamp (str), 0);
+			itt = icaltime_from_timet_with_zone (e2k_parse_timestamp (str), 0, NULL);
 			if (!icaltime_is_null_time (itt)) {
 				e_cal_backend_exchange_ensure_utc_zone (E_CAL_BACKEND (cbex), &itt);
 
@@ -783,7 +780,7 @@ get_changed_tasks (ECalBackendExchange *
 		/* Set DATE COMPLETED */
 		if ((str = e2k_properties_get_prop (result->props,
 				E2K_PR_OUTLOOK_TASK_DONE_DT))) {
-			itt = icaltime_from_timet (e2k_parse_timestamp (str), 0);
+			itt = icaltime_from_timet_with_zone (e2k_parse_timestamp (str), 0, NULL);
 			if (!icaltime_is_null_time (itt))
 				e_cal_component_set_completed (ecal, &itt);
 		}
@@ -791,7 +788,7 @@ get_changed_tasks (ECalBackendExchange *
 		/* Set LAST MODIFIED */
 		if ((str = e2k_properties_get_prop (result->props,
 				E2K_PR_CALENDAR_LAST_MODIFIED))) {
-			itt = icaltime_from_timet (e2k_parse_timestamp(str), 0);
+			itt = icaltime_from_timet_with_zone (e2k_parse_timestamp(str), 0, NULL);
 			if (!icaltime_is_null_time (itt)) {
 				e_cal_backend_exchange_ensure_utc_zone (E_CAL_BACKEND (cbex), &itt);
 				e_cal_component_set_last_modified (ecal, &itt);
