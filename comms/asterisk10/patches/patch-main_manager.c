$NetBSD: patch-main_manager.c,v 1.2 2012/10/09 01:36:32 jnemeth Exp $

--- main/manager.c.orig	2012-09-05 19:22:08.000000000 +0000
+++ main/manager.c
@@ -1717,7 +1717,7 @@ static char *handle_showmanconn(struct a
 	struct mansession_session *session;
 	time_t now = time(NULL);
 #define HSMCONN_FORMAT1 "  %-15.15s  %-15.15s  %-10.10s  %-10.10s  %-8.8s  %-8.8s  %-5.5s  %-5.5s\n"
-#define HSMCONN_FORMAT2 "  %-15.15s  %-15.15s  %-10d  %-10d  %-8d  %-8d  %-5.5d  %-5.5d\n"
+#define HSMCONN_FORMAT2 "  %-15.15s  %-15.15s  %-10jd  %-10jd  %-8d  %-8d  %-5.5d  %-5.5d\n"
 	int count = 0;
 	struct ao2_iterator i;
 
@@ -1738,7 +1738,7 @@ static char *handle_showmanconn(struct a
 	i = ao2_iterator_init(sessions, 0);
 	while ((session = ao2_iterator_next(&i))) {
 		ao2_lock(session);
-		ast_cli(a->fd, HSMCONN_FORMAT2, session->username, ast_inet_ntoa(session->sin.sin_addr), (int)(session->sessionstart), (int)(now - session->sessionstart), session->fd, session->inuse, session->readperm, session->writeperm);
+		ast_cli(a->fd, HSMCONN_FORMAT2, session->username, ast_inet_ntoa(session->sin.sin_addr), (intmax_t)(session->sessionstart), (intmax_t)(now - session->sessionstart), session->fd, session->inuse, session->readperm, session->writeperm);
 		count++;
 		ao2_unlock(session);
 		unref_mansession(session);
