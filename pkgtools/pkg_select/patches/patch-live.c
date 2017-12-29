$NetBSD: patch-live.c,v 1.1 2017/12/29 11:59:13 plunky Exp $

fix buffer overrun

--- live.c.orig	2009-03-08 14:25:53.000000000 +0000
+++ live.c
@@ -199,7 +199,7 @@ ftp_get(const char *path, const char *fi
 
 	XMALLOC(tmppath, MIDLEN * sizeof(char));
 
-	snprintf(tmppath, MAXLEN, "%s/%s.pkg_select", TMPDIR, file);
+	snprintf(tmppath, MIDLEN, "%s/%s.pkg_select", TMPDIR, file);
 
 	snprintf(cmd, MAXLEN, "cd %s\n", path);
 	if ((rc = ftp_cmd(cmd, "\n(550|250).*\n")) != 250)
