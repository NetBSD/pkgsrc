$NetBSD: patch-lib_tevent_tevent__threads.c,v 1.1 2019/09/05 12:39:56 hauke Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure
    
--- lib/tevent/tevent_threads.c.orig	2019-01-15 10:07:00.000000000 +0000
+++ lib/tevent/tevent_threads.c
@@ -234,6 +234,7 @@ struct tevent_thread_proxy *tevent_threa
 		return NULL;
 	}
 
+	memset(&tp->mutex, 0, sizeof(pthread_mutex_t));
 	ret = pthread_mutex_init(&tp->mutex, NULL);
 	if (ret != 0) {
 		goto fail;
@@ -439,6 +440,7 @@ struct tevent_threaded_context *tevent_t
 	}
 	tctx->event_ctx = ev;
 
+	memset(&tctx->event_ctx_mutex, 0, sizeof(pthread_mutex_t));
 	ret = pthread_mutex_init(&tctx->event_ctx_mutex, NULL);
 	if (ret != 0) {
 		TALLOC_FREE(tctx);
