$NetBSD: patch-scipy_ndimage_src___rank__filter__1d.cpp,v 1.2 2026/01/11 08:15:05 adam Exp $

Avoid WRAP conflict from sys/termios.h on illumos.

--- scipy/ndimage/src/_rank_filter_1d.cpp.orig	2026-01-10 17:57:13.000000000 +0000
+++ scipy/ndimage/src/_rank_filter_1d.cpp
@@ -48,6 +48,7 @@ public:
   }
 };
 
+#undef WRAP
 typedef enum {
   NEAREST = 0,
   WRAP = 1,
