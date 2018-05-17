$NetBSD: patch-calendar_e-cal-backend-exchange-calendar.c,v 1.1 2018/05/17 09:03:09 jperkin Exp $

Catch up with latest libical API.

--- calendar/e-cal-backend-exchange-calendar.c.orig	2011-02-06 04:54:00.000000000 +0000
+++ calendar/e-cal-backend-exchange-calendar.c
@@ -873,7 +873,7 @@ create_object (ECalBackendSync *backend,
 	     icalprop != NULL;
 	     icalprop = icalcomponent_get_next_property (icalcomp, ICAL_ANY_PROPERTY))
 	{
-		icalproperty_remove_parameter (icalprop, ICAL_X_PARAMETER);
+		icalproperty_remove_parameter_by_kind (icalprop, ICAL_X_PARAMETER);
 	}
 
 	/* add the timezones information and the component itself
@@ -1274,7 +1274,7 @@ modify_object_with_href (ECalBackendSync
 	     icalprop != NULL;
 	     icalprop = icalcomponent_get_next_property (updated_icalcomp, ICAL_ANY_PROPERTY))
 	{
-		icalproperty_remove_parameter (icalprop, ICAL_X_PARAMETER);
+		icalproperty_remove_parameter_by_kind (icalprop, ICAL_X_PARAMETER);
 	}
 
 	real_ecomp = e_cal_component_new ();
@@ -1300,7 +1300,6 @@ modify_object_with_href (ECalBackendSync
 			zone = icaltimezone_get_utc_timezone ();
 
 		dt.value->is_date = FALSE;
-		dt.value->is_utc = FALSE;
 		dt.value->hour = dt.value->minute = dt.value->second = 0;
 		dt.value->zone = zone;
 
@@ -1311,7 +1310,6 @@ modify_object_with_href (ECalBackendSync
 
 		e_cal_component_get_dtend (real_ecomp, &dt);
 		dt.value->is_date = FALSE;
-		dt.value->is_utc = FALSE;
 		dt.value->hour = dt.value->minute = dt.value->second = 0;
 		dt.value->zone = zone;
 
@@ -1349,7 +1347,6 @@ modify_object_with_href (ECalBackendSync
 			r->until.is_date = FALSE;
 
 			icaltimezone_convert_time (&r->until, from_zone, to_zone);
-			r->until.is_utc = TRUE;
 
 			e_cal_component_set_rrule_list (real_ecomp, rrule_list);
 			e_cal_component_free_datetime (&dt);
