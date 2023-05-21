$NetBSD: patch-src_cache.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/cache.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/cache.cpp
@@ -263,9 +263,9 @@ namespace {
 
 				if (!is) {
 					if (s.warn_missing) {
-						Output::Warning("Image not found: {}/{}", s.directory, filename);
+						Output::Warning("Image not found: {}/{}", std::string(s.directory), std::string(filename));
 					} else {
-						Output::Debug("Image not found: {}/{}", s.directory, filename);
+						Output::Debug("Image not found: {}/{}", std::string(s.directory), std::string(filename));
 						bmp = CreateEmpty<T>();
 					}
 				} else {
@@ -274,7 +274,7 @@ namespace {
 							T == Material::System ? Bitmap::Flag_System : 0);
 					bmp = Bitmap::Create(std::move(is), transparent, flags);
 					if (!bmp) {
-						Output::Warning("Invalid image: {}/{}", s.directory, filename);
+						Output::Warning("Invalid image: {}/{}", std::string(s.directory), std::string(filename));
 					}
 				}
 			}
@@ -307,7 +307,7 @@ namespace {
 
 			if (w < min_w || max_w < w || h < min_h || max_h < h) {
 				Output::Debug("Image size out of bounds: {}/{} ({}x{} < {}x{} < {}x{})",
-							  s.directory, filename, min_w, min_h, w, h, max_w, max_h);
+							  std::string(s.directory), std::string(filename), min_w, min_h, w, h, max_w, max_h);
 			}
 		}
 
@@ -357,7 +357,7 @@ BitmapRef Cache::Faceset(StringView file
 }
 
 BitmapRef Cache::Frame(StringView file, bool transparent) {
-	return LoadBitmap<Material::Frame>(file, transparent);
+	return LoadBitmap<Material::Frame>(std::string(file), transparent);
 }
 
 BitmapRef Cache::Gameover(StringView file) {
