$NetBSD: patch-pkg__info.c,v 1.1 2017/12/29 11:59:13 plunky Exp $

fix buffer overrun

--- pkg_info.c.orig	2017-12-29 11:44:43.485014784 +0000
+++ pkg_info.c
@@ -122,7 +122,7 @@ syspkg_deinstall(WINDOW *win, const char
 
 	if ((tarlist = exec_list(buf, NULL)) != NULL) {
 		for (i = 0; tarlist[i] != NULL; i++) {
-			snprintf(buf, MAXLEN, "%s -f %s 2> /dev/null",
+			snprintf(buf, MIDLEN, "%s -f %s 2> /dev/null",
 				 RM, tarlist[i]);
 			rmcmd = exec_list(buf, NULL);
 			/* unused output */
