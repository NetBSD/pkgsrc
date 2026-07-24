$NetBSD: patch-Foundation_src_Thread__POSIX.cpp,v 1.1 2026/07/24 12:15:53 adam Exp $

Support NetBSD

--- Foundation/src/Thread_POSIX.cpp.orig	2026-07-24 10:08:54.615103524 +0000
+++ Foundation/src/Thread_POSIX.cpp
@@ -386,6 +386,8 @@ void ThreadImpl::setCurrentNameImpl(cons
 #if defined(POCO_OS_FAMILY_UNIX) && !defined(POCO_VXWORKS)
 	#if (POCO_OS == POCO_OS_FREE_BSD || POCO_OS == POCO_OS_GNU_HURD)
 		pthread_setname_np(pthread_self(), truncateName(threadName).c_str());
+	#elif (POCO_OS == POCO_OS_NET_BSD)
+		pthread_setname_np(pthread_self(), truncateName(threadName).c_str(), nullptr);
 	#elif (POCO_OS == POCO_OS_MAC_OS_X)
 		#ifdef __MAC_OS_X_VERSION_MIN_REQUIRED
 			#if __MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
@@ -411,7 +413,7 @@ std::string ThreadImpl::getCurrentNameIm
 		POCO_MAX_THREAD_NAME_LEN;
 	#endif
 	char name[nameSize + 1]{'\0'};
-	#if (POCO_OS == POCO_OS_FREE_BSD || POCO_OS == POCO_OS_GNU_HURD)
+	#if (POCO_OS == POCO_OS_FREE_BSD || POCO_OS == POCO_OS_GNU_HURD || POCO_OS == POCO_OS_NET_BSD)
 		pthread_getname_np(pthread_self(), name, nameSize + 1);
 	#elif (POCO_OS == POCO_OS_MAC_OS_X)
 		#ifdef __MAC_OS_X_VERSION_MIN_REQUIRED
