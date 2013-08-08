$NetBSD: patch-main_manager.c,v 1.2 2013/08/08 00:45:10 jnemeth Exp $

--- main/manager.c.orig	2013-05-13 14:26:57.000000000 +0000
+++ main/manager.c
@@ -1850,7 +1850,7 @@ static char *handle_showmanconn(struct a
 	struct mansession_session *session;
 	time_t now = time(NULL);
 #define HSMCONN_FORMAT1 "  %-15.15s  %-55.55s  %-10.10s  %-10.10s  %-8.8s  %-8.8s  %-5.5s  %-5.5s\n"
-#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10d  %-10d  %-8d  %-8d  %-5.5d  %-5.5d\n"
+#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10jd  %-10jd  %-8d  %-8d  %-5.5d  %-5.5d\n"
 	int count = 0;
 	struct ao2_iterator i;
 
@@ -1871,7 +1871,7 @@ static char *handle_showmanconn(struct a
 	i = ao2_iterator_init(sessions, 0);
 	while ((session = ao2_iterator_next(&i))) {
 		ao2_lock(session);
-		ast_cli(a->fd, HSMCONN_FORMAT2, session->username, ast_sockaddr_stringify_addr(&session->addr), (int)(session->sessionstart), (int)(now - session->sessionstart), session->fd, session->inuse, session->readperm, session->writeperm);
+		ast_cli(a->fd, HSMCONN_FORMAT2, session->username, ast_sockaddr_stringify_addr(&session->addr), (intmax_t)(session->sessionstart), (intmax_t)(now - session->sessionstart), session->fd, session->inuse, session->readperm, session->writeperm);
 		count++;
 		ao2_unlock(session);
 		unref_mansession(session);
@@ -7203,9 +7203,11 @@ static char *handle_manager_show_events(
 	return CLI_SUCCESS;
 }
 
+RAII_DECL(struct ao2_container *, events, ao2_cleanup);
+
 static char *handle_manager_show_event(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
 {
-	RAII_VAR(struct ao2_container *, events, NULL, ao2_cleanup);
+	RAII_VAR(struct ao2_container *, events, NULL);
 	struct ao2_iterator it_events;
 	struct ast_xml_doc_item *item, *temp;
 	int length;
