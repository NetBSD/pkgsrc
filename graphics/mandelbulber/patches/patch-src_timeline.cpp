$NetBSD: patch-src_timeline.cpp,v 1.1 2013/03/02 18:08:03 joerg Exp $

--- src/timeline.cpp.orig	2013-02-27 21:20:36.000000000 +0000
+++ src/timeline.cpp
@@ -6,6 +6,7 @@
  */
 
 #include <cstdlib>
+#include <cstring>
 
 #include "timeline.hpp"
 #include "files.h"
