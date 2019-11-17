$NetBSD: patch-src_freebsd_ssc.c,v 1.1 2019/11/17 23:05:20 scole Exp $

Cast argument to execlp() appropriately

--- src/freebsd/ssc.c.orig	2008-02-04 20:11:38.000000000 -0800
+++ src/freebsd/ssc.c	2019-11-11 08:49:35.285330731 -0800
@@ -128,7 +128,7 @@
 		tty = name + namelen + 1;
 		sprintf(tty, "-S%s%d", name + namelen - 2, master);
 		execlp("xterm", "xterm", tty, "-geo", "80x24", "-name",
-		    "xski console", 0);
+		    "xski console", (char *)NULL);
 		abort();
 	default: /* parent */
 		close(master);
