$NetBSD: patch-Foundation_include_Poco_Types.h,v 1.1 2026/07/24 12:15:52 adam Exp $

Fix build on NetBSD.
https://github.com/pocoproject/poco/issues/3654

--- Foundation/include/Poco/Types.h.orig	2026-07-24 09:31:34.035519124 +0000
+++ Foundation/include/Poco/Types.h
@@ -54,7 +54,7 @@ using UIntPtr = std::uintptr_t;
 		#if defined(__LP64__)
 			#define POCO_PTR_IS_64_BIT 1
 			#define POCO_LONG_IS_64_BIT 1
-			#if POCO_OS == POCO_OS_LINUX || POCO_OS == POCO_OS_FREE_BSD || POCO_OS == POCO_OS_ANDROID || POCO_OS == POCO_OS_AIX || POCO_OS == POCO_OS_QNX || POCO_OS == POCO_OS_SOLARIS || POCO_OS == POCO_OS_GNU_HURD
+			#if POCO_OS == POCO_OS_LINUX || POCO_OS == POCO_OS_FREE_BSD || POCO_OS == POCO_OS_ANDROID || POCO_OS == POCO_OS_AIX || POCO_OS == POCO_OS_QNX || POCO_OS == POCO_OS_SOLARIS || POCO_OS == POCO_OS_GNU_HURD || POCO_OS == POCO_OS_NET_BSD
 				#define POCO_INT64_IS_LONG 1
 			#endif
 		#endif
