$NetBSD: patch-src_lib_OpenEXR_ImfDeepTiledInputFile.h,v 1.1 2023/03/30 20:26:38 joerg Exp $

Needed for uint64_t.

--- src/lib/OpenEXR/ImfDeepTiledInputFile.h.orig	2023-03-30 00:43:02.544663712 +0000
+++ src/lib/OpenEXR/ImfDeepTiledInputFile.h
@@ -20,6 +20,7 @@
 #include "ImfTileDescription.h"
 
 #include <ImathBox.h>
+#include <cstdint>
 
 OPENEXR_IMF_INTERNAL_NAMESPACE_HEADER_ENTER
 
