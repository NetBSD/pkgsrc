$NetBSD: patch-src_openrct2_platform_Platform2.h,v 1.5 2023/08/31 20:39:51 triaxx Exp $

Support NetBSD.

--- src/openrct2/platform/Platform2.h.orig	2020-11-01 19:00:01.000000000 +0000
+++ src/openrct2/platform/Platform2.h
@@ -46,7 +46,7 @@ namespace Platform
     bool FindApp(const std::string& app, std::string* output);
     int32_t Execute(const std::string& command, std::string* output = nullptr);
 
-#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__)
+#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__) || defined(__NetBSD__)
     std::string GetEnvironmentPath(const char* name);
     std::string GetHomePath();
 #endif
