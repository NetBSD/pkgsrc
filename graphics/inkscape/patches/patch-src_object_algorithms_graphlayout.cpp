$NetBSD: patch-src_object_algorithms_graphlayout.cpp,v 1.1 2023/02/02 15:26:55 tnn Exp $

graphlayout.cpp:150:32: error: implicit instantiation of undefined template 'std::array<SPItem *, 2>'
        std::array<SPItem*, 2> attachedItems;

--- src/object/algorithms/graphlayout.cpp.orig	2022-11-26 17:42:01.000000000 +0000
+++ src/object/algorithms/graphlayout.cpp
@@ -14,6 +14,7 @@
  */
 
 #include <algorithm>
+#include <array>
 #include <cstring>
 #include <iostream>
 #include <list>
