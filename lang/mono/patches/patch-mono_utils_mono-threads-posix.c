$NetBSD: patch-mono_utils_mono-threads-posix.c,v 1.3 2021/03/03 12:05:41 nia Exp $

* Workaround for NetBSD's pthread_equal

--- mono/utils/mono-threads-posix.c.orig	2020-02-04 17:00:34.000000000 +0000
+++ mono/utils/mono-threads-posix.c
@@ -224,7 +224,7 @@ mono_native_thread_id_get (void)
 gboolean
 mono_native_thread_id_equals (MonoNativeThreadId id1, MonoNativeThreadId id2)
 {
-	return pthread_equal (id1, id2);
+	return (id1 == id2);
 }
 
 /*
