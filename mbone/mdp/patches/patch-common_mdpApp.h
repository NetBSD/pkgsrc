$NetBSD: patch-common_mdpApp.h,v 1.1 2020/05/14 19:26:01 joerg Exp $

optarg is modified in place, can't be const.

--- common/mdpApp.h.orig	2020-05-13 20:40:17.396210025 +0000
+++ common/mdpApp.h
@@ -55,7 +55,7 @@ class MdpApp
         bool Init(MdpTimerInstallCallback*  timerInstaller,
                   MdpSocketInstallCallback* sockerInstaller);
         bool Start();
-        bool ProcessCommand(char opt, const char* optarg);
+        bool ProcessCommand(char opt, char* optarg);
         const char* SessionName() {return session_name;}
         virtual void SetPostProcessor(const char* theCmd);
         void SetProcessorOpt(int i, char *opt);
