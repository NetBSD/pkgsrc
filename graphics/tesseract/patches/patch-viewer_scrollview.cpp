$NetBSD: patch-viewer_scrollview.cpp,v 1.1 2013/04/29 21:31:12 joerg Exp $

--- viewer/scrollview.cpp.orig	2013-04-29 19:49:57.000000000 +0000
+++ viewer/scrollview.cpp
@@ -39,6 +39,7 @@ const int kMaxIntPairSize = 45;  // Hold
 #include <algorithm>
 #include <vector>
 #include <string>
+#include <cstdlib>
 #include <cstring>
 #include <climits>
 
