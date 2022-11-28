$NetBSD: patch-src_demangle_Utility.h,v 1.1 2022/11/28 20:50:16 jperkin Exp $

Work around ambiguous call on SunOS.

--- src/demangle/Utility.h.orig	2022-11-16 06:28:29.000000000 +0000
+++ src/demangle/Utility.h
@@ -134,7 +134,7 @@ public:
   OutputBuffer &operator<<(char C) { return (*this += C); }
 
   OutputBuffer &operator<<(long long N) {
-    return writeUnsigned(static_cast<unsigned long long>(std::abs(N)), N < 0);
+    return writeUnsigned(static_cast<unsigned long long>(std::abs((long double)N)), N < 0);
   }
 
   OutputBuffer &operator<<(unsigned long long N) {
