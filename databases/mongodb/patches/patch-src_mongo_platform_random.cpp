$NetBSD: patch-src_mongo_platform_random.cpp,v 1.5 2020/02/01 20:00:08 adam Exp $

Add NetBSD and DragonFly support.

--- src/mongo/platform/random.cpp.orig	2019-12-04 23:29:59.000000000 +0000
+++ src/mongo/platform/random.cpp
@@ -148,7 +148,7 @@ std::unique_ptr<SecureRandom> SecureRand
 }
 
 #elif defined(__linux__) || defined(__sun) || defined(__APPLE__) || defined(__FreeBSD__) || \
-    defined(__EMSCRIPTEN__)
+    defined(__EMSCRIPTEN__) || defined(__DragonFly__) || defined(__NetBSD__)
 
 class InputStreamSecureRandom : public SecureRandom {
 public:
