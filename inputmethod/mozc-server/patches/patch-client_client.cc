$NetBSD: patch-client_client.cc,v 1.5 2024/02/10 01:17:27 ryoon Exp $

--- client/client.cc.orig	2023-12-13 09:23:05.795914176 +0000
+++ client/client.cc
@@ -897,7 +897,7 @@ bool Client::LaunchTool(const std::strin
     return false;
   }
 
-#if defined(_WIN32) || defined(__linux__)
+#if defined(_WIN32) || defined(__linux__) || defined(__NetBSD__)
   std::string arg = absl::StrCat("--mode=", mode);
   if (!extra_arg.empty()) {
     absl::StrAppend(&arg, " ", extra_arg);
