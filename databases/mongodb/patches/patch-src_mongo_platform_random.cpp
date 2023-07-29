$NetBSD: patch-src_mongo_platform_random.cpp,v 1.6 2023/07/29 11:45:43 adam Exp $

Add NetBSD and DragonFly support.

--- src/mongo/platform/random.cpp.orig	2023-06-29 13:37:52.000000000 +0000
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
