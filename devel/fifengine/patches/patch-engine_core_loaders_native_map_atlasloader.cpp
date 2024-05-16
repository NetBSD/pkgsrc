$NetBSD: patch-engine_core_loaders_native_map_atlasloader.cpp,v 1.1 2024/05/16 13:38:42 wiz Exp $

boost 1.85 support.
https://github.com/fifengine/fifengine/issues/1085#issuecomment-2115210942

--- engine/core/loaders/native/map/atlasloader.cpp.orig	2019-01-11 17:24:38.000000000 +0000
+++ engine/core/loaders/native/map/atlasloader.cpp
@@ -312,7 +312,8 @@ namespace FIFE {
 				atlasElem->QueryValueAttribute("subimage_width", &subimageWidth);
 				atlasElem->QueryValueAttribute("subimage_height", &subimageHeight);
 				// file extension of the atlas is also used as subimage extension
-				std::string extension = bfs::extension(*atlasSource);
+                                    bfs::path p = *atlasSource;
+                                    std::string extension = p.extension().string();
 				// we need an atlas id
 				if (!atlasId) {
 					atlasId = atlasSource;
