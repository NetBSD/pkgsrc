$NetBSD: patch-Source_UI_platform.h,v 1.1 2019/09/07 00:36:34 tsutsui Exp $

- add NetBSD denitions

--- Source/UI/platform.h.orig	2015-07-08 21:49:42.000000000 +0000
+++ Source/UI/platform.h
@@ -66,7 +66,7 @@ private:
 	int find_drive;
 										// find drive count
 #endif // _WIN32
-#ifdef __linux__
+#if defined(UNIX)
 	bool FindUp(const char *dir);
 										// find ..
 	void *dir_handle;
@@ -75,7 +75,7 @@ private:
 										// file name (shift-jis)
 	bool dir_up;
 										// FindUp() result
-#endif // __linux__
+#endif // UNIX
 };
 
 #endif // PLATFORM_H
