$NetBSD: patch-apps_app__queue.c,v 1.6 2016/05/05 02:00:33 jnemeth Exp $

--- apps/app_queue.c.orig	2016-03-29 19:25:17.000000000 +0000
+++ apps/app_queue.c
@@ -4075,8 +4075,8 @@ static void record_abandoned(struct queu
 		"Uniqueid: %s\r\n"
 		"Position: %d\r\n"
 		"OriginalPosition: %d\r\n"
-		"HoldTime: %d\r\n",
-		qe->parent->name, ast_channel_uniqueid(qe->chan), qe->pos, qe->opos, (int)(time(NULL) - qe->start));
+		"HoldTime: %jd\r\n",
+		qe->parent->name, ast_channel_uniqueid(qe->chan), qe->pos, qe->opos, (intmax_t)(time(NULL) - qe->start));
 
 	qe->parent->callsabandoned++;
 	ao2_unlock(qe->parent);
@@ -4196,8 +4196,8 @@ static struct callattempt *wait_for_answ
 	struct ast_channel *in = qe->chan;
 	char on[80] = "";
 	char membername[80] = "";
-	long starttime = 0;
-	long endtime = 0;
+	time_t starttime = 0;
+	time_t endtime = 0;
 #ifdef HAVE_EPOLL
 	struct callattempt *epollo;
 #endif
@@ -4211,7 +4211,7 @@ static struct callattempt *wait_for_answ
 	inchan_name = ast_strdupa(ast_channel_name(qe->chan));
 	ast_channel_unlock(qe->chan);
 
-	starttime = (long) time(NULL);
+	starttime = time(NULL);
 #ifdef HAVE_EPOLL
 	for (epollo = outgoing; epollo; epollo = epollo->q_next) {
 		if (epollo->chan) {
@@ -4482,7 +4482,7 @@ static struct callattempt *wait_for_answ
 								ast_cdr_busy(ast_channel_cdr(in));
 							}
 							do_hang(o);
-							endtime = (long) time(NULL);
+							endtime = time(NULL);
 							endtime -= starttime;
 							rna(endtime * 1000, qe, on, membername, qe->parent->autopausebusy);
 							if (qe->parent->strategy != QUEUE_STRATEGY_RINGALL) {
@@ -4492,7 +4492,7 @@ static struct callattempt *wait_for_answ
 								/* Have enough time for a queue member to answer? */
 								if (ast_remaining_ms(start_time_tv, orig) > 500) {
 									ring_one(qe, outgoing, &numbusies);
-									starttime = (long) time(NULL);
+									starttime = time(NULL);
 								}
 							}
 							numbusies++;
@@ -4502,7 +4502,7 @@ static struct callattempt *wait_for_answ
 							if (ast_channel_cdr(in)) {
 								ast_cdr_busy(ast_channel_cdr(in));
 							}
-							endtime = (long) time(NULL);
+							endtime = time(NULL);
 							endtime -= starttime;
 							rna(endtime * 1000, qe, on, membername, qe->parent->autopauseunavail);
 							do_hang(o);
@@ -4512,7 +4512,7 @@ static struct callattempt *wait_for_answ
 								}
 								if (ast_remaining_ms(start_time_tv, orig) > 500) {
 									ring_one(qe, outgoing, &numbusies);
-									starttime = (long) time(NULL);
+									starttime = time(NULL);
 								}
 							}
 							numbusies++;
@@ -4598,7 +4598,7 @@ static struct callattempt *wait_for_answ
 					}
 					ast_frfree(f);
 				} else { /* ast_read() returned NULL */
-					endtime = (long) time(NULL) - starttime;
+					endtime = time(NULL) - starttime;
 					rna(endtime * 1000, qe, on, membername, 1);
 					do_hang(o);
 					if (qe->parent->strategy != QUEUE_STRATEGY_RINGALL) {
@@ -4607,7 +4607,7 @@ static struct callattempt *wait_for_answ
 						}
 						if (ast_remaining_ms(start_time_tv, orig) > 500) {
 							ring_one(qe, outgoing, &numbusies);
-							starttime = (long) time(NULL);
+							starttime = time(NULL);
 						}
 					}
 				}
@@ -4853,7 +4853,7 @@ static int wait_our_turn(struct queue_en
 
 			if ((status = get_member_status(qe->parent, qe->max_penalty, qe->min_penalty, qe->parent->leavewhenempty, 0))) {
 				*reason = QUEUE_LEAVEEMPTY;
-				ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), "NONE", "EXITEMPTY", "%d|%d|%ld", qe->pos, qe->opos, (long) (time(NULL) - qe->start));
+				ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), "NONE", "EXITEMPTY", "%d|%d|%jd", qe->pos, qe->opos, (intmax_t) (time(NULL) - qe->start));
 				leave_queue(qe);
 				break;
 			}
@@ -5103,12 +5103,12 @@ static void send_agent_complete(const st
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
 
@@ -5151,9 +5151,9 @@ static void queue_transfer_fixup(void *d
 	int callcompletedinsl = qtds->callcompletedinsl;
 	struct ast_datastore *datastore;
 
-	ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), member->membername, "TRANSFER", "%s|%s|%ld|%ld|%d",
-				ast_channel_exten(new_chan), ast_channel_context(new_chan), (long) (callstart - qe->start),
-				(long) (time(NULL) - callstart), qe->opos);
+	ast_queue_log(qe->parent->name, ast_channel_uniqueid(qe->chan), member->membername, "TRANSFER", "%s|%s|%jd|%jd|%d",
+				ast_channel_exten(new_chan), ast_channel_context(new_chan), (intmax_t) (callstart - qe->start),
+				(intmax_t) (time(NULL) - callstart), qe->opos);
 
 	update_queue(qe->parent, member, callcompletedinsl, (time(NULL) - callstart));
 
@@ -5674,7 +5674,7 @@ static int try_calling(struct queue_ent 
 			} else if (ast_check_hangup(qe->chan)) {
 				/* Caller must have hung up just before being connected */
 				ast_log(LOG_NOTICE, "Caller was about to talk to agent on %s but the caller hungup.\n", ast_channel_name(peer));
-				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "ABANDON", "%d|%d|%ld", qe->pos, qe->opos, (long) (time(NULL) - qe->start));
+				ast_queue_log(queuename, ast_channel_uniqueid(qe->chan), member->membername, "ABANDON", "%d|%d|%jd", qe->pos, qe->opos, (intmax_t) (time(NULL) - qe->start));
 				record_abandoned(qe);
 				ast_autoservice_chan_hangup_peer(qe->chan, peer);
 				ao2_ref(member, -1);
@@ -5714,8 +5714,8 @@ static int try_calling(struct queue_ent 
 		/* if setinterfacevar is defined, make member variables available to the channel */
 		/* use  pbx_builtin_setvar to set a load of variables with one call */
 		if (qe->parent->setinterfacevar) {
-			snprintf(interfacevar, sizeof(interfacevar), "MEMBERINTERFACE=%s,MEMBERNAME=%s,MEMBERCALLS=%d,MEMBERLASTCALL=%ld,MEMBERPENALTY=%d,MEMBERDYNAMIC=%d,MEMBERREALTIME=%d",
-				member->interface, member->membername, member->calls, (long)member->lastcall, member->penalty, member->dynamic, member->realtime);
+			snprintf(interfacevar, sizeof(interfacevar), "MEMBERINTERFACE=%s,MEMBERNAME=%s,MEMBERCALLS=%d,MEMBERLASTCALL=%jd,MEMBERPENALTY=%d,MEMBERDYNAMIC=%d,MEMBERREALTIME=%d",
+				member->interface, member->membername, member->calls, (intmax_t)member->lastcall, member->penalty, member->dynamic, member->realtime);
 		 	pbx_builtin_setvar_multiple(qe->chan, interfacevar);
 			pbx_builtin_setvar_multiple(peer, interfacevar);
 		}
@@ -5723,8 +5723,8 @@ static int try_calling(struct queue_ent 
 		/* if setqueueentryvar is defined, make queue entry (i.e. the caller) variables available to the channel */
 		/* use  pbx_builtin_setvar to set a load of variables with one call */
 		if (qe->parent->setqueueentryvar) {
-			snprintf(interfacevar, sizeof(interfacevar), "QEHOLDTIME=%ld,QEORIGINALPOS=%d",
-				(long) (time(NULL) - qe->start), qe->opos);
+			snprintf(interfacevar, sizeof(interfacevar), "QEHOLDTIME=%jd,QEORIGINALPOS=%d",
+				(intmax_t) (time(NULL) - qe->start), qe->opos);
 			pbx_builtin_setvar_multiple(qe->chan, interfacevar);
 			pbx_builtin_setvar_multiple(peer, interfacevar);
 		}
@@ -6018,12 +6018,12 @@ static int try_calling(struct queue_ent 
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
@@ -6055,17 +6055,17 @@ static int try_calling(struct queue_ent 
 
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
@@ -7234,8 +7234,8 @@ static int queue_exec(struct ast_channel
 		}
 	}
 
-	ast_debug(1, "queue: %s, expires: %ld, priority: %d\n",
-		args.queuename, (long)qe.expire, prio);
+	ast_debug(1, "queue: %s, expires: %jd, priority: %d\n",
+		args.queuename, (intmax_t)qe.expire, prio);
 
 	qe.chan = chan;
 	qe.prio = prio;
@@ -7285,8 +7285,8 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(args.queuename, ast_channel_uniqueid(chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld",
-				qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+			ast_queue_log(args.queuename, ast_channel_uniqueid(chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd",
+				qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 			break;
 		}
 
@@ -7331,7 +7331,7 @@ check_turns:
 			if ((status = get_member_status(qe.parent, qe.max_penalty, qe.min_penalty, qe.parent->leavewhenempty, 0))) {
 				record_abandoned(&qe);
 				reason = QUEUE_LEAVEEMPTY;
-				ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITEMPTY", "%d|%d|%ld", qe.pos, qe.opos, (long)(time(NULL) - qe.start));
+				ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITEMPTY", "%d|%d|%jd", qe.pos, qe.opos, (intmax_t)(time(NULL) - qe.start));
 				res = 0;
 				break;
 			}
@@ -7354,7 +7354,7 @@ check_turns:
 			record_abandoned(&qe);
 			reason = QUEUE_TIMEOUT;
 			res = 0;
-			ast_queue_log(qe.parent->name, ast_channel_uniqueid(qe.chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%ld", qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+			ast_queue_log(qe.parent->name, ast_channel_uniqueid(qe.chan),"NONE", "EXITWITHTIMEOUT", "%d|%d|%jd", qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 			break;
 		}
 
@@ -7382,8 +7382,8 @@ stop:
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
@@ -7391,7 +7391,7 @@ stop:
 			}
 		} else if (qe.valid_digits) {
 			ast_queue_log(args.queuename, ast_channel_uniqueid(chan), "NONE", "EXITWITHKEY",
-				"%s|%d|%d|%ld", qe.digits, qe.pos, qe.opos, (long) (time(NULL) - qe.start));
+				"%s|%d|%d|%jd", qe.digits, qe.pos, qe.opos, (intmax_t) (time(NULL) - qe.start));
 		}
 	}
 
@@ -8538,9 +8538,9 @@ static char *__queues_show(struct manses
 
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
@@ -8900,7 +8900,7 @@ static int manager_queues_status(struct 
 					"CallerIDName: %s\r\n"
 					"ConnectedLineNum: %s\r\n"
 					"ConnectedLineName: %s\r\n"
-					"Wait: %ld\r\n"
+					"Wait: %jd\r\n"
 					"%s"
 					"\r\n",
 					q->name, pos++, ast_channel_name(qe->chan), ast_channel_uniqueid(qe->chan),
@@ -8908,7 +8908,7 @@ static int manager_queues_status(struct 
 					S_COR(ast_channel_caller(qe->chan)->id.name.valid, ast_channel_caller(qe->chan)->id.name.str, "unknown"),
 					S_COR(ast_channel_connected(qe->chan)->id.number.valid, ast_channel_connected(qe->chan)->id.number.str, "unknown"),
 					S_COR(ast_channel_connected(qe->chan)->id.name.valid, ast_channel_connected(qe->chan)->id.name.str, "unknown"),
-					(long) (now - qe->start), idText);
+					(intmax_t) (now - qe->start), idText);
 			}
 		}
 		ao2_unlock(q);
