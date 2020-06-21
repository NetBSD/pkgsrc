$NetBSD: patch-libntp_ntp__calendar.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- libntp/ntp_calendar.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ libntp/ntp_calendar.c
@@ -2223,10 +2223,10 @@ ntpcal_iso8601std(
 		len = LIB_BUFLENGTH;
 	}
 	if (len) {
-		len = snprintf(buf, len, "%04u-%02u-%02uT%02u:%02u:%02u",
+		int slen = snprintf(buf, len, "%04u-%02u-%02uT%02u:%02u:%02u",
 			       cdp->year, cdp->month, cdp->monthday,
 			       cdp->hour, cdp->minute, cdp->second);
-		if (len < 0)
+		if (slen < 0)
 			*buf = '\0';
 	}
 	return buf;
