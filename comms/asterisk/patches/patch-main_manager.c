$NetBSD: patch-main_manager.c,v 1.1 2012/12/11 08:22:49 jnemeth Exp $

--- main/manager.c.orig	2012-10-17 19:22:46.000000000 +0000
+++ main/manager.c
@@ -1827,7 +1827,7 @@ static char *handle_showmanconn(struct a
 	struct mansession_session *session;
 	time_t now = time(NULL);
 #define HSMCONN_FORMAT1 "  %-15.15s  %-55.55s  %-10.10s  %-10.10s  %-8.8s  %-8.8s  %-5.5s  %-5.5s\n"
-#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10d  %-10d  %-8d  %-8d  %-5.5d  %-5.5d\n"
+#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10jd  %-10jd  %-8d  %-8d  %-5.5d  %-5.5d\n"
 	int count = 0;
 	struct ao2_iterator i;
 
@@ -1848,7 +1848,7 @@ static char *handle_showmanconn(struct a
 	i = ao2_iterator_init(sessions, 0);
 	while ((session = ao2_iterator_next(&i))) {
 		ao2_lock(session);
-		ast_cli(a->fd, HSMCONN_FORMAT2, session->username, ast_sockaddr_stringify_addr(&session->addr), (int)(session->sessionstart), (int)(now - session->sessionstart), session->fd, session->inuse, session->readperm, session->writeperm);
+		ast_cli(a->fd, HSMCONN_FORMAT2, session->username, ast_sockaddr_stringify_addr(&session->addr), (intmax_t)(session->sessionstart), (intmax_t)(now - session->sessionstart), session->fd, session->inuse, session->readperm, session->writeperm);
 		count++;
 		ao2_unlock(session);
 		unref_mansession(session);
