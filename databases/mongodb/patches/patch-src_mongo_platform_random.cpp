$NetBSD: patch-src_mongo_platform_random.cpp,v 1.2 2015/08/26 05:03:00 fhajny Exp $

Add NetBSD support.
--- src/mongo/platform/random.cpp.orig	2015-08-24 00:39:52.000000000 +0000
+++ src/mongo/platform/random.cpp
@@ -116,7 +116,7 @@ SecureRandom* SecureRandom::create() {
     return new WinSecureRandom();
 }
 
-#elif defined(__linux__) || defined(__sunos__) || defined(__APPLE__) || defined(__freebsd__)
+#elif defined(__linux__) || defined(__sunos__) || defined(__APPLE__) || defined(__freebsd__) || defined(__netbsd__)
 
 class InputStreamSecureRandom : public SecureRandom {
 public:
