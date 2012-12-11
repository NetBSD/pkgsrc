$NetBSD: patch-main_features.c,v 1.1 2012/12/11 08:22:49 jnemeth Exp $

--- main/features.c.orig	2012-10-02 01:27:19.000000000 +0000
+++ main/features.c
@@ -1756,14 +1756,14 @@ static int park_call_full(struct ast_cha
 		"Channel: %s\r\n"
 		"Parkinglot: %s\r\n"
 		"From: %s\r\n"
-		"Timeout: %ld\r\n"
+		"Timeout: %jd\r\n"
 		"CallerIDNum: %s\r\n"
 		"CallerIDName: %s\r\n"
 		"ConnectedLineNum: %s\r\n"
 		"ConnectedLineName: %s\r\n"
 		"Uniqueid: %s\r\n",
 		pu->parkingexten, ast_channel_name(chan), pu->parkinglot->name, event_from,
-		(long)pu->start.tv_sec + (long)(pu->parkingtime/1000) - (long)time(NULL),
+		(intmax_t)pu->start.tv_sec + (intmax_t)(pu->parkingtime/1000) - (intmax_t)time(NULL),
 		S_COR(ast_channel_caller(chan)->id.number.valid, ast_channel_caller(chan)->id.number.str, "<unknown>"),
 		S_COR(ast_channel_caller(chan)->id.name.valid, ast_channel_caller(chan)->id.name.str, "<unknown>"),
 		S_COR(ast_channel_connected(chan)->id.number.valid, ast_channel_connected(chan)->id.number.str, "<unknown>"),
@@ -2322,7 +2322,7 @@ static int builtin_automonitor(struct as
 		len = strlen(touch_monitor) + 50;
 		args = ast_alloca(len);
 		touch_filename = ast_alloca(len);
-		snprintf(touch_filename, len, "%s-%ld-%s", S_OR(touch_monitor_prefix, "auto"), (long)time(NULL), touch_monitor);
+		snprintf(touch_filename, len, "%s-%jd-%s", S_OR(touch_monitor_prefix, "auto"), (intmax_t)time(NULL), touch_monitor);
 		snprintf(args, len, "%s,%s,m", S_OR(touch_format, "wav"), touch_filename);
 	} else {
 		caller_chan_id = ast_strdupa(S_COR(ast_channel_caller(caller_chan)->id.number.valid,
@@ -2332,7 +2332,7 @@ static int builtin_automonitor(struct as
 		len = strlen(caller_chan_id) + strlen(callee_chan_id) + 50;
 		args = ast_alloca(len);
 		touch_filename = ast_alloca(len);
-		snprintf(touch_filename, len, "%s-%ld-%s-%s", S_OR(touch_monitor_prefix, "auto"), (long)time(NULL), caller_chan_id, callee_chan_id);
+		snprintf(touch_filename, len, "%s-%jd-%s-%s", S_OR(touch_monitor_prefix, "auto"), (intmax_t)time(NULL), caller_chan_id, callee_chan_id);
 		snprintf(args, len, "%s,%s,m", S_OR(touch_format, "wav"), touch_filename);
 	}
 
@@ -2434,7 +2434,7 @@ static int builtin_automixmonitor(struct
 		len = strlen(touch_monitor) + 50;
 		args = ast_alloca(len);
 		touch_filename = ast_alloca(len);
-		snprintf(touch_filename, len, "auto-%ld-%s", (long)time(NULL), touch_monitor);
+		snprintf(touch_filename, len, "auto-%jd-%s", (intmax_t)time(NULL), touch_monitor);
 		snprintf(args, len, "%s.%s,b", touch_filename, (touch_format) ? touch_format : "wav");
 	} else {
 		caller_chan_id = ast_strdupa(S_COR(ast_channel_caller(caller_chan)->id.number.valid,
@@ -2444,7 +2444,7 @@ static int builtin_automixmonitor(struct
 		len = strlen(caller_chan_id) + strlen(callee_chan_id) + 50;
 		args = ast_alloca(len);
 		touch_filename = ast_alloca(len);
-		snprintf(touch_filename, len, "auto-%ld-%s-%s", (long)time(NULL), caller_chan_id, callee_chan_id);
+		snprintf(touch_filename, len, "auto-%jd-%s-%s", (intmax_t)time(NULL), caller_chan_id, callee_chan_id);
 		snprintf(args, len, "%s.%s,b", touch_filename, S_OR(touch_format, "wav"));
 	}
 
@@ -7452,10 +7452,10 @@ static char *handle_parkedcalls(struct a
 
 		AST_LIST_LOCK(&curlot->parkings);
 		AST_LIST_TRAVERSE(&curlot->parkings, cur, list) {
-			ast_cli(a->fd, "%-10.10s %-25s (%-15s %-12s %4d) %6lds\n",
+			ast_cli(a->fd, "%-10.10s %-25s (%-15s %-12s %4d) %6jds\n",
 				cur->parkingexten, ast_channel_name(cur->chan), cur->context, cur->exten,
 				cur->priority,
-				(long) (cur->start.tv_sec + (cur->parkingtime / 1000) - time(NULL)));
+				(intmax_t) (cur->start.tv_sec + (cur->parkingtime / 1000) - time(NULL)));
 			++lotparked;
 		}
 		AST_LIST_UNLOCK(&curlot->parkings);
@@ -7531,7 +7531,7 @@ static int manager_parking_status(struct
 	struct ao2_iterator iter;
 	struct ast_parkinglot *curlot;
 	int numparked = 0;
-	long now = time(NULL);
+	time_t now = time(NULL);
 
 	if (!ast_strlen_zero(id))
 		snprintf(idText, sizeof(idText), "ActionID: %s\r\n", id);
@@ -7547,8 +7547,8 @@ static int manager_parking_status(struct
 				"Exten: %d\r\n"
 				"Channel: %s\r\n"
 				"From: %s\r\n"
-				"Timeout: %ld\r\n"
-				"Duration: %ld\r\n"
+				"Timeout: %jd\r\n"
+				"Duration: %jd\r\n"
 				"CallerIDNum: %s\r\n"
 				"CallerIDName: %s\r\n"
 				"ConnectedLineNum: %s\r\n"
@@ -7557,8 +7557,8 @@ static int manager_parking_status(struct
 				"\r\n",
 				curlot->name,
 				cur->parkingnum, ast_channel_name(cur->chan), cur->peername,
-				(long) cur->start.tv_sec + (long) (cur->parkingtime / 1000) - now,
-				now - (long) cur->start.tv_sec,
+				(intmax_t) cur->start.tv_sec + (intmax_t) (cur->parkingtime / 1000) - now,
+				now - (intmax_t) cur->start.tv_sec,
 				S_COR(ast_channel_caller(cur->chan)->id.number.valid, ast_channel_caller(cur->chan)->id.number.str, ""),	/* XXX in other places it is <unknown> */
 				S_COR(ast_channel_caller(cur->chan)->id.name.valid, ast_channel_caller(cur->chan)->id.name.str, ""),
 				S_COR(ast_channel_connected(cur->chan)->id.number.valid, ast_channel_connected(cur->chan)->id.number.str, ""),	/* XXX in other places it is <unknown> */
