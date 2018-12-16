$NetBSD: patch-include_CppUTest_PlatformSpecificFunctions.h,v 1.2 2018/12/16 07:02:08 schmonz Exp $

Expect pid_t from fork() and waitpid().

--- include/CppUTest/PlatformSpecificFunctions.h.orig	2016-05-25 05:41:47.000000000 +0000
+++ include/CppUTest/PlatformSpecificFunctions.h
@@ -28,13 +28,17 @@
 #ifndef PLATFORMSPECIFICFUNCTIONS_H_
 #define PLATFORMSPECIFICFUNCTIONS_H_
 
+#ifdef CPPUTEST_HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
+
 #include "CppUTest/TestOutput.h"
 TestOutput::WorkingEnvironment PlatformSpecificGetWorkingEnvironment();
 
 class TestPlugin;
 extern void (*PlatformSpecificRunTestInASeperateProcess)(UtestShell* shell, TestPlugin* plugin, TestResult* result);
-extern int (*PlatformSpecificFork)(void);
-extern int (*PlatformSpecificWaitPid)(int pid, int* status, int options);
+extern pid_t (*PlatformSpecificFork)(void);
+extern pid_t (*PlatformSpecificWaitPid)(int pid, int* status, int options);
 
 /* Platform specific interface we use in order to minimize dependencies with LibC.
  * This enables porting to different embedded platforms.
