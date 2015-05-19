$NetBSD: patch-apps_app__followme.c,v 1.2 2015/05/19 07:52:14 jnemeth Exp $

--- apps/app_followme.c.orig	2012-09-06 00:59:23.000000000 +0000
+++ apps/app_followme.c
@@ -372,7 +372,7 @@ static struct number *create_followme_nu
 		*tmp = '\0';
 	ast_copy_string(cur->number, buf, sizeof(cur->number));
 	cur->order = numorder;
-	ast_debug(1, "Created a number, %s, order of , %d, with a timeout of %ld.\n", cur->number, cur->order, cur->timeout);
+	ast_debug(1, "Created a number, %s, order of , %d, with a timeout of %jd.\n", cur->number, cur->order, (intmax_t)cur->timeout);
 
 	return cur;
 }
@@ -1008,7 +1008,7 @@ static struct ast_channel *findmeexec(st
 			break;
 		}
 
-		ast_debug(2, "Number(s) %s timeout %ld\n", nm->number, nm->timeout);
+		ast_debug(2, "Number(s) %s timeout %jd\n", nm->number, (intmax_t)nm->timeout);
 
 		/*
 		 * Put all active outgoing channels into autoservice.
@@ -1284,12 +1284,12 @@ static void end_bridge_callback(void *da
 
 	ast_channel_lock(chan);
 	if (ast_channel_cdr(chan)->answer.tv_sec) {
-		snprintf(buf, sizeof(buf), "%ld", (long) end - ast_channel_cdr(chan)->answer.tv_sec);
+		snprintf(buf, sizeof(buf), "%jd", (intmax_t) end - ast_channel_cdr(chan)->answer.tv_sec);
 		pbx_builtin_setvar_helper(chan, "ANSWEREDTIME", buf);
 	}
 
 	if (ast_channel_cdr(chan)->start.tv_sec) {
-		snprintf(buf, sizeof(buf), "%ld", (long) end - ast_channel_cdr(chan)->start.tv_sec);
+		snprintf(buf, sizeof(buf), "%jd", (intmax_t) end - ast_channel_cdr(chan)->start.tv_sec);
 		pbx_builtin_setvar_helper(chan, "DIALEDTIME", buf);
 	}
 	ast_channel_unlock(chan);
