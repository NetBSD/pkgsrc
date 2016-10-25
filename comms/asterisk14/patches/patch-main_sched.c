$NetBSD: patch-main_sched.c,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- main/sched.c.orig	2016-02-05 20:32:40.000000000 +0000
+++ main/sched.c
@@ -468,7 +468,7 @@ static int sched_settime(struct timeval 
 		ast_assert(0);
 	}
 
-	/*ast_debug(1, "TV -> %lu,%lu\n", tv->tv_sec, tv->tv_usec);*/
+	/*ast_debug(1, "TV -> %jd,%lu\n", (intmax_t)tv->tv_sec, tv->tv_usec);*/
 	if (ast_tvzero(*t))	/* not supplied, default to now */
 		*t = now;
 	*t = ast_tvadd(*t, ast_samp2tv(when, 1000));
@@ -696,11 +696,11 @@ void ast_sched_dump(struct ast_sched_con
 		struct timeval delta;
 		q = ast_heap_peek(con->sched_heap, x);
 		delta = ast_tvsub(q->when, when);
-		ast_debug(1, "|%.4d | %-15p | %-15p | %.6ld : %.6ld |\n",
+		ast_debug(1, "|%.4d | %-15p | %-15p | %.6jd : %.6ld |\n",
 			q->sched_id->id,
 			q->callback,
 			q->data,
-			(long)delta.tv_sec,
+			(intmax_t)delta.tv_sec,
 			(long int)delta.tv_usec);
 	}
 	ast_mutex_unlock(&con->lock);
