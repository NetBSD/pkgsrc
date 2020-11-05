$NetBSD: patch-i18npool_source_calendar_calendar__gregorian.cxx,v 1.1 2020/11/05 09:23:43 ryoon Exp $

* Fix build with textproc/icu-68.1.

--- i18npool/source/calendar/calendar_gregorian.cxx.orig	2020-10-21 20:09:11.000000000 +0000
+++ i18npool/source/calendar/calendar_gregorian.cxx
@@ -347,7 +347,7 @@ Calendar_gregorian::setLocalDateTime( do
             "Calendar_gregorian::setLocalDateTime: " << std::fixed << fM << " rounded to " << fR);
     int32_t nZoneOffset, nDSTOffset;
     UErrorCode status = U_ZERO_ERROR;
-    body->getTimeZone().getOffset( fR, TRUE, nZoneOffset, nDSTOffset, status );
+    body->getTimeZone().getOffset( fR, true, nZoneOffset, nDSTOffset, status );
     if ( !U_SUCCESS(status) ) throw ERROR;
     status = U_ZERO_ERROR;
     body->setTime( fR - (nZoneOffset + nDSTOffset), status );
