$NetBSD: patch-store_source_storbase.hxx,v 1.1 2019/02/25 14:12:53 tnn Exp $

include <cstdlib> for std::free()

--- store/source/storbase.hxx.orig	2019-01-23 19:35:25.000000000 +0000
+++ store/source/storbase.hxx
@@ -38,6 +38,7 @@
 #include <stddef.h>
 #include <string.h>
 #include <utility>
+#include <cstdlib>
 
 /** @file store common internals.
 */
