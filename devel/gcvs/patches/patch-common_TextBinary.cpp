$NetBSD: patch-common_TextBinary.cpp,v 1.1 2020/04/17 00:21:56 joerg Exp $

--- common/TextBinary.cpp.orig	2020-04-16 19:58:28.460381420 +0000
+++ common/TextBinary.cpp
@@ -463,7 +463,7 @@ bool SplitPath(const char *dir, CStr & u
 
 void GetExtension(const char *file, CStr & base, CStr & ext)
 {
-	char *tmp = strrchr(file, '.');
+	const char *tmp = strrchr(file, '.');
 
 	if(tmp == 0L)
 	{
