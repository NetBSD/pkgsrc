$NetBSD: patch-src_main.cpp,v 1.1 2021/04/04 11:10:37 nia Exp $

instead of listing a million free unixes just do !apple !win32.

--- src/main.cpp.orig	2019-07-29 10:49:37.000000000 +0000
+++ src/main.cpp
@@ -505,7 +505,7 @@ int main(int argc, char* argv[])
         // Now the program should be in app/Contents
         path.append("/Resources/");
         chdir(path.c_str());
-#elif (defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(SOLARIS)) && !defined(RELEASE_BUILD)
+#elif !defined(_WIN32)
         // Look for data files in DATADIR only if they are not available in the current directory.
         if(!std::ifstream("data/config/settings.lua").good()) {
             if(chdir(PKG_DATADIR) != 0) {
