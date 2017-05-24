$NetBSD: patch-openvpn-nagios.c,v 1.2 2017/05/24 20:35:12 adam Exp $

--- openvpn-nagios.c.orig	2013-02-10 01:33:07.000000000 +0000
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
 
@@ -112,7 +111,7 @@ openvpn_plugin_open_v3(vers, in, out)
 	struct ctx *ctx;
 	pthread_t thread;
 	int ac = 0;
-	char **av = __UNCONST(in->argv);
+	char **av = (void *)(unsigned long)(const void *)(in->argv);
 	int i, ch;
 	time_t now;
 
