$NetBSD: patch-src_Akai.h,v 1.1 2020/12/03 09:33:11 nia Exp $

Make this build on non-Linux non-Apple unixes.

--- src/Akai.h.orig	2019-02-20 19:12:49.000000000 +0000
+++ src/Akai.h
@@ -30,7 +30,7 @@
 # include <config.h>
 #endif
 
-#if !defined(_CARBON_) && !defined(__APPLE__) && !defined(WIN32)
+#if defined(__linux__)
 # define LINUX 1
 #endif
 
@@ -147,7 +147,7 @@ public:
 protected:
 #ifdef WIN32
   HANDLE mFile;
-#elif defined _CARBON_ || defined(__APPLE__) || LINUX
+#else
   int mFile;
 #endif
   bool mRegularFile;
