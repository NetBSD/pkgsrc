$NetBSD: patch-apps_app__queue.c,v 1.4 2021/01/02 22:45:43 jnemeth Exp $

--- apps/app_queue.c.orig	2020-11-19 12:31:10.000000000 +0000
+++ apps/app_queue.c
@@ -5433,7 +5433,7 @@ static int wait_our_turn(struct queue_en
 			if ((status = get_member_status(qe->parent, qe->max_penalty, qe->min_penalty, qe->parent->leavewhenempty, 0))) {
 				record_abandoned(qe);
 				*reason = QUEUE_LEAVEEMPTY;
-				ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), "NONE", "EXITEMPTY", "%d|%d|%ld", qe->pos, qe->opos, (long) (time(NULL) - qe->start));
+				ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), "NONE", "EXITEMPTY", "%d|%d|%jd", qe->pos, qe->opos, (intmax_t) (time(NULL) - qe->start));
 				res = -1;
 				qe->handled = -1;
 				break;
@@ -5688,8 +5688,8 @@ static void queue_agent_cb(void *userdat
 	} else if (ast_channel_agent_logoff_type() == stasis_message_type(msg)) {
 		ast_queue_log("NONE", agent_blob->snapshot->uniqueid,
 			ast_json_string_get(ast_json_object_get(agent_blob->blob, "agent")),
-			"AGENTLOGOFF", "%s|%ld", agent_blob->snapshot->name,
-			(long) ast_json_integer_get(ast_json_object_get(agent_blob->blob, "logintime")));
+			"AGENTLOGOFF", "%s|%jd", agent_blob->snapshot->name,
+			(intmax_t) ast_json_integer_get(ast_json_object_get(agent_blob->blob, "logintime")));
 	}
 }
 
@@ -5873,10 +5873,10 @@ static void log_attended_transfer(struct
 		return;
 	}
 
-	ast_queue_log(queue_data->queue->name, queue_data->caller_uniqueid, queue_data->member->membername, "ATTENDEDTRANSFER", "%s|%ld|%ld|%d",
+	ast_queue_log(queue_data->queue->name, queue_data->caller_uniqueid, queue_data->member->membername, "ATTENDEDTRANSFER", "%s|%jd|%jd|%d",
 			ast_str_buffer(transfer_str),
-			(long) (queue_data->starttime - queue_data->holdstart),
-			(long) (time(NULL) - queue_data->starttime), queue_data->caller_pos);
+			(intmax_t) (queue_data->starttime - queue_data->holdstart),
+			(intmax_t) (time(NULL) - queue_data->starttime), queue_data->caller_pos);
 }
 
 /*!
@@ -5962,10 +5962,10 @@ static void handle_blind_transfer(void *
 
 	ast_debug(3, "Detected blind transfer in queue %s\n", queue_data->queue->name);
 	ast_queue_log(queue_data->queue->name, queue_data->caller_uniqueid, queue_data->member->membername,
-			"BLINDTRANSFER", "%s|%s|%ld|%ld|%d",
+			"BLINDTRANSFER", "%s|%s|%jd|%jd|%d",
 			exten, context,
-			(long) (queue_data->starttime - queue_data->holdstart),
-			(long) (time(NULL) - queue_data->starttime), queue_data->caller_pos);
+			(intmax_t) (queue_data->starttime - queue_data->holdstart),
+			(intmax_t) (time(NULL) - queue_data->starttime), queue_data->caller_pos);
 
 	send_agent_complete(queue_data->queue->name, caller_snapshot, member_snapshot, queue_data->member,
 			queue_data->holdstart, queue_data->starttime, TRANSFER);
@@ -6223,9 +6223,9 @@ static void handle_hangup(void *userdata
 			channel_blob->snapshot->name);
 
 	ast_queue_log(queue_data->queue->name, queue_data->caller_uniqueid, queue_data->member->membername,
-			reason == CALLER ? "COMPLETECALLER" : "COMPLETEAGENT", "%ld|%ld|%d",
-		(long) (queue_data->starttime - queue_data->holdstart),
-		(long) (time(NULL) - queue_data->starttime), queue_data->caller_pos);
+			reason == CALLER ? "COMPLETECALLER" : "COMPLETEAGENT", "%jd|%jd|%d",
+		(intmax_t) (queue_data->starttime - queue_data->holdstart),
+		(intmax_t) (time(NULL) - queue_data->starttime), queue_data->caller_pos);
 
 	send_agent_complete(queue_data->queue->name, caller_snapshot, member_snapshot, queue_data->member,
 			queue_data->holdstart, queue_data->starttime, reason);
@@ -6781,7 +6781,7 @@ static int try_calling(struct queue_ent 
 			} else if (ast_check_hangup(qe->chan)) {
 				/* Caller must have hung up just before being connected */
 				ast_log(LOG_NOTICE, "Caller was about to talk to agent on %s but the caller hungup.\n", ast_channel_name(peer));
-				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "ABANDON", "%d|%d|%ld", qe->pos, qe->opos, (long) (time(NULL) - qe->start));
+				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "ABANDON", "%d|%d|%jd", qe->pos, qe->opos, (intmax_t) (time(NULL) - qe->start));
 				record_abandoned(qe);
 				qe->handled = -1;
 				ast_channel_publish_dial(qe->chan, peer, member->interface, ast_hangup_cause_to_dial_status(ast_channel_hangupcause(peer)));
@@ -6822,8 +6822,8 @@ static int try_calling(struct queue_ent 
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
@@ -6831,8 +6831,8 @@ static int try_calling(struct queue_ent 
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
@@ -6959,7 +6959,7 @@ static int try_calling(struct queue_ent 
 		}
 		qe->handled++;
 
-		ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "CONNECT", "%ld|%s|%ld", (long) (time(NULL) - qe->start), ast_channel_uniqueid(peer),
+		ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "CONNECT", "%jd|%s|%ld", (intmax_t) (time(NULL) - qe->start), ast_channel_uniqueid(peer),
 													(long)(orig - to > 0 ? (orig - to) / 1000 : 0));
 
 		blob = ast_json_pack("{s: s, s: s, s: s, s: I, s: I}",
@@ -8036,8 +8036,8 @@ static int queue_exec(struct ast_channel
 		}
 	}
 
-	ast_debug(1, "queue: %s, expires: %ld, priority: %d\n",
-		args.queuename, (long)qe.expire, prio);
+	ast_debug(1, "queue: %s, expires: %jd, priority: %d\n",
+		args.queuename, (intmax_t)qe.expire, prio);
 
 	qe.chan = chan;
 	qe.prio = prio;
@@ -8087,8 +8087,8 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(args.queuename, ast_channel_uniqueid(chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld",
-				qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+			ast_queue_log(args.queuename, ast_channel_uniqueid(chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd",
+				qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 			break;
 		}
 
@@ -8115,7 +8115,7 @@ check_turns:
 			reason = QUEUE_TIMEOUT;
 			res = 0;
 			ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITWITHTIMEOUT",
-				"%d|%d|%ld", qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+				"%d|%d|%jd", qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 			break;
 		}
 
@@ -8135,7 +8135,7 @@ check_turns:
 			if ((status = get_member_status(qe.parent, qe.max_penalty, qe.min_penalty, qe.parent->leavewhenempty, 0))) {
 				record_abandoned(&qe);
 				reason = QUEUE_LEAVEEMPTY;
-				ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITEMPTY", "%d|%d|%ld", qe.pos, qe.opos, (long)(time(NULL) - qe.start));
+				ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITEMPTY", "%d|%d|%jd", qe.pos, qe.opos, (intmax_t)(time(NULL) - qe.start));
 				res = 0;
 				break;
 			}
@@ -8145,7 +8145,7 @@ check_turns:
 		if (noption && tries >= ao2_container_count(qe.parent->members)) {
 			ast_verb(3, "Exiting on time-out cycle\n");
 			ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITWITHTIMEOUT",
-				"%d|%d|%ld", qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+				"%d|%d|%jd", qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
@@ -8158,7 +8158,7 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(qe.parent->name, ast_channel_uniqueid(qe.chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld", qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+			ast_queue_log(qe.parent->name, ast_channel_uniqueid(qe.chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd", qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 			break;
 		}
 
@@ -8187,8 +8187,8 @@ stop:
 			if (!qe.handled) {
 				record_abandoned(&qe);
 				ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "ABANDON",
-					"%d|%d|%ld", qe.pos, qe.opos,
-					(long) (time(NULL) - qe.start));
+					"%d|%d|%jd", qe.pos, qe.opos,
+					(intmax_t) (time(NULL) - qe.start));
 				res = -1;
 			} else if (reason == QUEUE_LEAVEEMPTY) {
 				/* Return back to dialplan, don't hang up */
@@ -8199,7 +8199,7 @@ stop:
 			}
 		} else if (qe.valid_digits) {
 			ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITWITHKEY",
-				"%s|%d|%d|%ld", qe.digits, qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+				"%s|%d|%d|%jd", qe.digits, qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 		}
 	}
 
@@ -9345,9 +9345,9 @@ static char *__queues_show(struct manses
 
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
@@ -9716,7 +9716,7 @@ static int manager_queues_status(struct 
 					"CallerIDName: %s\r\n"
 					"ConnectedLineNum: %s\r\n"
 					"ConnectedLineName: %s\r\n"
-					"Wait: %ld\r\n"
+					"Wait: %jd\r\n"
 					"Priority: %d\r\n"
 					"%s"
 					"\r\n",
@@ -9725,7 +9725,7 @@ static int manager_queues_status(struct 
 					S_COR(ast_channel_caller(qe->chan)->id.name.valid, ast_channel_caller(qe->chan)->id.name.str, "unknown"),
 					S_COR(ast_channel_connected(qe->chan)->id.number.valid, ast_channel_connected(qe->chan)->id.number.str, "unknown"),
 					S_COR(ast_channel_connected(qe->chan)->id.name.valid, ast_channel_connected(qe->chan)->id.name.str, "unknown"),
-					(long) (now - qe->start), qe->prio, idText);
+					(intmax_t) (now - qe->start), qe->prio, idText);
 				++q_items;
 			}
 		}
