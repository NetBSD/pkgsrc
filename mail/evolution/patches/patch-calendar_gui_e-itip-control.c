$NetBSD: patch-calendar_gui_e-itip-control.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- calendar/gui/e-itip-control.c.orig	2011-03-29 18:38:46.000000000 +0000
+++ calendar/gui/e-itip-control.c
@@ -673,7 +673,7 @@ write_label_piece (EItipControl *itip, E
 	/* UTC times get converted to the current timezone. This is done for
 	   the COMPLETED property, which is always in UTC, and also because
 	   Outlook sends simple events as UTC times. */
-	if (dt->value->is_utc) {
+	if (icaltime_is_utc(*dt->value)) {
 		zone = calendar_config_get_icaltimezone ();
 		icaltimezone_convert_time (dt->value, icaltimezone_get_utc_timezone (), zone);
 	}
@@ -691,7 +691,7 @@ write_label_piece (EItipControl *itip, E
 				     time_buf, sizeof (time_buf));
 	g_string_append (buffer, time_buf);
 
-	if (!dt->value->is_utc && dt->tzid) {
+	if (!icaltime_is_utc(*dt->value) && dt->tzid) {
 		zone = icalcomponent_get_timezone (priv->top_level, dt->tzid);
 	}
 
@@ -930,7 +930,7 @@ set_date_label (EItipControl *itip,
 	if (type == E_CAL_COMPONENT_TODO && datetime.value) {
 		str = g_strdup_printf ("<b>%s:</b>", _("Completed"));
 		/* Pass TRUE as is_utc, so it gets converted to the current timezone. */
-		datetime.value->is_utc = TRUE;
+		datetime.value->zone = icaltimezone_get_utc_timezone();
 		write_label_piece (itip, &datetime, buffer, str, "<br>", FALSE);
 		wrote = TRUE;
 		task_completed = TRUE;
@@ -1898,7 +1898,7 @@ change_status (icalcomponent *ical_comp,
 	if (prop) {
 		icalparameter *param;
 
-		icalproperty_remove_parameter (prop, ICAL_PARTSTAT_PARAMETER);
+		icalproperty_remove_parameter_by_kind (prop, ICAL_PARTSTAT_PARAMETER);
 		param = icalparameter_new_partstat (status);
 		icalproperty_add_parameter (prop, param);
 	} else {
