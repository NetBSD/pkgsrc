$NetBSD: patch-src_lib_OpenEXR_ImfTiledMisc.h,v 1.1 2023/03/30 20:26:38 joerg Exp $

Needed for uint64_t.

--- src/lib/OpenEXR/ImfTiledMisc.h.orig	2022-04-07 00:52:25.000000000 +0000
+++ src/lib/OpenEXR/ImfTiledMisc.h
@@ -17,6 +17,7 @@
 #include "ImfTileDescription.h"
 #include <ImathBox.h>
 
+#include <cstdint>
 #include <stdio.h>
 #include <vector>
 
