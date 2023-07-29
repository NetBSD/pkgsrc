$NetBSD: patch-src_mongo_platform_random.cpp,v 1.1 2023/07/29 11:51:15 adam Exp $

Add NetBSD and DragonFly support.

--- src/mongo/platform/random.cpp.orig	2023-06-29 02:35:52.000000000 +0000
+++ src/mongo/platform/random.cpp
@@ -57,7 +57,7 @@
 #ifdef _WIN32
 #define SECURE_RANDOM_BCRYPT
 #elif defined(__linux__) || defined(__sun) || defined(__APPLE__) || defined(__FreeBSD__) || \
-    defined(__EMSCRIPTEN__)
+    defined(__EMSCRIPTEN__) || defined(__DragonFly__) || defined(__NetBSD__)
 #define SECURE_RANDOM_URANDOM
 #elif defined(__OpenBSD__)
 #define SECURE_RANDOM_ARCFOUR
