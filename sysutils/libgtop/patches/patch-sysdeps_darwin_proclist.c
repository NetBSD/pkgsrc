$NetBSD: patch-sysdeps_darwin_proclist.c,v 1.1 2016/04/07 11:54:57 youri Exp $

Fix Darwin build.

--- sysdeps/darwin/proclist.c.orig	2011-06-01 15:40:47.000000000 +0000
+++ sysdeps/darwin/proclist.c
@@ -43,7 +43,7 @@ _glibtop_init_proclist_p (glibtop *serve
 
 pid_t *
 glibtop_get_proclist_p (glibtop *server, glibtop_proclist *buf,
-			int64_t which, int64_t arg)
+			gint64 which, gint64 arg)
 {
 	unsigned count, total, i;
 	pid_t *pids_chain;
