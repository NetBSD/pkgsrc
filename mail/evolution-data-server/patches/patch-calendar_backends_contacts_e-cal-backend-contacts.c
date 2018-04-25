$NetBSD: patch-calendar_backends_contacts_e-cal-backend-contacts.c,v 1.1 2018/04/25 05:57:58 markd Exp $

work with libical-3

--- calendar/backends/contacts/e-cal-backend-contacts.c.orig	2011-04-21 19:35:36.000000000 +0000
+++ calendar/backends/contacts/e-cal-backend-contacts.c
@@ -501,7 +501,6 @@ cdate_to_icaltime (EContactDate *cdate)
 	ret.month = cdate->month;
 	ret.day = cdate->day;
 	ret.is_date = TRUE;
-	ret.is_utc = FALSE;
 	ret.zone = NULL;
 	ret.is_daylight = FALSE;
 
