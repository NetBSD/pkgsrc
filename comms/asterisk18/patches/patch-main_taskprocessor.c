$NetBSD: patch-main_taskprocessor.c,v 1.1 2021/06/27 21:39:27 jnemeth Exp $

* Fix segfault under NetBSD/aarch64 9.99.80.

--- main/taskprocessor.c.orig	2021-01-21 16:28:04.000000000 +0000
+++ main/taskprocessor.c
@@ -37,6 +37,13 @@
 #include "asterisk/taskprocessor.h"
 #include "asterisk/sem.h"
 
+/* XXX, pthread_equal() is misused to compare non-valid thread pointers */
+static int
+pt_pthread_equal(pthread_t t1, pthread_t t2)
+{
+	return t1 == t2;
+}
+
 /*!
  * \brief tps_task structure is queued to a taskprocessor
  *
@@ -263,7 +270,7 @@ static void default_listener_shutdown(st
 
 	ast_assert(pvt->poll_thread != AST_PTHREADT_NULL);
 
-	if (pthread_equal(pthread_self(), pvt->poll_thread)) {
+	if (pt_pthread_equal(pthread_self(), pvt->poll_thread)) {
 		res = pthread_detach(pvt->poll_thread);
 		if (res != 0) {
 			ast_log(LOG_ERROR, "pthread_detach(): %s\n", strerror(errno));
@@ -1268,7 +1275,7 @@ int ast_taskprocessor_is_task(struct ast
 	int is_task;
 
 	ao2_lock(tps);
-	is_task = pthread_equal(tps->thread, pthread_self());
+	is_task = pt_pthread_equal(tps->thread, pthread_self());
 	ao2_unlock(tps);
 	return is_task;
 }
