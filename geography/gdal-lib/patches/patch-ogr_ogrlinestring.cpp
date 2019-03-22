$NetBSD: patch-ogr_ogrlinestring.cpp,v 1.2 2019/03/22 15:31:11 gdt Exp $

Include required header for std::fabs.  From upstream.

--- ogr/ogrlinestring.cpp.orig	2019-03-15 12:35:19.000000000 +0000
+++ ogr/ogrlinestring.cpp
@@ -31,6 +31,7 @@
 #include "ogr_geos.h"
 #include "ogr_p.h"
 
+#include <cmath>
 #include <cstdlib>
 #include <algorithm>
 #include <limits>
