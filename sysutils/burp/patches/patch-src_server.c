$NetBSD: patch-src_server.c,v 1.1 2016/12/17 14:21:27 joerg Exp $

Check pointer for Non-NULL-ness, not for positivity.

--- src/server.c.orig	2016-12-15 17:48:47.698862968 +0000
+++ src/server.c
@@ -543,7 +543,7 @@ static int do_backup_server(const char *
 			working, current, currentdata,
 			finishing, cconf, client,
 			p1cntr, cntr);
-		if(!ret && cconf->keep>0)
+		if(!ret && cconf->keep)
 			ret=remove_old_backups(basedir, cconf, client);
 	}
 
