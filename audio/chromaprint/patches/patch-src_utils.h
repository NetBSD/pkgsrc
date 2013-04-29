$NetBSD: patch-src_utils.h,v 1.1 2013/04/29 21:31:09 joerg Exp $

--- src/utils.h.orig	2013-04-28 13:38:52.000000000 +0000
+++ src/utils.h
@@ -28,6 +28,7 @@
 #include <math.h>
 #include <stddef.h>
 #include <stdint.h>
+#include <algorithm>
 #include <limits>
 #include <iterator>
 
