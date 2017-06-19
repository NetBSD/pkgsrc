$NetBSD: patch-internal_easylogging++.h,v 1.1 2017/06/19 18:41:39 maya Exp $

NetBSD support, it's a unixy OS.

--- internal/easylogging++.h.orig	2016-09-18 20:16:04.000000000 +0000
+++ internal/easylogging++.h
@@ -99,13 +99,19 @@
 #else
 #   define ELPP_OS_FREEBSD 0
 #endif
+#if (defined(__NetBSD__))
+#   define ELPP_OS_NETBSD 1
+#else
+#   define ELPP_OS_NETBSD 0
+#endif
+
 #if (defined(__sun))
 #   define ELPP_OS_SOLARIS 1
 #else
 #   define ELPP_OS_SOLARIS 0
 #endif
 // Unix
-#if ((ELPP_OS_LINUX || ELPP_OS_MAC || ELPP_OS_FREEBSD || ELPP_OS_SOLARIS) && (!ELPP_OS_WINDOWS))
+#if ((ELPP_OS_LINUX || ELPP_OS_MAC || ELPP_OS_FREEBSD || ELPP_OS_NETBSD || ELPP_OS_SOLARIS) && (!ELPP_OS_WINDOWS))
 #   define ELPP_OS_UNIX 1
 #else
 #   define ELPP_OS_UNIX 0
@@ -6692,4 +6698,4 @@ el::base::debug::CrashHandler elCrashHan
 #else
 #   define START_EASYLOGGINGPP(argc, argv) el::Helpers::setArgs(argc, argv)
 #endif  // defined(ELPP_UNICODE)
-#endif // EASYLOGGINGPP_H
\ No newline at end of file
+#endif // EASYLOGGINGPP_H
