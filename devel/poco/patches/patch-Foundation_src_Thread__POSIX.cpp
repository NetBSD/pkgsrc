$NetBSD: patch-Foundation_src_Thread__POSIX.cpp,v 1.2 2026/11/26 10:25:52 nros Exp $

Support NetBSD
Support Solaris

--- Foundation/src/Thread_POSIX.cpp.orig	2026-05-20 16:41:39.000000000 +0000
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
@@ -394,6 +396,8 @@ void ThreadImpl::setCurrentNameImpl(cons
 		#endif
 	#elif (POCO_OS == POCO_OS_QNX)
 		pthread_setname_np(pthread_self(), truncateName(threadName, _NTO_THREAD_NAME_MAX).c_str());
+	#elif (POCO_OS == POCO_OS_SOLARIS)
+	        pthread_setname_np(pthread_self(), truncateName(threadName, PTHREAD_MAX_NAMELEN_NP).c_str());
 	#else
 		prctl(PR_SET_NAME, truncateName(threadName).c_str());
 	#endif
@@ -407,11 +411,13 @@ std::string ThreadImpl::getCurrentNameIm
 	constexpr std::size_t nameSize =
 	#if (POCO_OS == POCO_OS_QNX)
 		_NTO_THREAD_NAME_MAX;
+        #elif (POCO_OS == POCO_OS_SOLARIS)
+                PTHREAD_MAX_NAMELEN_NP;
 	#else
 		POCO_MAX_THREAD_NAME_LEN;
 	#endif
 	char name[nameSize + 1]{'\0'};
-	#if (POCO_OS == POCO_OS_FREE_BSD || POCO_OS == POCO_OS_GNU_HURD)
+	#if (POCO_OS == POCO_OS_FREE_BSD || POCO_OS == POCO_OS_GNU_HURD || POCO_OS == POCO_OS_NET_BSD)
 		pthread_getname_np(pthread_self(), name, nameSize + 1);
 	#elif (POCO_OS == POCO_OS_MAC_OS_X)
 		#ifdef __MAC_OS_X_VERSION_MIN_REQUIRED
@@ -419,7 +425,7 @@ std::string ThreadImpl::getCurrentNameIm
 				pthread_getname_np(pthread_self(), name, nameSize + 1);
 			#endif
 		#endif
-	#elif (POCO_OS == POCO_OS_QNX)
+	#elif (POCO_OS == POCO_OS_QNX || POCO_OS == POCO_OS_SOLARIS)
 		pthread_getname_np(pthread_self(), name, nameSize);
 	#else
 		prctl(PR_GET_NAME, name);
