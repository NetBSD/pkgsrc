$NetBSD: patch-main_sched.c,v 1.1.1.1 2012/01/15 18:36:21 jnemeth Exp $

--- main/sched.c.orig	2010-12-20 17:15:54.000000000 +0000
+++ main/sched.c
@@ -553,12 +553,12 @@ void ast_sched_dump(struct ast_sched_con
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
