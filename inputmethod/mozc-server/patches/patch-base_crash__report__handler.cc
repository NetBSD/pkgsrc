$NetBSD: patch-base_crash__report__handler.cc,v 1.3 2014/01/19 01:18:50 ryoon Exp $

--- base/crash_report_handler.cc.orig	2014-01-06 07:10:31.000000000 +0000
+++ base/crash_report_handler.cc
@@ -346,7 +346,7 @@ void CrashReportHandler::SetCriticalSect
 
 }  // namespace mozc
 
-#else
+#elif defined(OS_LINUX) || defined(OS_NETBSD)  // OS_WIN
 
 namespace mozc {
 
@@ -372,4 +372,4 @@ void CrashReportHandler::SetCriticalSect
 
 }  // namespace mozc
 
-#endif
+#endif  // OS_WIN OS_LINUX OS_NETBSD
