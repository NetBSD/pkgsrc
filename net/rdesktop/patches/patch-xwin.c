$NetBSD: patch-xwin.c,v 1.1 2020/01/15 15:31:28 wiz Exp $

Workaround for undefined HOST_NAME_MAX on BSD systems

--- xwin.c.orig	2019-06-13 12:10:15.000000000 +0000
+++ xwin.c
@@ -1887,7 +1887,7 @@ static void
 set_wm_client_machine(Display * dpy, Window win)
 {
 	XTextProperty tp;
-	char hostname[HOST_NAME_MAX];
+	char hostname[sysconf(_SC_HOST_NAME_MAX)];
 
 	if (gethostname(hostname, sizeof(hostname)) != 0)
 		return;
