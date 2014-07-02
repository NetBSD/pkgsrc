$NetBSD: patch-main_manager.c,v 1.3 2014/07/02 03:06:24 jnemeth Exp $

--- main/manager.c.orig	2014-06-12 16:54:15.000000000 +0000
+++ main/manager.c
@@ -1871,7 +1871,7 @@ static char *handle_showmanconn(struct a
 	struct mansession_session *session;
 	time_t now = time(NULL);
 #define HSMCONN_FORMAT1 "  %-15.15s  %-55.55s  %-10.10s  %-10.10s  %-8.8s  %-8.8s  %-5.5s  %-5.5s\n"
-#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10d  %-10d  %-8d  %-8d  %-5.5d  %-5.5d\n"
+#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10jd  %-10jd  %-8d  %-8d  %-5.5d  %-5.5d\n"
 	int count = 0;
 	struct ao2_iterator i;
 
@@ -1897,8 +1897,8 @@ static char *handle_showmanconn(struct a
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
@@ -5692,11 +5692,13 @@ static void append_channel_vars(struct a
 AST_THREADSTORAGE(manager_event_buf);
 #define MANAGER_EVENT_BUF_INITSIZE   256
 
+RAII_DECL(struct ao2_container *, sessions, ao2_cleanup);
+
 int __ast_manager_event_multichan(int category, const char *event, int chancount,
 	struct ast_channel **chans, const char *file, int line, const char *func,
 	const char *fmt, ...)
 {
-	RAII_VAR(struct ao2_container *, sessions, ao2_global_obj_ref(mgr_sessions), ao2_cleanup);
+	RAII_VAR(struct ao2_container *, sessions, ao2_global_obj_ref(mgr_sessions));
 	struct mansession_session *session;
 	struct manager_custom_hook *hook;
 	struct ast_str *auth = ast_str_alloca(80);
@@ -7313,9 +7315,11 @@ static char *handle_manager_show_events(
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
