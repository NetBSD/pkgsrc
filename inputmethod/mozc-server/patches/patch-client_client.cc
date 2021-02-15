$NetBSD: patch-client_client.cc,v 1.4 2021/02/15 14:50:23 ryoon Exp $

* NetBSD support

--- client/client.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ client/client.cc
@@ -867,7 +867,7 @@ bool Client::LaunchTool(const std::strin
     return false;
   }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NETBSD)
   std::string arg = "--mode=" + mode;
   if (!extra_arg.empty()) {
     arg += " ";
@@ -877,7 +877,7 @@ bool Client::LaunchTool(const std::strin
     LOG(ERROR) << "Cannot execute: " << kMozcTool << " " << arg;
     return false;
   }
-#endif  // OS_WIN || OS_LINUX || OS_ANDROID
+#endif  // OS_WIN || OS_LINUX || OS_ANDROID || OS_NETBSD
 
   // TODO(taku): move MacProcess inside SpawnMozcProcess.
   // TODO(taku): support extra_arg.
