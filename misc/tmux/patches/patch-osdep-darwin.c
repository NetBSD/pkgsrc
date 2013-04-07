$NetBSD: patch-osdep-darwin.c,v 1.1 2013/04/07 04:00:40 schmonz Exp $

Fix build on OS X 10.6.8, from <https://trac.macports.org/ticket/38588>.

--- osdep-darwin.c.orig	2013-02-24 12:42:49.000000000 +0000
+++ osdep-darwin.c
@@ -33,17 +33,17 @@ struct event_base	*osdep_event_init(void
 char *
 osdep_get_name(int fd, unused char *tty)
 {
-	struct proc_bsdshortinfo	bsdinfo;
+	struct proc_bsdinfo	bsdinfo;
 	pid_t				pgrp;
 	int				ret;
 
 	if ((pgrp = tcgetpgrp(fd)) == -1)
 		return (NULL);
 
-	ret = proc_pidinfo(pgrp, PROC_PIDT_SHORTBSDINFO, 0,
+	ret = proc_pidinfo(pgrp, PROC_PIDTBSDINFO, 0,
 	    &bsdinfo, sizeof bsdinfo);
-	if (ret == sizeof bsdinfo && *bsdinfo.pbsi_comm != '\0')
-		return (strdup(bsdinfo.pbsi_comm));
+	if (ret == sizeof bsdinfo && *bsdinfo.pbi_comm != '\0')
+		return (strdup(bsdinfo.pbi_comm));
 	return (NULL);
 }
 
