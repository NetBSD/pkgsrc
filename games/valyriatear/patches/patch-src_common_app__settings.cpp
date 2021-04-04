$NetBSD: patch-src_common_app__settings.cpp,v 1.1 2021/04/04 11:10:37 nia Exp $

all non-apple unixes should keep settings in ~/.valyriatear.

--- src/common/app_settings.cpp.orig	2019-07-29 10:49:37.000000000 +0000
+++ src/common/app_settings.cpp
@@ -50,7 +50,7 @@ static void _CopyOldSaveFiles(const std:
         return;
     }
 
-#if (defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(SOLARIS))
+#if !defined(_WIN32) && !defined(__APPLE__)
     // We assume the old save files are in ~/.valyriatear
     passwd *pw = getpwuid(getuid());
     if(!pw)
@@ -104,7 +104,7 @@ static void _CopyOldSettingsFile(const s
         return;
     }
 
-#if (defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(SOLARIS))
+#if !defined(_WIN32) && !defined(__APPLE__)
     // We assume the old settings.lua file is in ~/.valyriatear
     passwd *pw = getpwuid(getuid());
     if(!pw)
