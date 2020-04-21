$NetBSD: patch-src_lib_WPXTable.h,v 1.1 2020/04/21 18:58:18 dholland Exp $

Needs a definition for size_t.

--- src/lib/WPXTable.h~	2018-12-25 16:19:19.000000000 +0000
+++ src/lib/WPXTable.h
@@ -37,6 +37,7 @@
 #define _WPXTABLE_H
 
 #include <vector>
+#include <cstddef> // for size_t
 
 struct WPXTableCell
 {
