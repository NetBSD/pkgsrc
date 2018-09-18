$NetBSD: patch-mbuffer.c,v 1.1 2018/09/18 09:49:29 fhajny Exp $

Default sysconfdir location.

--- mbuffer.c.orig	2018-06-25 20:37:20.000000000 +0000
+++ mbuffer.c
@@ -1029,7 +1029,7 @@ static void initDefaults()
 
 	const char *home = getenv("HOME");
 	readConfigFile("/etc/mbuffer.rc");
-	readConfigFile(PREFIX "/etc/mbuffer.rc");
+	readConfigFile(SYSCONFDIR "/mbuffer.rc");
 	if (home == 0) {
 		warningmsg("HOME environment variable not set - unable to find defaults file\n");
 		return;
