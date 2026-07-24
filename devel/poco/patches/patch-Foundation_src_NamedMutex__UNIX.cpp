$NetBSD: patch-Foundation_src_NamedMutex__UNIX.cpp,v 1.1 2026/07/24 12:15:53 adam Exp $

Support NetBSD

--- Foundation/src/NamedMutex_UNIX.cpp.orig	2015-08-04 05:20:55.000000000 +0000
+++ Foundation/src/NamedMutex_UNIX.cpp
@@ -41,7 +41,7 @@ namespace Poco {
 		unsigned short int* array;
 		struct seminfo*     __buf;
 	};
-#elif (POCO_OS == POCO_OS_HPUX)
+#elif (POCO_OS == POCO_OS_HPUX) || (POCO_OS == POCO_OS_NET_BSD)
 	union semun
 	{
 		int              val;
