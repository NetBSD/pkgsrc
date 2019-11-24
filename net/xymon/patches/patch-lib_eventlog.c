$NetBSD: patch-lib_eventlog.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8084/
Add guards around GCC diagnostics pragma to allow for building on older vers

--- lib/eventlog.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ lib/eventlog.c
@@ -42,10 +42,14 @@ static int wanted_eventcolumn(char *serv
 
 	if (!eventignorecolumns || (strlen(service) > (sizeof(svc)-3))) return 1;
 
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 	#pragma GCC diagnostic push
 	#pragma GCC diagnostic ignored "-Wformat-truncation"
+#endif  // __GNUC__
 	snprintf(svc, sizeof(svc), ",%s,", service);
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 	#pragma GCC diagnostic pop
+#endif  // __GNUC__
 
 	result = (strstr(eventignorecolumns, svc) == NULL);
 
