$NetBSD: patch-src_paths.c,v 1.1 2020/07/10 19:33:30 adam Exp $

Fix building on Darwin.

--- src/paths.c.orig	2020-07-10 17:57:53.000000000 +0000
+++ src/paths.c
@@ -297,7 +297,7 @@ void Paths_Init(const char *argv0)
 	Paths_InitHomeDirs();
 
 	/* Init screenshot directory string */
-#if !defined(__MACOSX__)
+#if 1
 	sScreenShotDir = Str_Dup(sWorkingDir);
 #else
 	sScreenShotDir = Paths_GetMacScreenShotDir();
