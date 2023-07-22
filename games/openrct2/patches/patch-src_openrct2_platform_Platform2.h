$NetBSD: patch-src_openrct2_platform_Platform2.h,v 1.3 2023/07/22 10:55:16 triaxx Exp $

Support NetBSD.

--- src/openrct2/platform/Platform2.h.orig	2020-08-15 19:13:50.000000000 +0000
+++ src/openrct2/platform/Platform2.h
@@ -37,7 +37,7 @@ namespace Platform
     rct2_time GetTimeLocal();
     rct2_date GetDateLocal();
 
-#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__)
+#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__) || defined(__NetBSD__)
     std::string GetEnvironmentPath(const char* name);
     std::string GetHomePath();
 #endif
