$NetBSD: patch-client_client.cc,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- client/client.cc.orig	2013-03-29 04:33:44.000000000 +0000
+++ client/client.cc
@@ -950,7 +950,7 @@ bool Client::LaunchTool(const string &mo
     return false;
   }
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_NETBSD)
   string arg = "--mode=" + mode;
   if (!extra_arg.empty()) {
     arg += " ";
@@ -960,7 +960,7 @@ bool Client::LaunchTool(const string &mo
     LOG(ERROR) << "Cannot execute: " << kMozcTool << " " << arg;
     return false;
   }
-#endif  // OS_WIN || OS_LINUX
+#endif  // OS_WIN || OS_LINUX || OS_NETBSD
 
   // TODO(taku): move MacProcess inside SpawnMozcProcess.
   // TODO(taku): support extra_arg.
