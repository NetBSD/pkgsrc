$NetBSD: patch-client_cd-util.c,v 1.1 2018/06/13 15:49:40 youri Exp $

Fix db path.

--- client/cd-util.c.orig	2016-07-27 13:49:36.000000000 +0000
+++ client/cd-util.c
@@ -814,7 +814,7 @@ cd_util_dump (CdUtilPrivate *priv, gchar
 {
 	CdDevice *device;
 	CdProfile *profile;
-	const gchar *argv[] = { "sqlite3", "/var/lib/colord/mapping.db", ".dump", NULL };
+	const gchar *argv[] = { "sqlite3", "@VARBASE@/db/colord/mapping.db", ".dump", NULL };
 	gboolean ret = TRUE;
 	gchar *tmp;
 	GDateTime *dt;
