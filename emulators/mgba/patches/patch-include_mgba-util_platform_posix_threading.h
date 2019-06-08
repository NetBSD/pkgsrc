$NetBSD: patch-include_mgba-util_platform_posix_threading.h,v 1.1 2019/06/08 22:46:03 nia Exp $

Support NetBSD pthreads.

--- include/mgba-util/platform/posix/threading.h.orig	2019-02-25 01:33:16.000000000 +0000
+++ include/mgba-util/platform/posix/threading.h
@@ -95,6 +95,8 @@ static inline int ThreadSetName(const ch
 #elif defined(__FreeBSD__) || defined(__OpenBSD__)
 	pthread_set_name_np(pthread_self(), name);
 	return 0;
+#elif defined(__NetBSD__)
+	return pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif defined(__HAIKU__)
 	rename_thread(find_thread(NULL), name);
 	return 0;
