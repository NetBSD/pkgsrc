$NetBSD: patch-src_openrct2_platform_Platform2.h,v 1.1 2019/11/17 16:19:57 nia Exp $

Support NetBSD.

--- src/openrct2/platform/Platform2.h.orig	2019-10-28 20:18:47.000000000 +0000
+++ src/openrct2/platform/Platform2.h
@@ -33,7 +33,7 @@ namespace Platform
     std::string GetDocsPath();
     std::string GetCurrentExecutablePath();
 
-#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__)
+#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__) || defined(__NetBSD__)
     std::string GetEnvironmentPath(const char* name);
     std::string GetHomePath();
 #endif
