$NetBSD: patch-Source_App_app__config.h,v 1.1 2024/09/04 11:59:05 jperkin Exp $

Avoid FOPEN conflict with system headers.

--- Source/App/app_config.h.orig	2024-09-04 11:22:30.145799815 +0000
+++ Source/App/app_config.h
@@ -50,6 +50,7 @@ typedef enum EncPass {
 #define MAX_CHANNEL_NUMBER 6U
 #define MAX_NUM_TOKENS 210
 
+#undef FOPEN
 #ifdef _WIN32
 #define FOPEN(f, s, m) fopen_s(&f, s, m)
 #else
