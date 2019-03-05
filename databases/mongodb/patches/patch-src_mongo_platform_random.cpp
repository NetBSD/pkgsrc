$NetBSD: patch-src_mongo_platform_random.cpp,v 1.4 2019/03/05 19:35:58 adam Exp $

Add NetBSD support.

--- src/mongo/platform/random.cpp.orig	2019-01-30 14:26:33.000000000 +0000
+++ src/mongo/platform/random.cpp
@@ -150,7 +150,7 @@ std::unique_ptr<SecureRandom> SecureRand
     return stdx::make_unique<WinSecureRandom>();
 }
 
-#elif defined(__linux__) || defined(__sun) || defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__linux__) || defined(__sun) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 
 class InputStreamSecureRandom : public SecureRandom {
 public:
