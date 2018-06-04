$NetBSD: patch-src_EbmlSInteger.cpp,v 1.1 2018/06/04 20:27:09 mrg Exp $

--- src/EbmlSInteger.cpp.orig	2018-04-20 11:27:20.000000000 -0700
+++ src/EbmlSInteger.cpp	2018-06-04 12:58:27.207323385 -0700
@@ -34,6 +34,7 @@
 */
 #include <cassert>
 #include <climits>
+#include <limits>
 
 #include "ebml/EbmlSInteger.h"
 
