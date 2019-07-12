$NetBSD: patch-repmgr.c,v 1.1 2019/07/12 12:49:26 adam Exp $

repmgr is not linked against gettext.

--- repmgr.c.orig	2019-07-12 11:42:23.000000000 +0000
+++ repmgr.c
@@ -784,7 +784,7 @@ repmgrd_pause(PG_FUNCTION_ARGS)
 
 	if (fwrite(buf.data, strlen(buf.data) + 1, 1, file) != 1)
 	{
-		elog(WARNING, _("unable to write to file %s"), REPMGRD_STATE_FILE);
+		elog(WARNING, "unable to write to file %s", REPMGRD_STATE_FILE);
 	}
 
 	pfree(buf.data);
