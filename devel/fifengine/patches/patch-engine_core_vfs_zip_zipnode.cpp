$NetBSD: patch-engine_core_vfs_zip_zipnode.cpp,v 1.1 2022/01/09 15:30:24 wiz Exp $

Add missing header for std::find

--- engine/core/vfs/zip/zipnode.cpp.orig	2019-01-11 17:24:38.000000000 +0000
+++ engine/core/vfs/zip/zipnode.cpp
@@ -21,6 +21,8 @@
 
 // Standard C++ library includes
 
+#include <algorithm>
+
 // FIFE includes
 // These includes are split up in two parts, separated by one empty line
 // First block: files included from the FIFE root src directory
