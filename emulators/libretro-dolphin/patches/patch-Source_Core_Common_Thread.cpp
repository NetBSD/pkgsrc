$NetBSD: patch-Source_Core_Common_Thread.cpp,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Source/Core/Common/Thread.cpp.orig	2018-08-27 13:59:39.000000000 +0000
+++ Source/Core/Common/Thread.cpp
@@ -18,7 +18,7 @@
 #include <mach/mach.h>
 #elif defined BSD4_4 || defined __FreeBSD__ || defined __OpenBSD__
 #include <pthread_np.h>
-#elif defined __MINGW32__
+#elif defined __NetBSD__ || defined __MINGW32__
 #include <pthread.h>
 #elif defined __HAIKU__
 #include <OS.h>
@@ -139,6 +139,8 @@ void SetCurrentThreadName(const char* sz
   pthread_setname_np(szThreadName);
 #elif defined __FreeBSD__ || defined __OpenBSD__
   pthread_set_name_np(pthread_self(), szThreadName);
+#elif defined __NetBSD__
+  pthread_setname_np(pthread_self(), szThreadName, NULL);
 #elif defined __HAIKU__
   rename_thread(find_thread(nullptr), szThreadName);
 #else
