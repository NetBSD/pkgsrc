$NetBSD: patch-client_client.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- client/client.cc.orig	2012-08-31 05:36:43.000000000 +0000
+++ client/client.cc
@@ -934,7 +934,7 @@ bool Client::LaunchTool(const string &mo
     return false;
   }
 
-#if defined(OS_WINDOWS) || defined(OS_LINUX)
+#if defined(OS_WINDOWS) || defined(OS_LINUX) || defined(OS_NETBSD)
   string arg = "--mode=" + mode;
   if (!extra_arg.empty()) {
     arg += " ";
@@ -944,7 +944,7 @@ bool Client::LaunchTool(const string &mo
     LOG(ERROR) << "Cannot execute: " << kMozcTool << " " << arg;
     return false;
   }
-#endif  // OS_WINDOWS || OS_LINUX
+#endif  // OS_WINDOWS || OS_LINUX || OS_NETBSD
 
   // TODO(taku): move MacProcess inside SpawnMozcProcess.
   // TODO(taku): support extra_arg.
