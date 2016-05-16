$NetBSD: patch-client_client.cc,v 1.2 2016/05/16 11:51:49 ryoon Exp $

--- client/client.cc.orig	2016-05-15 08:11:10.000000000 +0000
+++ client/client.cc
@@ -891,7 +891,7 @@ bool Client::LaunchTool(const string &mo
   }
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID)\
-    || defined(OS_NACL)
+    || defined(OS_NACL) || defined(OS_NETBSD)
   string arg = "--mode=" + mode;
   if (!extra_arg.empty()) {
     arg += " ";
@@ -901,7 +901,7 @@ bool Client::LaunchTool(const string &mo
     LOG(ERROR) << "Cannot execute: " << kMozcTool << " " << arg;
     return false;
   }
-#endif  // OS_WIN || OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_WIN || OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
 
   // TODO(taku): move MacProcess inside SpawnMozcProcess.
   // TODO(taku): support extra_arg.
