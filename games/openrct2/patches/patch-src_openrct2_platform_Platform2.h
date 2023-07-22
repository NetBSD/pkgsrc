$NetBSD: patch-src_openrct2_platform_Platform2.h,v 1.2 2023/07/22 02:15:16 triaxx Exp $

Support NetBSD.

--- src/openrct2/platform/Platform2.h.orig	2020-04-17 14:13:30.000000000 +0000
+++ src/openrct2/platform/Platform2.h
@@ -33,7 +33,7 @@ namespace Platform
     std::string GetDocsPath();
     std::string GetCurrentExecutablePath();
 
-#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__)
+#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__) || defined(__NetBSD__)
     std::string GetEnvironmentPath(const char* name);
     std::string GetHomePath();
 #endif
