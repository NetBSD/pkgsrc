$NetBSD: patch-openvpn-nagios.c,v 1.1 2013/03/26 23:32:50 joerg Exp $

--- openvpn-nagios.c.orig	2013-03-25 15:45:11.000000000 +0000
+++ openvpn-nagios.c
@@ -87,12 +87,11 @@ strmatch(s, match)
 #endif
 
 static time_t
-date_strtots(strdate)
-	char *strdate;
+date_strtots(unsigned char *strdate)
 {
 	struct tm tm;
 
-	(void)strptime(strdate, "%y%m%d%H%M%SZ", &tm);
+	(void)strptime((char *)strdate, "%y%m%d%H%M%SZ", &tm);
 	return mktime(&tm);
 }
 
