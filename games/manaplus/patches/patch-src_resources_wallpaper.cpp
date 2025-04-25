$NetBSD: patch-src_resources_wallpaper.cpp,v 1.1 2025/04/25 08:12:38 wiz Exp $

Add header for time().

--- src/resources/wallpaper.cpp.orig	2025-04-25 07:49:24.044195586 +0000
+++ src/resources/wallpaper.cpp
@@ -39,9 +39,7 @@
 #include <sys/time.h>
 #endif  // WIN32
 
-#ifdef __clang__
 #include <ctime>
-#endif  // __clang__
 
 #include "debug.h"
 
