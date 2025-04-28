$NetBSD: patch-src_OdfGenerator.cxx,v 1.1 2025/04/28 20:47:00 tnn Exp $

Include <cstdint> for uint8_t.

--- src/OdfGenerator.cxx.orig	2025-04-23 07:30:10.581413641 +0000
+++ src/OdfGenerator.cxx
@@ -33,6 +33,7 @@
 #include <math.h>
 
 #include <cctype>
+#include <cstdint>
 #include <limits>
 #include <string>
 #include <stack>
