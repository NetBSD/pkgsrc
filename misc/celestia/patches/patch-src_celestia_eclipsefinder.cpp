$NetBSD: patch-src_celestia_eclipsefinder.cpp,v 1.2 2012/07/03 17:40:36 joerg Exp $

--- src/celestia/eclipsefinder.cpp.orig	2004-09-09 06:34:50.000000000 +0000
+++ src/celestia/eclipsefinder.cpp
@@ -10,6 +10,7 @@
 // as published by the Free Software Foundation; either version 2
 // of the License, or (at your option) any later version.
 
+#include <cstring>
 #include <string>
 #include <sstream>
 #include <algorithm>
