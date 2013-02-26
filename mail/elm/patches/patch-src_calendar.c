$NetBSD: patch-src_calendar.c,v 1.1 2013/02/26 11:08:17 joerg Exp $

--- src/calendar.c.orig	2013-02-25 16:39:42.000000000 +0000
+++ src/calendar.c
@@ -45,7 +45,7 @@ static char rcsid[] = "@(#)$Id: calendar
 
 #include "s_error.h"
 
-scan_calendar()
+void scan_calendar(void)
 {
 	FILE *calendar;
 	int  count;
