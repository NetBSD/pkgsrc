$NetBSD: patch-src_mac.cpp,v 1.1 2012/02/06 03:28:44 sbd Exp $

--- src/mac.cpp.orig	2005-04-15 09:05:46.000000000 +0000
+++ src/mac.cpp
@@ -45,7 +45,7 @@ extern "C"{
 
 static char *get_file_extname(const char *filename)
 {
-	char *ext = strrchr(filename, '.');
+	char *ext = (char *)strrchr(filename, '.');
 
 	if (ext != NULL)
 		++ext;
