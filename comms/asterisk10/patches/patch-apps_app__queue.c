$NetBSD: patch-apps_app__queue.c,v 1.3 2012/10/09 01:36:32 jnemeth Exp $

--- apps/app_queue.c.orig	2012-09-07 21:49:16.000000000 +0000
+++ apps/app_queue.c
@@ -3449,8 +3449,8 @@ static void record_abandoned(struct queu
 		"Uniqueid: %s\r\n"
 		"Position: %d\r\n"
 		"OriginalPosition: %d\r\n"
-		"HoldTime: %d\r\n",
-		qe->parent->name, qe->chan->uniqueid, qe->pos, qe->opos, (int)(time(NULL) - qe->start));
+		"HoldTime: %jd\r\n",
+		qe->parent->name, qe->chan->uniqueid, qe->pos, qe->opos, (intmax_t)(time(NULL) - qe->start));
 
 	qe->parent->callsabandoned++;
 	ao2_unlock(qe->parent);
@@ -4109,7 +4109,7 @@ static int wait_our_turn(struct queue_en
 
 			if ((status = get_member_status(qe->parent, qe->max_penalty, qe->min_penalty, qe->parent->leavewhenempty))) {
 				*reason = QUEUE_LEAVEEMPTY;
-				ast_queue_log(qe->parent->name, qe->chan->uniqueid, "NONE", "EXITEMPTY", "%d|%d|%ld", qe->pos, qe->opos, (long) time(NULL) - qe->start);
+				ast_queue_log(qe->parent->name, qe->chan->uniqueid, "NONE", "EXITEMPTY", "%d|%d|%jd", qe->pos, qe->opos, (intmax_t) time(NULL) - qe->start);
 				leave_queue(qe);
 				break;
 			}
@@ -4315,12 +4315,12 @@ static void send_agent_complete(const st
 		"Channel: %s\r\n"
 		"Member: %s\r\n"
 		"MemberName: %s\r\n"
-		"HoldTime: %ld\r\n"
-		"TalkTime: %ld\r\n"
+		"HoldTime: %jd\r\n"
+		"TalkTime: %jd\r\n"
 		"Reason: %s\r\n"
 		"%s",
 		queuename, qe->chan->uniqueid, peer->name, member->interface, member->membername,
-		(long)(callstart - qe->start), (long)(time(NULL) - callstart), reason,
+		(intmax_t)(callstart - qe->start), (intmax_t)(time(NULL) - callstart), reason,
 		qe->parent->eventwhencalled == QUEUE_EVENT_VARIABLES ? vars2manager(qe->chan, vars, vars_len) : "");
 }
 
@@ -4363,9 +4363,9 @@ static void queue_transfer_fixup(void *d
 	int callcompletedinsl = qtds->callcompletedinsl;
 	struct ast_datastore *datastore;
 
-	ast_queue_log(qe->parent->name, qe->chan->uniqueid, member->membername, "TRANSFER", "%s|%s|%ld|%ld|%d",
-				new_chan->exten, new_chan->context, (long) (callstart - qe->start),
-				(long) (time(NULL) - callstart), qe->opos);
+	ast_queue_log(qe->parent->name, qe->chan->uniqueid, member->membername, "TRANSFER", "%s|%s|%jd|%jd|%d",
+				new_chan->exten, new_chan->context, (intmax_t) (callstart - qe->start),
+				(intmax_t) (time(NULL) - callstart), qe->opos);
 
 	update_queue(qe->parent, member, callcompletedinsl, (time(NULL) - callstart));
 	
@@ -4854,7 +4854,7 @@ static int try_calling(struct queue_ent 
 			} else if (ast_check_hangup(qe->chan)) {
 				/* Caller must have hung up just before being connected */
 				ast_log(LOG_NOTICE, "Caller was about to talk to agent on %s but the caller hungup.\n", peer->name);
-				ast_queue_log(queuename, qe->chan->uniqueid, member->membername, "ABANDON", "%d|%d|%ld", qe->pos, qe->opos, (long) time(NULL) - qe->start);
+				ast_queue_log(queuename, qe->chan->uniqueid, member->membername, "ABANDON", "%d|%d|%jd", qe->pos, qe->opos, (intmax_t) time(NULL) - qe->start);
 				record_abandoned(qe);
 				ast_hangup(peer);
 				ao2_ref(member, -1);
@@ -4901,8 +4901,8 @@ static int try_calling(struct queue_ent 
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
@@ -5158,8 +5158,8 @@ static int try_calling(struct queue_ent 
 				ast_log(LOG_WARNING, "Asked to execute an AGI on this channel, but could not find application (agi)!\n");
 		}
 		qe->handled++;
-		ast_queue_log(queuename, qe->chan->uniqueid, member->membername, "CONNECT", "%ld|%s|%ld", (long) time(NULL) - qe->start, peer->uniqueid,
-													(long)(orig - to > 0 ? (orig - to) / 1000 : 0));
+		ast_queue_log(queuename, qe->chan->uniqueid, member->membername, "CONNECT", "%jd|%s|%jd", (intmax_t) time(NULL) - qe->start, peer->uniqueid,
+													(intmax_t)(orig - to > 0 ? (orig - to) / 1000 : 0));
 
 		if (qe->chan->cdr) {
 			struct ast_cdr *cdr;
@@ -5195,12 +5195,12 @@ static int try_calling(struct queue_ent 
 					"Channel: %s\r\n"
 					"Member: %s\r\n"
 					"MemberName: %s\r\n"
-					"Holdtime: %ld\r\n"
+					"Holdtime: %jd\r\n"
 					"BridgedChannel: %s\r\n"
-					"Ringtime: %ld\r\n"
+					"Ringtime: %jd\r\n"
 					"%s",
 					queuename, qe->chan->uniqueid, peer->name, member->interface, member->membername,
-					(long) time(NULL) - qe->start, peer->uniqueid, (long)(orig - to > 0 ? (orig - to) / 1000 : 0),
+					(intmax_t) time(NULL) - qe->start, peer->uniqueid, (intmax_t)(orig - to > 0 ? (orig - to) / 1000 : 0),
 					qe->parent->eventwhencalled == QUEUE_EVENT_VARIABLES ? vars2manager(qe->chan, vars, sizeof(vars)) : "");
 		ast_copy_string(oldcontext, qe->chan->context, sizeof(oldcontext));
 		ast_copy_string(oldexten, qe->chan->exten, sizeof(oldexten));
@@ -5232,17 +5232,17 @@ static int try_calling(struct queue_ent 
 
 			/* detect a blind transfer */
 			if (!(qe->chan->_softhangup | peer->_softhangup) && (strcasecmp(oldcontext, qe->chan->context) || strcasecmp(oldexten, qe->chan->exten))) {
-				ast_queue_log(queuename, qe->chan->uniqueid, member->membername, "TRANSFER", "%s|%s|%ld|%ld|%d",
-					qe->chan->exten, qe->chan->context, (long) (callstart - qe->start),
-					(long) (time(NULL) - callstart), qe->opos);
+				ast_queue_log(queuename, qe->chan->uniqueid, member->membername, "TRANSFER", "%s|%s|%jd|%jd|%d",
+					qe->chan->exten, qe->chan->context, (intmax_t) (callstart - qe->start),
+					(intmax_t) (time(NULL) - callstart), qe->opos);
 				send_agent_complete(qe, queuename, peer, member, callstart, vars, sizeof(vars), TRANSFER);
 			} else if (ast_check_hangup(qe->chan)) {
-				ast_queue_log(queuename, qe->chan->uniqueid, member->membername, "COMPLETECALLER", "%ld|%ld|%d",
-					(long) (callstart - qe->start), (long) (time(NULL) - callstart), qe->opos);
+				ast_queue_log(queuename, qe->chan->uniqueid, member->membername, "COMPLETECALLER", "%jd|%jd|%d",
+					(intmax_t) (callstart - qe->start), (intmax_t) (time(NULL) - callstart), qe->opos);
 				send_agent_complete(qe, queuename, peer, member, callstart, vars, sizeof(vars), CALLER);
 			} else {
-				ast_queue_log(queuename, qe->chan->uniqueid, member->membername, "COMPLETEAGENT", "%ld|%ld|%d",
-					(long) (callstart - qe->start), (long) (time(NULL) - callstart), qe->opos);
+				ast_queue_log(queuename, qe->chan->uniqueid, member->membername, "COMPLETEAGENT", "%jd|%jd|%d",
+					(intmax_t) (callstart - qe->start), (intmax_t) (time(NULL) - callstart), qe->opos);
 				send_agent_complete(qe, queuename, peer, member, callstart, vars, sizeof(vars), AGENT);
 			}
 			if ((tds = ast_channel_datastore_find(qe->chan, &queue_transfer_info, NULL))) {	
@@ -6183,8 +6183,8 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(args.queuename, chan->uniqueid,"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld", 
-				qe.pos, qe.opos, (long) time(NULL) - qe.start);
+			ast_queue_log(args.queuename, chan->uniqueid,"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd", 
+				qe.pos, qe.opos, (intmax_t) time(NULL) - qe.start);
 			break;
 		}
 
@@ -6226,7 +6226,7 @@ check_turns:
 			if ((status = get_member_status(qe.parent, qe.max_penalty, qe.min_penalty, qe.parent->leavewhenempty))) {
 				record_abandoned(&qe);
 				reason = QUEUE_LEAVEEMPTY;
-				ast_queue_log(args.queuename, chan->uniqueid, "NONE", "EXITEMPTY", "%d|%d|%ld", qe.pos, qe.opos, (long)(time(NULL) - qe.start));
+				ast_queue_log(args.queuename, chan->uniqueid, "NONE", "EXITEMPTY", "%d|%d|%jd", qe.pos, qe.opos, (intmax_t)(time(NULL) - qe.start));
 				res = 0;
 				break;
 			}
@@ -6248,7 +6248,7 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(qe.parent->name, qe.chan->uniqueid,"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld", qe.pos, qe.opos, (long) time(NULL) - qe.start);
+			ast_queue_log(qe.parent->name, qe.chan->uniqueid,"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd", qe.pos, qe.opos, (intmax_t) time(NULL) - qe.start);
 			break;
 		}
 
@@ -6275,8 +6275,8 @@ stop:
 			if (!qe.handled) {
 				record_abandoned(&qe);
 				ast_queue_log(args.queuename, chan->uniqueid, "NONE", "ABANDON",
-					"%d|%d|%ld", qe.pos, qe.opos,
-					(long) time(NULL) - qe.start);
+					"%d|%d|%jd", qe.pos, qe.opos,
+					(intmax_t) time(NULL) - qe.start);
 				res = -1;
 			} else if (qcontinue) {
 				reason = QUEUE_CONTINUE;
