$NetBSD: patch-Source_App_app__config.h,v 1.2 2026/08/12 03:41:38 ryoon Exp $

Avoid FOPEN conflict with system headers.

--- Source/App/app_config.h.orig	2026-03-23 06:52:18.000000000 +0000
+++ Source/App/app_config.h
@@ -54,6 +54,7 @@ typedef enum EncPass {
 
 #define MAX_NUM_TOKENS 210
 
+#undef FOPEN
 #ifdef _WIN32
 #define FOPEN(f, s, m) fopen_s(&f, s, m)
 #else
