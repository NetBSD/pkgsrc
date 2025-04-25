$NetBSD: patch-src_progs_dyecmd_client.cpp,v 1.1 2025/04/25 08:12:38 wiz Exp $

Add header for time().

--- src/progs/dyecmd/client.cpp.orig	2025-04-25 07:50:14.418497178 +0000
+++ src/progs/dyecmd/client.cpp
@@ -88,9 +88,7 @@ PRAGMA48(GCC diagnostic pop)
 #undef ERROR
 #endif  // WIN32
 
-#ifdef __clang__
 #include <ctime>
-#endif  // __clang__
 
 #ifdef ANDROID
 #ifndef USE_SDL2
