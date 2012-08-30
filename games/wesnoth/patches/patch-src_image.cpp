$NetBSD: patch-src_image.cpp,v 1.1 2012/08/30 16:24:49 adam Exp $

Fix compiling with boost-1.51.0

--- src/image.cpp.orig	2012-08-29 23:53:27.000000000 +0000
+++ src/image.cpp
@@ -349,7 +349,7 @@ size_t hash_value(const locator::value& 
 	using boost::hash_value;
 	using boost::hash_combine;
 
-	size_t hash = hash_value(val.type_);
+	size_t hash = hash_value((int)val.type_);
 	if (val.type_ == locator::FILE || val.type_ == locator::SUB_FILE) {
 		hash_combine(hash, val.filename_);
 	}
