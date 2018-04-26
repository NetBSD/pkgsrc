$NetBSD: patch-kcalcore_icaltimezones.cpp,v 1.1 2018/04/26 07:55:21 markd Exp $

work with libical-3

--- kcalcore/icaltimezones.cpp.orig	2015-06-24 12:43:14.000000000 +0000
+++ kcalcore/icaltimezones.cpp
@@ -54,7 +54,7 @@ static QDateTime toQDateTime(const icalt
 {
     return QDateTime(QDate(t.year, t.month, t.day),
                      QTime(t.hour, t.minute, t.second),
-                     (t.is_utc ? Qt::UTC : Qt::LocalTime));
+                     (icaltime_is_utc(t) ? Qt::UTC : Qt::LocalTime));
 }
 
 // Maximum date for time zone data.
@@ -81,7 +81,6 @@ static icaltimetype writeLocalICalDateTi
     t.second = local.time().second();
     t.is_date = 0;
     t.zone = 0;
-    t.is_utc = 0;
     return t;
 }
 
@@ -886,7 +885,7 @@ ICalTimeZone ICalTimeZoneSource::parse(i
         case ICAL_LASTMODIFIED_PROPERTY:
         {
             const icaltimetype t = icalproperty_get_lastmodified(p);
-            if (t.is_utc) {
+            if (icaltime_is_utc(t)) {
                 data->d->lastModified = toQDateTime(t);
             } else {
                 kDebug() << "LAST-MODIFIED not UTC";
@@ -1259,7 +1258,7 @@ QList<QDateTime> ICalTimeZoneSourcePriva
     // Convert DTSTART to QDateTime, and from local time to UTC
     const QDateTime localStart = toQDateTime(dtstart);     // local time
     dtstart.second -= prevOffset;
-    dtstart.is_utc = 1;
+    dtstart = icaltime_convert_to_zone(dtstart, icaltimezone_get_utc_timezone());
     const QDateTime utcStart = toQDateTime(icaltime_normalize(dtstart));       // UTC
 
     transitions += utcStart;
@@ -1286,13 +1285,12 @@ QList<QDateTime> ICalTimeZoneSourcePriva
                     t.minute = dtstart.minute;
                     t.second = dtstart.second;
                     t.is_date = 0;
-                    t.is_utc = 0;    // dtstart is in local time
                 }
                 // RFC2445 states that RDATE must be in local time,
                 // but we support UTC as well to be safe.
-                if (!t.is_utc) {
+                if (!icaltime_is_utc(t)) {
                     t.second -= prevOffset;    // convert to UTC
-                    t.is_utc = 1;
+                    t = icaltime_convert_to_zone(t, icaltimezone_get_utc_timezone());
                     t = icaltime_normalize(t);
                 }
                 transitions += toQDateTime(t);
