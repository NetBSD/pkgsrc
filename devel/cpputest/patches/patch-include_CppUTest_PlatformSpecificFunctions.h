$NetBSD: patch-include_CppUTest_PlatformSpecificFunctions.h,v 1.1 2018/06/22 15:56:56 schmonz Exp $

Expect pid_t from fork() and waitpid().

--- include/CppUTest/PlatformSpecificFunctions.h.orig	2016-05-25 05:41:47.000000000 +0000
+++ include/CppUTest/PlatformSpecificFunctions.h
@@ -33,8 +33,8 @@ TestOutput::WorkingEnvironment PlatformS
 
 class TestPlugin;
 extern void (*PlatformSpecificRunTestInASeperateProcess)(UtestShell* shell, TestPlugin* plugin, TestResult* result);
-extern int (*PlatformSpecificFork)(void);
-extern int (*PlatformSpecificWaitPid)(int pid, int* status, int options);
+extern pid_t (*PlatformSpecificFork)(void);
+extern pid_t (*PlatformSpecificWaitPid)(int pid, int* status, int options);
 
 /* Platform specific interface we use in order to minimize dependencies with LibC.
  * This enables porting to different embedded platforms.
