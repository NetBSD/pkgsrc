$NetBSD: patch-apps_app__queue.c,v 1.3 2013/12/23 01:34:03 jnemeth Exp $

--- apps/app_queue.c.orig	2013-09-12 00:02:37.000000000 +0000
+++ apps/app_queue.c
@@ -4735,7 +4735,7 @@ static int wait_our_turn(struct queue_en
 
 			if ((status = get_member_status(qe->parent, qe->max_penalty, qe->min_penalty, qe->parent->leavewhenempty))) {
 				*reason = QUEUE_LEAVEEMPTY;
-				ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), "NONE", "EXITEMPTY", "%d|%d|%ld", qe->pos, qe->opos, (long) time(NULL) - qe->start);
+				ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), "NONE", "EXITEMPTY", "%d|%d|%jd", qe->pos, qe->opos, (intmax_t) time(NULL) - qe->start);
 				leave_queue(qe);
 				break;
 			}
@@ -4975,12 +4975,12 @@ static void send_agent_complete(const st
 		"Channel: %s\r\n"
 		"Member: %s\r\n"
 		"MemberName: %s\r\n"
-		"HoldTime: %ld\r\n"
-		"TalkTime: %ld\r\n"
+		"HoldTime: %jd\r\n"
+		"TalkTime: %jd\r\n"
 		"Reason: %s\r\n"
 		"%s",
 		queuename, ast_channel_uniqueid(qe->chan), ast_channel_name(peer), member->interface, member->membername,
-		(long)(callstart - qe->start), (long)(time(NULL) - callstart), reason,
+		(intmax_t)(callstart - qe->start), (intmax_t)(time(NULL) - callstart), reason,
 		qe->parent->eventwhencalled == QUEUE_EVENT_VARIABLES ? vars2manager(qe->chan, vars, vars_len) : "");
 }
 
@@ -5023,9 +5023,9 @@ static void queue_transfer_fixup(void *d
 	int callcompletedinsl = qtds->callcompletedinsl;
 	struct ast_datastore *datastore;
 
-	ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), member->membername, "TRANSFER", "%s|%s|%ld|%ld|%d",
-				ast_channel_exten(new_chan), ast_channel_context(new_chan), (long) (callstart - qe->start),
-				(long) (time(NULL) - callstart), qe->opos);
+	ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), member->membername, "TRANSFER", "%s|%s|%jd|%jd|%d",
+				ast_channel_exten(new_chan), ast_channel_context(new_chan), (intmax_t) (callstart - qe->start),
+				(intmax_t) (time(NULL) - callstart), qe->opos);
 
 	update_queue(qe->parent, member, callcompletedinsl, (time(NULL) - callstart));
 
@@ -5542,7 +5542,7 @@ static int try_calling(struct queue_ent 
 			} else if (ast_check_hangup(qe->chan)) {
 				/* Caller must have hung up just before being connected */
 				ast_log(LOG_NOTICE, "Caller was about to talk to agent on %s but the caller hungup.\n", ast_channel_name(peer));
-				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "ABANDON", "%d|%d|%ld", qe->pos, qe->opos, (long) time(NULL) - qe->start);
+				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "ABANDON", "%d|%d|%jd", qe->pos, qe->opos, (intmax_t) time(NULL) - qe->start);
 				record_abandoned(qe);
 				ast_autoservice_chan_hangup_peer(qe->chan, peer);
 				ao2_ref(member, -1);
@@ -5591,8 +5591,8 @@ static int try_calling(struct queue_ent 
 		/* if setqueueentryvar is defined, make queue entry (i.e. the caller) variables available to the channel */
 		/* use  pbx_builtin_setvar to set a load of variables with one call */
 		if (qe->parent->setqueueentryvar) {
-			snprintf(interfacevar, sizeof(interfacevar), "QEHOLDTIME=%ld,QEORIGINALPOS=%d",
-				(long) time(NULL) - qe->start, qe->opos);
+			snprintf(interfacevar, sizeof(interfacevar), "QEHOLDTIME=%jd,QEORIGINALPOS=%d",
+				(intmax_t) time(NULL) - qe->start, qe->opos);
 			pbx_builtin_setvar_multiple(qe->chan, interfacevar);
 			pbx_builtin_setvar_multiple(peer, interfacevar);
 		}
@@ -5809,8 +5809,8 @@ static int try_calling(struct queue_ent 
 			}
 		}
 		qe->handled++;
-		ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "CONNECT", "%ld|%s|%ld", (long) time(NULL) - qe->start, ast_channel_uniqueid(peer),
-													(long)(orig - to > 0 ? (orig - to) / 1000 : 0));
+		ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "CONNECT", "%jd|%s|%jd", (intmax_t) time(NULL) - qe->start, ast_channel_uniqueid(peer),
+													(intmax_t)(orig - to > 0 ? (orig - to) / 1000 : 0));
 
 		if (ast_channel_cdr(qe->chan)) {
 			struct ast_cdr *cdr;
@@ -5864,12 +5864,12 @@ static int try_calling(struct queue_ent 
 					"Channel: %s\r\n"
 					"Member: %s\r\n"
 					"MemberName: %s\r\n"
-					"HoldTime: %ld\r\n"
+					"HoldTime: %jd\r\n"
 					"BridgedChannel: %s\r\n"
-					"RingTime: %ld\r\n"
+					"RingTime: %jd\r\n"
 					"%s",
 					queuename, ast_channel_uniqueid(qe->chan), ast_channel_name(peer), member->interface, member->membername,
-					(long) time(NULL) - qe->start, ast_channel_uniqueid(peer), (long)(orig - to > 0 ? (orig - to) / 1000 : 0),
+					(intmax_t) time(NULL) - qe->start, ast_channel_uniqueid(peer), (intmax_t)(orig - to > 0 ? (orig - to) / 1000 : 0),
 					qe->parent->eventwhencalled == QUEUE_EVENT_VARIABLES ? vars2manager(qe->chan, vars, sizeof(vars)) : "");
 		ast_copy_string(oldcontext, ast_channel_context(qe->chan), sizeof(oldcontext));
 		ast_copy_string(oldexten, ast_channel_exten(qe->chan), sizeof(oldexten));
@@ -5901,17 +5901,17 @@ static int try_calling(struct queue_ent 
 
 			/* detect a blind transfer */
 			if (!(ast_channel_softhangup_internal_flag(qe->chan) | ast_channel_softhangup_internal_flag(peer)) && (strcasecmp(oldcontext, ast_channel_context(qe->chan)) || strcasecmp(oldexten, ast_channel_exten(qe->chan)))) {
-				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "TRANSFER", "%s|%s|%ld|%ld|%d",
-					ast_channel_exten(qe->chan), ast_channel_context(qe->chan), (long) (callstart - qe->start),
-					(long) (time(NULL) - callstart), qe->opos);
+				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "TRANSFER", "%s|%s|%jd|%jd|%d",
+					ast_channel_exten(qe->chan), ast_channel_context(qe->chan), (intmax_t) (callstart - qe->start),
+					(intmax_t) (time(NULL) - callstart), qe->opos);
 				send_agent_complete(qe, queuename, peer, member, callstart, vars, sizeof(vars), TRANSFER);
 			} else if (ast_check_hangup(qe->chan) && !ast_check_hangup(peer)) {
-				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "COMPLETECALLER", "%ld|%ld|%d",
-					(long) (callstart - qe->start), (long) (time(NULL) - callstart), qe->opos);
+				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "COMPLETECALLER", "%jd|%jd|%d",
+					(intmax_t) (callstart - qe->start), (intmax_t) (time(NULL) - callstart), qe->opos);
 				send_agent_complete(qe, queuename, peer, member, callstart, vars, sizeof(vars), CALLER);
 			} else {
-				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "COMPLETEAGENT", "%ld|%ld|%d",
-					(long) (callstart - qe->start), (long) (time(NULL) - callstart), qe->opos);
+				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "COMPLETEAGENT", "%jd|%jd|%d",
+					(intmax_t) (callstart - qe->start), (intmax_t) (time(NULL) - callstart), qe->opos);
 				send_agent_complete(qe, queuename, peer, member, callstart, vars, sizeof(vars), AGENT);
 			}
 			if ((tds = ast_channel_datastore_find(qe->chan, &queue_transfer_info, NULL))) {
@@ -7088,8 +7088,8 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(args.queuename, ast_channel_uniqueid(chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld",
-				qe.pos, qe.opos, (long) time(NULL) - qe.start);
+			ast_queue_log(args.queuename, ast_channel_uniqueid(chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd",
+				qe.pos, qe.opos, (intmax_t) time(NULL) - qe.start);
 			break;
 		}
 
@@ -7133,7 +7133,7 @@ check_turns:
 			if ((status = get_member_status(qe.parent, qe.max_penalty, qe.min_penalty, qe.parent->leavewhenempty))) {
 				record_abandoned(&qe);
 				reason = QUEUE_LEAVEEMPTY;
-				ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITEMPTY", "%d|%d|%ld", qe.pos, qe.opos, (long)(time(NULL) - qe.start));
+				ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITEMPTY", "%d|%d|%jd", qe.pos, qe.opos, (intmax_t)(time(NULL) - qe.start));
 				res = 0;
 				break;
 			}
@@ -7155,7 +7155,7 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(qe.parent->name, ast_channel_uniqueid(qe.chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld", qe.pos, qe.opos, (long) time(NULL) - qe.start);
+			ast_queue_log(qe.parent->name, ast_channel_uniqueid(qe.chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd", qe.pos, qe.opos, (intmax_t) time(NULL) - qe.start);
 			break;
 		}
 
@@ -7183,8 +7183,8 @@ stop:
 			if (!qe.handled) {
 				record_abandoned(&qe);
 				ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "ABANDON",
-					"%d|%d|%ld", qe.pos, qe.opos,
-					(long) time(NULL) - qe.start);
+					"%d|%d|%jd", qe.pos, qe.opos,
+					(intmax_t) time(NULL) - qe.start);
 				res = -1;
 			} else if (qcontinue) {
 				reason = QUEUE_CONTINUE;
