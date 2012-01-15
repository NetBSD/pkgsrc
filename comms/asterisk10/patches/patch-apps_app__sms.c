$NetBSD: patch-apps_app__sms.c,v 1.1.1.1 2012/01/15 18:36:21 jnemeth Exp $

--- apps/app_sms.c.orig	2011-07-14 20:25:31.000000000 +0000
+++ apps/app_sms.c
@@ -553,7 +553,7 @@ static void packdate(unsigned char *o, t
 	int z;
 
 	ast_localtime(&topack, &t, NULL);
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined( __NetBSD__ ) || defined(__APPLE__) || defined(__CYGWIN__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined( __NetBSD__ ) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__DragonFly__)
 	z = -t.tm_gmtoff / 60 / 15;
 #else
 	z = timezone / 60 / 15;
