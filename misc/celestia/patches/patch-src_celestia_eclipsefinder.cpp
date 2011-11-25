$NetBSD: patch-src_celestia_eclipsefinder.cpp,v 1.1 2011/11/25 22:08:30 joerg Exp $

--- src/celestia/eclipsefinder.cpp.orig	2011-11-25 16:35:03.000000000 +0000
+++ src/celestia/eclipsefinder.cpp
@@ -10,6 +10,7 @@
 // as published by the Free Software Foundation; either version 2
 // of the License, or (at your option) any later version.
 
+#include <cstring>
 #include <string>
 #include <sstream>
 #include <algorithm>
