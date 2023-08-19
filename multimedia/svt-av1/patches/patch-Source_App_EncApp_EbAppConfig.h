$NetBSD: patch-Source_App_EncApp_EbAppConfig.h,v 1.1 2023/08/19 15:03:39 jperkin Exp $

Avoid existing FOPEN define.

--- Source/App/EncApp/EbAppConfig.h.orig	2023-04-26 22:11:56.000000000 +0000
+++ Source/App/EncApp/EbAppConfig.h
@@ -121,6 +121,7 @@ extern uint32_t          app_malloc_coun
 #define MAX_CHANNEL_NUMBER 6U
 #define MAX_NUM_TOKENS 210
 
+#undef FOPEN
 #ifdef _WIN32
 #define FOPEN(f, s, m) fopen_s(&f, s, m)
 #else
