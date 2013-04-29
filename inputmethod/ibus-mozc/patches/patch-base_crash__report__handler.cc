$NetBSD: patch-base_crash__report__handler.cc,v 1.1 2013/04/29 09:21:24 ryoon Exp $

--- base/crash_report_handler.cc.orig	2013-03-29 04:33:43.000000000 +0000
+++ base/crash_report_handler.cc
@@ -364,7 +364,7 @@ void CrashReportHandler::SetCriticalSect
 }
 }  // namespace mozc
 
-#elif defined(OS_LINUX)  // OS_WIN
+#elif defined(OS_LINUX) || defined(OS_NETBSD) // OS_WIN
 
 namespace mozc {
 
