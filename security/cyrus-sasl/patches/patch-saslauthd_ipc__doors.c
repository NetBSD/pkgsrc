$NetBSD: patch-saslauthd_ipc__doors.c,v 1.1 2016/09/11 06:11:15 richard Exp $
match do_request() declaration signature to implementation
--- saslauthd/ipc_doors.c.orig	2012-01-27 23:31:36.000000000 +0000
+++ saslauthd/ipc_doors.c
@@ -74,7 +74,7 @@
 /****************************************
  * declarations/protos
  *****************************************/
-static void	do_request(void *, char *, size_t, door_desc_t *, uint_t);
+static void	do_request(void *, char *, size_t, door_desc_t *, size_t);
 static void	send_no(char *);
 static void	need_thread(door_info_t*);
 static void	*server_thread(void *);
