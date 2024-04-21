$NetBSD: patch-src_core_store_MMapDirectory.cpp,v 1.1 2024/04/21 17:28:32 adam Exp $

Fix build with newer boost.

--- src/core/store/MMapDirectory.cpp.orig	2024-04-21 17:18:00.396087158 +0000
+++ src/core/store/MMapDirectory.cpp
@@ -36,7 +36,7 @@ MMapIndexInput::MMapIndexInput(const Str
     bufferPosition = 0;
     if (!path.empty()) {
         try {
-            file.open(boost::filesystem::wpath(path), _length);
+            file.open(boost::filesystem::path(path), _length);
         } catch (...) {
             boost::throw_exception(FileNotFoundException(path));
         }
