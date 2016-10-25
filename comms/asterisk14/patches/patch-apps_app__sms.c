$NetBSD: patch-apps_app__sms.c,v 1.1.1.1 2016/10/25 08:17:07 jnemeth Exp $

--- apps/app_sms.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ apps/app_sms.c
@@ -555,7 +555,7 @@ static void packdate(unsigned char *o, t
 	int z;
 
 	ast_localtime(&topack, &t, NULL);
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined( __NetBSD__ ) || defined(__APPLE__) || defined(__CYGWIN__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined( __NetBSD__ ) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__DragonFly__)
 	z = -t.tm_gmtoff / 60 / 15;
 #else
 	z = timezone / 60 / 15;
