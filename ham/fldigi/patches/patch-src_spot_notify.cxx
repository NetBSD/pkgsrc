$NetBSD: patch-src_spot_notify.cxx,v 1.1 2013/05/06 14:49:32 joerg Exp $

--- src/spot/notify.cxx.orig	2013-05-03 14:35:28.000000000 +0000
+++ src/spot/notify.cxx
@@ -33,7 +33,10 @@
 #include <cctype>
 #include <cstdlib>
 
-#if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)
+#if __cplusplus >= 201103L
+#  define MAP_TYPE std::unordered_map
+#  include <unordered_map>
+#elif (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)
 #  define MAP_TYPE std::tr1::unordered_map
 #  include <tr1/unordered_map>
 #else
