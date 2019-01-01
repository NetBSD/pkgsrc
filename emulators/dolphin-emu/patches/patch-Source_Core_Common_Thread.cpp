$NetBSD: patch-Source_Core_Common_Thread.cpp,v 1.1 2019/01/01 17:19:58 nia Exp $

Support NetBSD.

--- Source/Core/Common/Thread.cpp.orig	2016-06-24 08:09:07.000000000 +0000
+++ Source/Core/Common/Thread.cpp
@@ -14,6 +14,8 @@
 #include <mach/mach.h>
 #elif defined BSD4_4 || defined __FreeBSD__
 #include <pthread_np.h>
+#elif defined __NetBSD__
+#include <pthread.h>
 #endif
 
 #ifdef USE_VTUNE
@@ -135,6 +137,8 @@ void SetCurrentThreadName(const char* sz
 	pthread_setname_np(szThreadName);
 #elif defined __FreeBSD__
 	pthread_set_name_np(pthread_self(), szThreadName);
+#elif defined __NetBSD__
+	pthread_setname_np(pthread_self(), szThreadName, NULL);
 #else
 	// linux doesn't allow to set more than 16 bytes, including \0.
 	pthread_setname_np(pthread_self(), std::string(szThreadName).substr(0, 15).c_str());
