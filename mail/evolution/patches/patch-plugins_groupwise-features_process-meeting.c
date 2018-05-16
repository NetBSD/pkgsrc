$NetBSD: patch-plugins_groupwise-features_process-meeting.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- plugins/groupwise-features/process-meeting.c.orig	2011-03-29 18:38:48.000000000 +0000
+++ plugins/groupwise-features/process-meeting.c
@@ -118,7 +118,7 @@ change_status (icalcomponent *ical_comp,
 	if (prop) {
 		icalparameter *param;
 
-		icalproperty_remove_parameter (prop, ICAL_PARTSTAT_PARAMETER);
+		icalproperty_remove_parameter_by_kind (prop, ICAL_PARTSTAT_PARAMETER);
 		param = icalparameter_new_partstat (status);
 		icalproperty_add_parameter (prop, param);
 	} else {
