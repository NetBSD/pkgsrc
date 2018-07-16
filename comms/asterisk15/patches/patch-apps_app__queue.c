$NetBSD: patch-apps_app__queue.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- apps/app_queue.c.orig	2018-05-01 20:12:26.000000000 +0000
+++ apps/app_queue.c
@@ -2307,7 +2307,7 @@ static int get_member_status(struct call
 				ast_debug(4, "%s is unavailable because he is paused'\n", member->membername);
 				break;
 			} else if ((conditions & QUEUE_EMPTY_WRAPUP) && member->lastcall && q->wrapuptime && (time(NULL) - q->wrapuptime < member->lastcall)) {
-				ast_debug(4, "%s is unavailable because it has only been %d seconds since his last call (wrapup time is %d)\n", member->membername, (int) (time(NULL) - member->lastcall), q->wrapuptime);
+				ast_debug(4, "%s is unavailable because it has only been %jd seconds since his last call (wrapup time is %jd)\n", member->membername, (intmax_t) (time(NULL) - member->lastcall), (intmax_t)q->wrapuptime);
 				break;
 			} else {
 				ao2_ref(member, -1);
@@ -5549,7 +5549,7 @@ static int wait_our_turn(struct queue_en
 
 			if ((status = get_member_status(qe->parent, qe->max_penalty, qe->min_penalty, qe->raise_penalty, qe->parent->leavewhenempty, 0))) {
 				*reason = QUEUE_LEAVEEMPTY;
-				ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), "NONE", "EXITEMPTY", "%d|%d|%ld", qe->pos, qe->opos, (long) (time(NULL) - qe->start));
+				ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), "NONE", "EXITEMPTY", "%d|%d|%jd", qe->pos, qe->opos, (intmax_t) (time(NULL) - qe->start));
 				res = -1;
 				qe->handled = -1;
 				break;
@@ -6934,8 +6934,8 @@ static int try_calling(struct queue_ent 
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
@@ -6943,8 +6943,8 @@ static int try_calling(struct queue_ent 
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
@@ -8205,8 +8205,8 @@ static int queue_exec(struct ast_channel
 		}
 	}
 
-	ast_debug(1, "queue: %s, expires: %ld, priority: %d\n",
-		args.queuename, (long)qe.expire, prio);
+	ast_debug(1, "queue: %s, expires: %jd, priority: %d\n",
+		args.queuename, (intmax_t)qe.expire, prio);
 
 	qe.chan = chan;
 	qe.prio = prio;
@@ -8257,8 +8257,8 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(args.queuename, ast_channel_uniqueid(chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld",
-				qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+			ast_queue_log(args.queuename, ast_channel_uniqueid(chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd",
+				qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 			break;
 		}
 
@@ -8328,7 +8328,7 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(qe.parent->name, ast_channel_uniqueid(qe.chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld", qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+			ast_queue_log(qe.parent->name, ast_channel_uniqueid(qe.chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd", qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 			break;
 		}
 
@@ -8356,8 +8356,8 @@ stop:
 			if (!qe.handled) {
 				record_abandoned(&qe);
 				ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "ABANDON",
-					"%d|%d|%ld", qe.pos, qe.opos,
-					(long) (time(NULL) - qe.start));
+					"%d|%d|%jd", qe.pos, qe.opos,
+					(intmax_t) (time(NULL) - qe.start));
 				res = -1;
 			} else if (qcontinue) {
 				reason = QUEUE_CONTINUE;
@@ -8368,7 +8368,7 @@ stop:
 			}
 		} else if (qe.valid_digits) {
 			ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITWITHKEY",
-				"%s|%d|%d|%ld", qe.digits, qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+				"%s|%d|%d|%jd", qe.digits, qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 		}
 	}
 
@@ -9631,9 +9631,9 @@ static char *__queues_show(struct manses
 
 			do_print(s, fd, "   Callers: ");
 			for (qe = q->head; qe; qe = qe->next) {
-				ast_str_set(&out, 0, "      %d. %s (wait: %ld:%2.2ld, prio: %d)",
-					pos++, ast_channel_name(qe->chan), (long) (now - qe->start) / 60,
-					(long) (now - qe->start) % 60, qe->prio);
+				ast_str_set(&out, 0, "      %d. %s (wait: %jd:%2.2jd, prio: %d)",
+					pos++, ast_channel_name(qe->chan), (intmax_t) (now - qe->start) / 60,
+					(intmax_t) (now - qe->start) % 60, qe->prio);
 				do_print(s, fd, ast_str_buffer(out));
 			}
 		}
@@ -9672,7 +9672,7 @@ static int word_in_list(const char *list
 	const char *find, *end_find, *end_list;
 
 	/* strip whitespace from front */
-	while(isspace(*list)) {
+	while(isspace((unsigned char)*list)) {
 		list++;
 	}
 
@@ -9681,11 +9681,11 @@ static int word_in_list(const char *list
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
@@ -9698,11 +9698,11 @@ static int word_in_list(const char *list
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
@@ -9994,7 +9994,7 @@ static int manager_queues_status(struct 
 					"CallerIDName: %s\r\n"
 					"ConnectedLineNum: %s\r\n"
 					"ConnectedLineName: %s\r\n"
-					"Wait: %ld\r\n"
+					"Wait: %jd\r\n"
 					"Priority: %d\r\n"
 					"%s"
 					"\r\n",
@@ -10003,7 +10003,7 @@ static int manager_queues_status(struct 
 					S_COR(ast_channel_caller(qe->chan)->id.name.valid, ast_channel_caller(qe->chan)->id.name.str, "unknown"),
 					S_COR(ast_channel_connected(qe->chan)->id.number.valid, ast_channel_connected(qe->chan)->id.number.str, "unknown"),
 					S_COR(ast_channel_connected(qe->chan)->id.name.valid, ast_channel_connected(qe->chan)->id.name.str, "unknown"),
-					(long) (now - qe->start), qe->prio, idText);
+					(intmax_t) (now - qe->start), qe->prio, idText);
 				++q_items;
 			}
 		}
