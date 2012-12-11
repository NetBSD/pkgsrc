$NetBSD: patch-main_sched.c,v 1.1 2012/12/11 08:22:49 jnemeth Exp $

--- main/sched.c.orig	2012-06-15 16:20:16.000000000 +0000
+++ main/sched.c
@@ -349,7 +349,7 @@ static int sched_settime(struct timeval 
 {
 	struct timeval now = ast_tvnow();
 
-	/*ast_debug(1, "TV -> %lu,%lu\n", tv->tv_sec, tv->tv_usec);*/
+	/*ast_debug(1, "TV -> %jd,%jd\n", tv->tv_sec, tv->tv_usec);*/
 	if (ast_tvzero(*t))	/* not supplied, default to now */
 		*t = now;
 	*t = ast_tvadd(*t, ast_samp2tv(when, 1000));
@@ -557,12 +557,12 @@ void ast_sched_dump(struct ast_sched_con
 		struct timeval delta;
 		q = ast_heap_peek(con->sched_heap, x);
 		delta = ast_tvsub(q->when, when);
-		ast_debug(1, "|%.4d | %-15p | %-15p | %.6ld : %.6ld |\n",
+		ast_debug(1, "|%.4d | %-15p | %-15p | %.6jd : %.6jd |\n",
 			q->id,
 			q->callback,
 			q->data,
-			(long)delta.tv_sec,
-			(long int)delta.tv_usec);
+			(intmax_t)delta.tv_sec,
+			(intmax_t)delta.tv_usec);
 	}
 	ast_mutex_unlock(&con->lock);
 	ast_debug(1, "=============================================================\n");
