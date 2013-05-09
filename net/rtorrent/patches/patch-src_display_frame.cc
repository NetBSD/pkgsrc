$NetBSD: patch-src_display_frame.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/display/frame.cc.orig	2013-05-03 22:39:08.000000000 +0000
+++ src/display/frame.cc
@@ -38,7 +38,16 @@
 
 #include <algorithm>
 #include <functional>
+#if __cplusplus >= 201103L
+using std::function;
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
 #include <tr1/functional>
+using std::tr1::function;
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
 #include <rak/algorithm.h>
 #include <torrent/exceptions.h>
 
@@ -367,9 +376,9 @@ Frame::balance_row(uint32_t x, uint32_t 
   //
   // Else if we're short, only give each what they require.
   std::stable_sort(dynamicFrames, dynamicFrames + dynamicSize,
-                   std::tr1::bind(std::greater<extent_type>(),
-                                  std::tr1::bind(&dynamic_min_height, std::tr1::placeholders::_1),
-                                  std::tr1::bind(&dynamic_min_height, std::tr1::placeholders::_2)));
+                   bind(std::greater<extent_type>(),
+                                  bind(&dynamic_min_height, STD_PLACEHOLDERS::_1),
+                                  bind(&dynamic_min_height, STD_PLACEHOLDERS::_2)));
 
   bool retry;
 
@@ -442,9 +451,9 @@ Frame::balance_column(uint32_t x, uint32
   //
   // Else if we're short, only give each what they require.
   std::stable_sort(dynamicFrames, dynamicFrames + dynamicSize,
-                   std::tr1::bind(std::greater<extent_type>(),
-                                  std::tr1::bind(&dynamic_min_width, std::tr1::placeholders::_1),
-                                  std::tr1::bind(&dynamic_min_width, std::tr1::placeholders::_2)));
+                   bind(std::greater<extent_type>(),
+                                  bind(&dynamic_min_width, STD_PLACEHOLDERS::_1),
+                                  bind(&dynamic_min_width, STD_PLACEHOLDERS::_2)));
 
   bool retry;
 
