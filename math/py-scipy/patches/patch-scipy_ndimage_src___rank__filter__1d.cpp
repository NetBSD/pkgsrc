$NetBSD: patch-scipy_ndimage_src___rank__filter__1d.cpp,v 1.1 2025/01/07 15:38:35 jperkin Exp $

Avoid WRAP conflict from sys/termios.h on illumos.

--- scipy/ndimage/src/_rank_filter_1d.cpp.orig	2025-01-07 15:15:58.549682110 +0000
+++ scipy/ndimage/src/_rank_filter_1d.cpp
@@ -18,6 +18,7 @@ struct Mediator // this is used for rank
   int maxCt; // count of items in max heap
 };
 
+#undef WRAP
 typedef enum {
   NEAREST = 0,
   WRAP = 1,
