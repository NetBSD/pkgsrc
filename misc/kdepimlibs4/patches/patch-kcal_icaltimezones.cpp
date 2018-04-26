$NetBSD: patch-kcal_icaltimezones.cpp,v 1.1 2018/04/26 07:55:21 markd Exp $

work with libical-3

--- kcal/icaltimezones.cpp.orig	2015-06-24 12:43:14.000000000 +0000
+++ kcal/icaltimezones.cpp
@@ -50,7 +50,7 @@ static QDateTime toQDateTime( const ical
 {
   return QDateTime( QDate( t.year, t.month, t.day ),
                     QTime( t.hour, t.minute, t.second ),
-                    ( t.is_utc ? Qt::UTC : Qt::LocalTime ) );
+                    ( icaltime_is_utc(t) ? Qt::UTC : Qt::LocalTime ) );
 }
 
 // Maximum date for time zone data.
@@ -77,7 +77,6 @@ static icaltimetype writeLocalICalDateTi
   t.second = local.time().second();
   t.is_date = 0;
   t.zone = 0;
-  t.is_utc = 0;
   return t;
 }
 
@@ -787,7 +786,7 @@ ICalTimeZone ICalTimeZoneSource::parse( 
     case ICAL_LASTMODIFIED_PROPERTY:
     {
       icaltimetype t = icalproperty_get_lastmodified(p);
-      if ( t.is_utc ) {
+      if ( icaltime_is_utc(t) ) {
         data->d->lastModified = toQDateTime( t );
       } else {
         kDebug() << "LAST-MODIFIED not UTC";
@@ -972,7 +971,7 @@ QList<QDateTime> ICalTimeZoneSourcePriva
   // Convert DTSTART to QDateTime, and from local time to UTC
   QDateTime localStart = toQDateTime( dtstart );   // local time
   dtstart.second -= prevOffset;
-  dtstart.is_utc = 1;
+  dtstart = icaltime_convert_to_zone(dtstart, icaltimezone_get_utc_timezone());
   QDateTime utcStart = toQDateTime( icaltime_normalize( dtstart ) );   // UTC
 
   transitions += utcStart;
@@ -999,13 +998,12 @@ QList<QDateTime> ICalTimeZoneSourcePriva
           t.minute = dtstart.minute;
           t.second = dtstart.second;
           t.is_date = 0;
-          t.is_utc = 0;    // dtstart is in local time
         }
         // RFC2445 states that RDATE must be in local time,
         // but we support UTC as well to be safe.
-        if ( !t.is_utc ) {
+        if ( !icaltime_is_utc(t) ) {
           t.second -= prevOffset;    // convert to UTC
-          t.is_utc = 1;
+          t = icaltime_convert_to_zone(t, icaltimezone_get_utc_timezone());
           t = icaltime_normalize( t );
         }
         transitions += toQDateTime( t );
