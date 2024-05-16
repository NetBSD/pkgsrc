$NetBSD: patch-engine_core_loaders_native_map_maploader.cpp,v 1.1 2024/05/16 13:38:42 wiz Exp $

boost 1.85 support.
https://github.com/fifengine/fifengine/issues/1085#issuecomment-2115210942

--- engine/core/loaders/native/map/maploader.cpp.orig	2019-01-11 17:24:38.000000000 +0000
+++ engine/core/loaders/native/map/maploader.cpp
@@ -838,7 +838,9 @@ namespace FIFE {
 			for (iter = files.begin(); iter != files.end(); ++iter) {
 				// TODO - vtchill - may need a way to allow clients to load things other
 				// than .xml and .zip files
-				std::string ext = bfs::extension(*iter);
+				    bfs::path p = *iter;
+                                    std::string ext = p.extension().string();
+
 				if (ext == ".xml" || ext == ".zip") {
 					loadImportFile(*iter, importDirectoryString);
 				}
