$NetBSD: patch-main_manager.c,v 1.5 2015/05/19 07:52:14 jnemeth Exp $

--- main/manager.c.orig	2014-12-17 09:24:50.000000000 +0000
+++ main/manager.c
@@ -1886,7 +1886,7 @@ static char *handle_showmanconn(struct a
 	struct mansession_session *session;
 	time_t now = time(NULL);
 #define HSMCONN_FORMAT1 "  %-15.15s  %-55.55s  %-10.10s  %-10.10s  %-8.8s  %-8.8s  %-5.5s  %-5.5s\n"
-#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10d  %-10d  %-8d  %-8d  %-5.5d  %-5.5d\n"
+#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10jd  %-10jd  %-8d  %-8d  %-5.5d  %-5.5d\n"
 	int count = 0;
 	struct ao2_iterator i;
 
@@ -1912,8 +1912,8 @@ static char *handle_showmanconn(struct a
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
@@ -2726,9 +2726,9 @@ static int action_ping(struct mansession
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
 
@@ -3580,7 +3580,7 @@ static int action_status(struct mansessi
 	struct ast_channel *c;
 	char bridge[256];
 	struct timeval now = ast_tvnow();
-	long elapsed_seconds = 0;
+	intmax_t elapsed_seconds = 0;
 	int channels = 0;
 	int all = ast_strlen_zero(name); /* set if we want all channels */
 	const char *id = astman_get_header(m, "ActionID");
@@ -3670,7 +3670,7 @@ static int action_status(struct mansessi
 			"Context: %s\r\n"
 			"Extension: %s\r\n"
 			"Priority: %d\r\n"
-			"Seconds: %ld\r\n"
+			"Seconds: %jd\r\n"
 			"%s"
 			"Uniqueid: %s\r\n"
 			"%s"
@@ -3684,7 +3684,7 @@ static int action_status(struct mansessi
 			ast_channel_accountcode(c),
 			ast_channel_state(c),
 			ast_state2str(ast_channel_state(c)), ast_channel_context(c),
-			ast_channel_exten(c), ast_channel_priority(c), (long)elapsed_seconds, bridge, ast_channel_uniqueid(c), ast_str_buffer(str), idText);
+			ast_channel_exten(c), ast_channel_priority(c), (intmax_t)elapsed_seconds, bridge, ast_channel_uniqueid(c), ast_str_buffer(str), idText);
 		} else {
 			astman_append(s,
 				"Event: Status\r\n"
@@ -5735,11 +5735,13 @@ static void append_channel_vars(struct a
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
 	struct ast_str *auth = ast_str_alloca(MAX_AUTH_PERM_STRING);
@@ -5765,8 +5767,8 @@ int __ast_manager_event_multichan(int ca
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
@@ -7361,9 +7363,11 @@ static char *handle_manager_show_events(
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
