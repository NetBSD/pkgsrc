$NetBSD: patch-main_manager.c,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- main/manager.c.orig	2016-09-30 20:36:17.000000000 +0000
+++ main/manager.c
@@ -2500,7 +2500,7 @@ static char *handle_showmanconn(struct a
 	struct mansession_session *session;
 	time_t now = time(NULL);
 #define HSMCONN_FORMAT1 "  %-15.15s  %-55.55s  %-10.10s  %-10.10s  %-8.8s  %-8.8s  %-5.5s  %-5.5s\n"
-#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10d  %-10d  %-8d  %-8d  %-5.5d  %-5.5d\n"
+#define HSMCONN_FORMAT2 "  %-15.15s  %-55.55s  %-10jd  %-10jd  %-8d  %-8d  %-5.5d  %-5.5d\n"
 	int count = 0;
 	struct ao2_iterator i;
 
@@ -2526,8 +2526,8 @@ static char *handle_showmanconn(struct a
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
@@ -3367,9 +3367,9 @@ static int action_ping(struct mansession
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
 
@@ -4478,7 +4478,7 @@ static void generate_status(struct manse
 		"DNID: %s\r\n"
 		"EffectiveConnectedLineNum: %s\r\n"
 		"EffectiveConnectedLineName: %s\r\n"
-		"TimeToHangup: %ld\r\n"
+		"TimeToHangup: %jd\r\n"
 		"BridgeID: %s\r\n"
 		"Linkedid: %s\r\n"
 		"Application: %s\r\n"
@@ -4499,7 +4499,7 @@ static void generate_status(struct manse
 		S_OR(ast_channel_dialed(chan)->number.str, ""),
 		S_COR(effective_id.number.valid, effective_id.number.str, "<unknown>"),
 		S_COR(effective_id.name.valid, effective_id.name.str, "<unknown>"),
-		(long)ast_channel_whentohangup(chan)->tv_sec,
+		(intmax_t)ast_channel_whentohangup(chan)->tv_sec,
 		bridge ? bridge->uniqueid : "",
 		ast_channel_linkedid(chan),
 		ast_channel_appl(chan),
@@ -6742,8 +6742,8 @@ static int __attribute__((format(printf,
 	if (timestampevents) {
 		now = ast_tvnow();
 		ast_str_append(&buf, 0,
-			"Timestamp: %ld.%06lu\r\n",
-			(long)now.tv_sec, (unsigned long) now.tv_usec);
+			"Timestamp: %jd.%06lu\r\n",
+			(intmax_t)now.tv_sec, (unsigned long) now.tv_usec);
 	}
 	if (manager_debug) {
 		static int seq;
