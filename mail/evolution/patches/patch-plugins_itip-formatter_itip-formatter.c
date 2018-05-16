$NetBSD: patch-plugins_itip-formatter_itip-formatter.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- plugins/itip-formatter/itip-formatter.c.orig	2011-03-29 18:38:48.000000000 +0000
+++ plugins/itip-formatter/itip-formatter.c
@@ -941,7 +941,7 @@ change_status (icalcomponent *ical_comp,
 	if (prop) {
 		icalparameter *param;
 
-		icalproperty_remove_parameter (prop, ICAL_PARTSTAT_PARAMETER);
+		icalproperty_remove_parameter_by_kind (prop, ICAL_PARTSTAT_PARAMETER);
 		param = icalparameter_new_partstat (status);
 		icalproperty_add_parameter (prop, param);
 	} else {
@@ -2390,9 +2390,9 @@ format_itip_object (EMFormatHTML *efh, G
 
 		/* If the timezone is not in the component, guess the local time */
 		/* Should we guess if the timezone is an olsen name somehow? */
-		if (datetime.value->is_utc)
+		if (icaltime_is_utc(*datetime.value))
 			from_zone = icaltimezone_get_utc_timezone ();
-		else if (!datetime.value->is_utc && datetime.tzid)
+		else if (!icaltime_is_utc(*datetime.value) && datetime.tzid)
 			from_zone = icalcomponent_get_timezone (info->top_level, datetime.tzid);
 		else
 			from_zone = NULL;
@@ -2426,9 +2426,9 @@ format_itip_object (EMFormatHTML *efh, G
 
 		/* If the timezone is not in the component, guess the local time */
 		/* Should we guess if the timezone is an olsen name somehow? */
-		if (datetime.value->is_utc)
+		if (icaltime_is_utc(*datetime.value))
 			from_zone = icaltimezone_get_utc_timezone ();
-		else if (!datetime.value->is_utc && datetime.tzid)
+		else if (!icaltime_is_utc(*datetime.value) && datetime.tzid)
 			from_zone = icalcomponent_get_timezone (info->top_level, datetime.tzid);
 		else
 			from_zone = NULL;
