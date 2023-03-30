$NetBSD: patch-src_lib_OpenEXR_ImfDeepTiledInputPart.h,v 1.1 2023/03/30 20:26:38 joerg Exp $

Needed for uint64_t.

--- src/lib/OpenEXR/ImfDeepTiledInputPart.h.orig	2023-03-30 00:45:53.423143357 +0000
+++ src/lib/OpenEXR/ImfDeepTiledInputPart.h
@@ -11,6 +11,7 @@
 #include "ImfTileDescription.h"
 
 #include <ImathBox.h>
+#include <cstdint>
 
 OPENEXR_IMF_INTERNAL_NAMESPACE_HEADER_ENTER
 
