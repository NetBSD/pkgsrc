$NetBSD: patch-src_wesnoth.cpp,v 1.1 2018/06/24 16:02:50 adam Exp $

On macOS, use regular (); wesnoth_main() only needed for app bundle.

--- src/wesnoth.cpp.orig	2018-06-24 12:26:22.000000000 +0000
+++ src/wesnoth.cpp
@@ -1012,7 +1012,7 @@ static void restart_process()
 #define error_exit(res) return res
 #endif
 
-#ifdef __APPLE__
+#if 0
 extern "C" int wesnoth_main(int argc, char** argv);
 int wesnoth_main(int argc, char** argv)
 #else
