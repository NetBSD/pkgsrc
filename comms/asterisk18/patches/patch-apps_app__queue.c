$NetBSD: patch-apps_app__queue.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- apps/app_queue.c.orig	2021-03-25 17:34:21.000000000 +0000
+++ apps/app_queue.c
@@ -5909,8 +5909,8 @@ static void queue_agent_cb(void *userdat
 	} else if (ast_channel_agent_logoff_type() == stasis_message_type(msg)) {
 		ast_queue_log("NONE", agent_blob->snapshot->base->uniqueid,
 			ast_json_string_get(ast_json_object_get(agent_blob->blob, "agent")),
-			"AGENTLOGOFF", "%s|%ld", agent_blob->snapshot->base->name,
-			(long) ast_json_integer_get(ast_json_object_get(agent_blob->blob, "logintime")));
+			"AGENTLOGOFF", "%s|%jd", agent_blob->snapshot->base->name,
+			(intmax_t) ast_json_integer_get(ast_json_object_get(agent_blob->blob, "logintime")));
 	}
 }
 
@@ -7043,8 +7043,8 @@ static int try_calling(struct queue_ent 
 		/* if setinterfacevar is defined, make member variables available to the channel */
 		/* use  pbx_builtin_setvar to set a load of variables with one call */
 		if (qe->parent->setinterfacevar && interfacevar) {
-			ast_str_set(&interfacevar, 0, "MEMBERINTERFACE=%s,MEMBERNAME=%s,MEMBERCALLS=%d,MEMBERLASTCALL=%ld,MEMBERPENALTY=%d,MEMBERDYNAMIC=%d,MEMBERREALTIME=%d",
-				member->interface, member->membername, member->calls, (long)member->lastcall, member->penalty, member->dynamic, member->realtime);
+			ast_str_set(&interfacevar, 0, "MEMBERINTERFACE=%s,MEMBERNAME=%s,MEMBERCALLS=%d,MEMBERLASTCALL=%jd,MEMBERPENALTY=%d,MEMBERDYNAMIC=%d,MEMBERREALTIME=%d",
+				member->interface, member->membername, member->calls, (intmax_t)member->lastcall, member->penalty, member->dynamic, member->realtime);
 			pbx_builtin_setvar_multiple(qe->chan, ast_str_buffer(interfacevar));
 			pbx_builtin_setvar_multiple(peer, ast_str_buffer(interfacevar));
 		}
@@ -7052,8 +7052,8 @@ static int try_calling(struct queue_ent 
 		/* if setqueueentryvar is defined, make queue entry (i.e. the caller) variables available to the channel */
 		/* use  pbx_builtin_setvar to set a load of variables with one call */
 		if (qe->parent->setqueueentryvar && interfacevar) {
-			ast_str_set(&interfacevar, 0, "QEHOLDTIME=%ld,QEORIGINALPOS=%d",
-				(long) (time(NULL) - qe->start), qe->opos);
+			ast_str_set(&interfacevar, 0, "QEHOLDTIME=%jd,QEORIGINALPOS=%d",
+				(intmax_t) (time(NULL) - qe->start), qe->opos);
 			pbx_builtin_setvar_multiple(qe->chan, ast_str_buffer(interfacevar));
 			pbx_builtin_setvar_multiple(peer, ast_str_buffer(interfacevar));
 		}
@@ -8335,8 +8335,8 @@ static int queue_exec(struct ast_channel
 		}
 	}
 
-	ast_debug(1, "queue: %s, expires: %ld, priority: %d\n",
-		args.queuename, (long)qe.expire, prio);
+	ast_debug(1, "queue: %s, expires: %jd, priority: %d\n",
+		args.queuename, (intmax_t)qe.expire, prio);
 
 	qe.chan = chan;
 	qe.prio = prio;
@@ -8402,8 +8402,8 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(args.queuename, ast_channel_uniqueid(chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld",
-				qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+			ast_queue_log(args.queuename, ast_channel_uniqueid(chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd",
+				qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 			break;
 		}
 
@@ -8473,7 +8473,7 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(qe.parent->name, ast_channel_uniqueid(qe.chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld", qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+			ast_queue_log(qe.parent->name, ast_channel_uniqueid(qe.chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd", qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 			break;
 		}
 
@@ -8514,7 +8514,7 @@ stop:
 			}
 		} else if (qe.valid_digits) {
 			ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITWITHKEY",
-				"%s|%d|%d|%ld", qe.digits, qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+				"%s|%d|%d|%jd", qe.digits, qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 		}
 	}
 
@@ -9871,7 +9871,7 @@ static int word_in_list(const char *list
 	const char *find, *end_find, *end_list;
 
 	/* strip whitespace from front */
-	while(isspace(*list)) {
+	while(isspace((unsigned char)*list)) {
 		list++;
 	}
 
@@ -9880,11 +9880,11 @@ static int word_in_list(const char *list
 		if (find != list && *(find - 1) != ' ') {
 			list = find;
 			/* strip word from front */
-			while(!isspace(*list) && *list != '\0') {
+			while(!isspace((unsigned char)*list) && *list != '\0') {
 				list++;
 			}
 			/* strip whitespace from front */
-			while(isspace(*list)) {
+			while(isspace((unsigned char)*list)) {
 				list++;
 			}
 			continue;
@@ -9897,11 +9897,11 @@ static int word_in_list(const char *list
 		if (end_find == end_list || *end_find != ' ') {
 			list = find;
 			/* strip word from front */
-			while(!isspace(*list) && *list != '\0') {
+			while(!isspace((unsigned char)*list) && *list != '\0') {
 				list++;
 			}
 			/* strip whitespace from front */
-			while(isspace(*list)) {
+			while(isspace((unsigned char)*list)) {
 				list++;
 			}
 			continue;
@@ -10194,7 +10194,7 @@ static int manager_queues_status(struct 
 					"CallerIDName: %s\r\n"
 					"ConnectedLineNum: %s\r\n"
 					"ConnectedLineName: %s\r\n"
-					"Wait: %ld\r\n"
+					"Wait: %jd\r\n"
 					"Priority: %d\r\n"
 					"%s"
 					"\r\n",
@@ -10203,7 +10203,7 @@ static int manager_queues_status(struct 
 					S_COR(ast_channel_caller(qe->chan)->id.name.valid, ast_channel_caller(qe->chan)->id.name.str, "unknown"),
 					S_COR(ast_channel_connected(qe->chan)->id.number.valid, ast_channel_connected(qe->chan)->id.number.str, "unknown"),
 					S_COR(ast_channel_connected(qe->chan)->id.name.valid, ast_channel_connected(qe->chan)->id.name.str, "unknown"),
-					(long) (now - qe->start), qe->prio, idText);
+					(intmax_t) (now - qe->start), qe->prio, idText);
 				++q_items;
 			}
 		}
