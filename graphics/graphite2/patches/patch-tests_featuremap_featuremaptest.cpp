$NetBSD: patch-tests_featuremap_featuremaptest.cpp,v 1.1 2025/04/30 13:56:24 tnn Exp $

Include <cstdint> for uint8_t.

--- tests/featuremap/featuremaptest.cpp.orig	2025-04-30 13:54:39.368572172 +0000
+++ tests/featuremap/featuremaptest.cpp
@@ -20,6 +20,7 @@
     internet at http://www.fsf.org/licenses/lgpl.html.
 */
 #include <cassert>
+#include <cstdint>
 #include <cstdlib>
 #include <fstream>
 #include <iostream>
