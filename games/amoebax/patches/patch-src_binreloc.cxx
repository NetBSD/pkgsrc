$NetBSD: patch-src_binreloc.cxx,v 1.1 2025/09/29 14:06:05 nia Exp $

Build fixes for modern clang; via FreeBSD Ports

--- src/binreloc.cxx.orig	2009-02-28 17:38:34.000000000 +0000
+++ src/binreloc.cxx
@@ -739,7 +739,8 @@ br_strndup (const char *str, size_t size
 char *
 br_dirname (const char *path)
 {
-	char *end, *result;
+	const char *end;
+	char *result;
 
 	if (path == (const char *) NULL)
 		return (char *) NULL;
