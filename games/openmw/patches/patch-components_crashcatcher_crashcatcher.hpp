$NetBSD: patch-components_crashcatcher_crashcatcher.hpp,v 1.1 2021/10/22 22:43:11 nia Exp $

Needs to recognize NetBSD to avoid symbol conflicts.

--- components/crashcatcher/crashcatcher.hpp.orig	2021-10-10 16:17:03.000000000 +0000
+++ components/crashcatcher/crashcatcher.hpp
@@ -3,7 +3,7 @@
 
 #include <string>
 
-#if (defined(__APPLE__) || (defined(__linux)  &&  !defined(ANDROID)) || (defined(__unix) &&  !defined(ANDROID)) || defined(__posix))
+#if (defined(__APPLE__) || (defined(__linux)  &&  !defined(ANDROID)) || (defined(__unix) &&  !defined(ANDROID)) || defined(__posix)) || defined(__NetBSD__)
     #define USE_CRASH_CATCHER 1
 #else
     #define USE_CRASH_CATCHER 0
