$NetBSD: patch-src_Platforms_Gcc_UtestPlatform.cpp,v 1.1 2018/06/22 15:56:56 schmonz Exp $

Expect pid_t from fork() and waitpid().

--- src/Platforms/Gcc/UtestPlatform.cpp.orig	2018-06-22 15:45:32.759762992 +0000
+++ src/Platforms/Gcc/UtestPlatform.cpp
@@ -132,8 +132,8 @@ TestOutput::WorkingEnvironment PlatformS
 
 void (*PlatformSpecificRunTestInASeperateProcess)(UtestShell* shell, TestPlugin* plugin, TestResult* result) =
         GccPlatformSpecificRunTestInASeperateProcess;
-int (*PlatformSpecificFork)(void) = PlatformSpecificForkImplementation;
-int (*PlatformSpecificWaitPid)(int, int*, int) = PlatformSpecificWaitPidImplementation;
+pid_t (*PlatformSpecificFork)(void) = PlatformSpecificForkImplementation;
+pid_t (*PlatformSpecificWaitPid)(int, int*, int) = PlatformSpecificWaitPidImplementation;
 
 extern "C" {
 
