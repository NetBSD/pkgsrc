$NetBSD: patch-base_crash__report__handler.cc,v 1.2 2013/09/07 18:42:14 ryoon Exp $

--- base/crash_report_handler.cc.orig	2013-08-28 05:26:13.000000000 +0000
+++ base/crash_report_handler.cc
@@ -321,7 +321,7 @@ void CrashReportHandler::SetCriticalSect
 }
 }  // namespace mozc
 
-#elif defined(OS_LINUX)  // OS_WIN
+#elif defined(OS_LINUX) || defined(OS_NETBSD)  // OS_WIN
 
 namespace mozc {
 
@@ -341,4 +341,4 @@ bool CrashReportHandler::Uninitialize() 
 
 }  // namespace mozc
 
-#endif  // OS_WIN OS_LINUX
+#endif  // OS_WIN OS_LINUX OS_NETBSD
