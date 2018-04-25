$NetBSD: patch-calendar_libecal_e-cal-component.c,v 1.1 2018/04/25 05:57:58 markd Exp $

Work with libical-3

--- calendar/libecal/e-cal-component.c.orig	2011-04-21 19:35:36.000000000 +0000
+++ calendar/libecal/e-cal-component.c
@@ -2414,7 +2414,7 @@ get_datetime (struct datetime *datetime,
 	   This makes the timezone code simpler. */
 	if (datetime->tzid_param)
 		dt->tzid = g_strdup (icalparameter_get_tzid (datetime->tzid_param));
-	else if (dt->value && dt->value->is_utc)
+	else if (dt->value && icaltime_is_utc (*dt->value))
 		dt->tzid = g_strdup ("UTC");
 	else
 		dt->tzid = NULL;
@@ -2449,9 +2449,9 @@ set_datetime (ECalComponent *comp, struc
 
 	/* If the TZID is set to "UTC", we set the is_utc flag. */
 	if (dt->tzid && !strcmp (dt->tzid, "UTC"))
-		dt->value->is_utc = 1;
-	else
-		dt->value->is_utc = 0;
+		dt->value->zone = icaltimezone_get_utc_timezone ();
+	else if (dt->value->zone == icaltimezone_get_utc_timezone ())
+		dt->value->zone = NULL;
 
 	if (datetime->prop) {
 		(* prop_set_func) (datetime->prop, *dt->value);
@@ -2471,7 +2471,7 @@ set_datetime (ECalComponent *comp, struc
 			icalproperty_add_parameter (datetime->prop, datetime->tzid_param);
 		}
 	} else if (datetime->tzid_param) {
-		icalproperty_remove_parameter (datetime->prop, ICAL_TZID_PARAMETER);
+		icalproperty_remove_parameter_by_kind (datetime->prop, ICAL_TZID_PARAMETER);
 		datetime->tzid_param = NULL;
 	}
 }
@@ -3407,7 +3407,7 @@ e_cal_component_set_organizer (ECalCompo
 						    priv->organizer.sentby_param);
 		}
 	} else if (priv->organizer.sentby_param) {
-		icalproperty_remove_parameter (priv->organizer.prop, ICAL_SENTBY_PARAMETER);
+		icalproperty_remove_parameter_by_kind (priv->organizer.prop, ICAL_SENTBY_PARAMETER);
 		priv->organizer.sentby_param = NULL;
 	}
 
@@ -3424,7 +3424,7 @@ e_cal_component_set_organizer (ECalCompo
 						    priv->organizer.cn_param);
 		}
 	} else if (priv->organizer.cn_param) {
-		icalproperty_remove_parameter (priv->organizer.prop, ICAL_CN_PARAMETER);
+		icalproperty_remove_parameter_by_kind (priv->organizer.prop, ICAL_CN_PARAMETER);
 		priv->organizer.cn_param = NULL;
 	}
 
@@ -3441,7 +3441,7 @@ e_cal_component_set_organizer (ECalCompo
 						    priv->organizer.language_param);
 		}
 	} else if (priv->organizer.language_param) {
-		icalproperty_remove_parameter (priv->organizer.prop, ICAL_LANGUAGE_PARAMETER);
+		icalproperty_remove_parameter_by_kind (priv->organizer.prop, ICAL_LANGUAGE_PARAMETER);
 		priv->organizer.language_param = NULL;
 	}
 
@@ -4386,7 +4386,7 @@ e_cal_component_set_summary (ECalCompone
 						    priv->summary.altrep_param);
 		}
 	} else if (priv->summary.altrep_param) {
-		icalproperty_remove_parameter (priv->summary.prop, ICAL_ALTREP_PARAMETER);
+		icalproperty_remove_parameter_by_kind (priv->summary.prop, ICAL_ALTREP_PARAMETER);
 		priv->summary.altrep_param = NULL;
 	}
 
