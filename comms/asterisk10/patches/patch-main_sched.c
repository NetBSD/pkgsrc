$NetBSD: patch-main_sched.c,v 1.2 2012/10/09 01:36:32 jnemeth Exp $

--- main/sched.c.orig	2012-06-15 16:07:08.000000000 +0000
+++ main/sched.c
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
