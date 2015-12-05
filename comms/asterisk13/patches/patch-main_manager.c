$NetBSD: patch-main_manager.c,v 1.1.1.1 2015/12/05 23:29:10 jnemeth Exp $

--- main/manager.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/manager.c
@@ -2440,7 +2448,7 @@ static char *handle_showmanconn(struct a
 	struct mansession_session *session;
 	time_t now = time(NULL);
 #define HSMCONN_FORMAT1 "  %-15.15s  %-55.55s  %-10.10s  %-10.10s  %-8.8s  %-8.8s  %-5.5s  %-5.5s\n"
-#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10d  %-10d  %-8d  %-8d  %-5.5d  %-5.5d\n"
+#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10jd  %-10jd  %-8d  %-8d  %-5.5d  %-5.5d\n"
 	int count = 0;
 	struct ao2_iterator i;
 
@@ -2466,8 +2474,8 @@ static char *handle_showmanconn(struct a
 			ao2_lock(session);
 			ast_cli(a->fd, HSMCONN_FORMAT2, session->username,
 				ast_sockaddr_stringify_addr(&session->addr),
-				(int) (session->sessionstart),
-				(int) (now - session->sessionstart),
+				(intmax_t) (session->sessionstart),
+				(intmax_t) (now - session->sessionstart),
 				session->fd,
 				session->inuse,
 				session->readperm,
@@ -3299,9 +3307,9 @@ static int action_ping(struct mansession
 	astman_append(
 		s,
 		"Ping: Pong\r\n"
-		"Timestamp: %ld.%06lu\r\n"
+		"Timestamp: %jd.%06lu\r\n"
 		"\r\n",
-		(long) now.tv_sec, (unsigned long) now.tv_usec);
+		(intmax_t) now.tv_sec, (unsigned long) now.tv_usec);
 	return 0;
 }
 
@@ -6606,8 +6623,8 @@ int __ast_manager_event_multichan(int ca
 	if (timestampevents) {
 		now = ast_tvnow();
 		ast_str_append(&buf, 0,
-				"Timestamp: %ld.%06lu\r\n",
-				 (long)now.tv_sec, (unsigned long) now.tv_usec);
+				"Timestamp: %jd.%06lu\r\n",
+				 (intmax_t)now.tv_sec, (unsigned long) now.tv_usec);
 	}
 	if (manager_debug) {
 		static int seq;
