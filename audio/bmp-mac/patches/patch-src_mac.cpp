$NetBSD: patch-src_mac.cpp,v 1.1 2012/06/27 08:33:40 sbd Exp $

Make get_file_extname() a const function.

--- src/mac.cpp.orig	2005-04-15 09:00:01.000000000 +0000
+++ src/mac.cpp
@@ -43,9 +43,9 @@ static PlayerInfo *mac_info;
 extern "C"{
 #endif
 
-static char *get_file_extname(const char *filename)
+static const char *get_file_extname(const char *filename)
 {
-	char *ext = strrchr(filename, '.');
+	const char *ext = strrchr(filename, '.');
 
 	if (ext != NULL)
 		++ext;
