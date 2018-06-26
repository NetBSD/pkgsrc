$NetBSD: patch-client_cd-util.c,v 1.2 2018/06/26 10:16:20 jperkin Exp $

Fix db path.
SunOS requires sys/termios.h

--- client/cd-util.c.orig	2016-07-27 13:49:36.000000000 +0000
+++ client/cd-util.c
@@ -27,6 +27,9 @@
 #ifdef HAVE_PWD_H
 #include <pwd.h>
 #endif
+#ifdef __sun
+#include <sys/termios.h>
+#endif
 #include <stdlib.h>
 #include <stdio.h>
 #include <sys/ioctl.h>
@@ -814,7 +817,7 @@ cd_util_dump (CdUtilPrivate *priv, gchar
 {
 	CdDevice *device;
 	CdProfile *profile;
-	const gchar *argv[] = { "sqlite3", "/var/lib/colord/mapping.db", ".dump", NULL };
+	const gchar *argv[] = { "sqlite3", "@VARBASE@/db/colord/mapping.db", ".dump", NULL };
 	gboolean ret = TRUE;
 	gchar *tmp;
 	GDateTime *dt;
