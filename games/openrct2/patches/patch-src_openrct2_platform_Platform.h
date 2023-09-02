$NetBSD: patch-src_openrct2_platform_Platform.h,v 1.1 2023/09/02 07:30:35 triaxx Exp $

Support NetBSD.

--- src/openrct2/platform/Platform.h.orig	2022-04-25 17:21:38.000000000 +0000
+++ src/openrct2/platform/Platform.h
@@ -92,7 +92,7 @@ namespace Platform
     std::string GetUsername();
 
     std::string GetSteamPath();
-#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__)
+#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__) || defined(__NetBSD__)
     std::string GetEnvironmentPath(const char* name);
     std::string GetHomePath();
 #endif
