$NetBSD: patch-mono_metadata_w32mutex-unix.c,v 1.1 2020/02/12 15:25:16 ryoon Exp $

* Workaround for NetBSD's pthread_equal

--- mono/metadata/w32mutex-unix.c.orig	2020-02-04 17:00:34.000000000 +0000
+++ mono/metadata/w32mutex-unix.c
@@ -84,7 +84,7 @@ mutex_handle_signal (MonoW32Handle *hand
 	if (mutex_handle->abandoned) {
 		mono_trace (G_LOG_LEVEL_DEBUG, MONO_TRACE_IO_LAYER_MUTEX, "%s: %s handle %p is abandoned",
 			__func__, mono_w32handle_get_typename (handle_data->type), handle_data);
-	} else if (!pthread_equal (mutex_handle->tid, tid)) {
+	} else if (!(mutex_handle->tid == tid)) {
 		mono_trace (G_LOG_LEVEL_DEBUG, MONO_TRACE_IO_LAYER_MUTEX, "%s: we don't own %s handle %p (owned by %ld, me %ld)",
 			__func__, mono_w32handle_get_typename (handle_data->type), handle_data, (long)mutex_handle->tid, (long)tid);
 		return MONO_W32HANDLE_WAIT_RET_NOT_OWNED_BY_CALLER;
@@ -118,7 +118,7 @@ mutex_handle_own (MonoW32Handle *handle_
 		__func__, mono_w32handle_get_typename (handle_data->type), handle_data, (gpointer) mutex_handle->tid, mutex_handle->recursion, (gpointer) pthread_self (), mutex_handle->recursion + 1, mutex_handle->abandoned ? "true" : "false");
 
 	if (mutex_handle->recursion != 0) {
-		g_assert (pthread_equal (pthread_self (), mutex_handle->tid));
+		g_assert ((pthread_self () == mutex_handle->tid));
 		mutex_handle->recursion++;
 	} else {
 		mutex_handle->tid = pthread_self ();
@@ -146,7 +146,7 @@ mutex_handle_is_owned (MonoW32Handle *ha
 	mono_trace (G_LOG_LEVEL_DEBUG, MONO_TRACE_IO_LAYER_MUTEX, "%s: testing ownership %s handle %p",
 		__func__, mono_w32handle_get_typename (handle_data->type), handle_data);
 
-	if (mutex_handle->recursion > 0 && pthread_equal (mutex_handle->tid, pthread_self ())) {
+	if (mutex_handle->recursion > 0 && (mutex_handle->tid == pthread_self ())) {
 		mono_trace (G_LOG_LEVEL_DEBUG, MONO_TRACE_IO_LAYER_MUTEX, "%s: %s handle %p owned by %p",
 			__func__, mono_w32handle_get_typename (handle_data->type), handle_data, (gpointer) pthread_self ());
 		return TRUE;
@@ -404,7 +404,7 @@ ves_icall_System_Threading_Mutex_Release
 	if (mutex_handle->abandoned) {
 		// The Win32 ReleaseMutex() function returns TRUE for abandoned mutexes
 		ret = TRUE;
-	} else if (!pthread_equal (mutex_handle->tid, tid)) {
+	} else if (!(mutex_handle->tid == tid)) {
 		ret = FALSE;
 
 		mono_trace (G_LOG_LEVEL_DEBUG, MONO_TRACE_IO_LAYER_MUTEX, "%s: we don't own %s handle %p (owned by %ld, me %ld)",
@@ -505,7 +505,7 @@ mono_w32mutex_abandon (MonoInternalThrea
 
 		tid = MONO_UINT_TO_NATIVE_THREAD_ID (internal->tid);
 
-		if (!pthread_equal (mutex_handle->tid, tid))
+		if (!(mutex_handle->tid == tid))
 			g_error ("%s: trying to release mutex %p acquired by thread %p from thread %p",
 				__func__, handle, (gpointer) mutex_handle->tid, (gpointer) tid);
 
