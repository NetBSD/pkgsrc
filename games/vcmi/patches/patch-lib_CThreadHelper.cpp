$NetBSD: patch-lib_CThreadHelper.cpp,v 1.1 2024/08/12 11:19:26 nia Exp $

Add support for NetBSD.

--- lib/CThreadHelper.cpp.orig	2024-08-04 19:07:25.000000000 +0000
+++ lib/CThreadHelper.cpp
@@ -15,7 +15,8 @@
 #elif defined(VCMI_HAIKU)
 	#include <OS.h>
 #elif !defined(VCMI_APPLE) && !defined(VCMI_FREEBSD) && \
-	!defined(VCMI_HURD) && !defined(VCMI_OPENBSD)
+	!defined(VCMI_HURD) && !defined(VCMI_OPENBSD) && \
+	!defined(VCMI_NETBSD)
 	#include <sys/prctl.h>
 #endif
 
@@ -109,6 +110,8 @@ void setThreadName(const std::string &na
 	pthread_setname_np(name.c_str());
 #elif defined(VCMI_FREEBSD)
 	pthread_setname_np(pthread_self(), name.c_str());
+#elif defined(VCMI_NETBSD)
+	pthread_setname_np(pthread_self(), "%s", (void *)name.c_str());
 #elif defined(VCMI_HAIKU)
 	rename_thread(find_thread(NULL), name.c_str());
 #elif defined(VCMI_UNIX)
