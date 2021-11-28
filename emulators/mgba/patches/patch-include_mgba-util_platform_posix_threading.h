$NetBSD: patch-include_mgba-util_platform_posix_threading.h,v 1.3 2021/11/28 11:34:14 nia Exp $

Support NetBSD pthreads.

https://github.com/mgba-emu/mgba/pull/2366

--- include/mgba-util/platform/posix/threading.h.orig	2020-01-22 02:17:11.000000000 +0000
+++ include/mgba-util/platform/posix/threading.h
@@ -94,7 +94,11 @@ static inline int ThreadSetName(const ch
 	rename_thread(find_thread(NULL), name);
 	return 0;
 #elif defined(HAVE_PTHREAD_SETNAME_NP)
+#if defined(__NetBSD__)
+	return pthread_setname_np(pthread_self(), "%s", (void *)name);
+#else
 	return pthread_setname_np(pthread_self(), name);
+#endif
 #else
 	UNUSED(name);
 	return 0;
