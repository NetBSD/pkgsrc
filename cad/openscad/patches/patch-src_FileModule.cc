$NetBSD: patch-src_FileModule.cc,v 1.1 2024/04/28 08:09:07 mef Exp $


boost-1.85 deleted api

--- objects/src/FileModule.o ---
src/FileModule.cc: In member function 'void FileModule::registerUse(std::__cxx11::string, const Location&)':
src/FileModule.cc:68:11: error: 'is_regular' is not a member of 'fs'
   if (fs::is_regular(path)) {
           ^~~~~~~~~~
src/FileModule.cc:68:11: note: suggested alternative: 'is_regular_file'
   if (fs::is_regular(path)) {
           ^~~~~~~~~~
           is_regular_file

--- src/FileModule.cc.orig	2021-02-01 02:41:09.000000000 +0900
+++ src/FileModule.cc	2024-04-28 16:54:35.694333460 +0900
@@ -65,7 +65,7 @@ void FileModule::registerUse(const std::
 	auto ext = fs::path(path).extension().generic_string();
 
 	if (boost::iequals(ext, ".otf") || boost::iequals(ext, ".ttf")) {
-		if (fs::is_regular(path)) {
+		if (fs::is_regular_file(path)) {
 			FontCache::instance()->register_font_file(path);
 		} else {
 			LOG(message_group::Error,Location::NONE,"","Can't read font with path '%1$s'",path);
