$NetBSD: patch-src_frontend-common_platform__misc__unix.cpp,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/frontend-common/platform_misc_unix.cpp.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/frontend-common/platform_misc_unix.cpp
@@ -16,6 +16,8 @@ Log_SetChannel(FrontendCommon);
 #include <cstdio>
 #include <sys/wait.h>
 
+extern char **environ;
+
 static bool SetScreensaverInhibitX11(bool inhibit, const WindowInfo& wi)
 {
   TinyString command;
