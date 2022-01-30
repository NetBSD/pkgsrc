$NetBSD: patch-splash_SplashFontFile.cc,v 1.1 2022/01/30 12:07:02 rhialto Exp $

Avoid build break with g++ 8:

[ 98%] Linking CXX executable poppler-render
/usr/bin/ld: ../../libpoppler.so.117.0.0: undefined reference to `std::filesystem::__cxx11::path::_M_split_cmpts()'
/usr/bin/ld: ../../libpoppler.so.117.0.0: undefined reference to `std::filesystem::remove(std::filesystem::__cxx11::path const&, std::error_code&)'
collect2: error: ld returned 1 exit status

Patch is similar to upstream's issue 1203:
https://gitlab.freedesktop.org/poppler/poppler/-/issues/1203

--- splash/SplashFontFile.cc.orig	2022-01-05 12:53:41.000000000 +0000
+++ splash/SplashFontFile.cc
@@ -23,12 +23,7 @@
 #include <config.h>
 
 #include <cstdio>
-// TODO remove here and below once we depend on a new enough gcc in our CI
-#if __has_include(<filesystem>)
-#    include <filesystem>
-#else
 #    include <unistd.h>
-#endif
 #include "goo/gmem.h"
 #include "goo/GooString.h"
 #include "SplashFontFile.h"
@@ -81,13 +76,7 @@ SplashFontSrc::~SplashFontSrc()
     if (deleteSrc) {
         if (isFile) {
             if (fileName) {
-#if __has_include(<filesystem>)
-                // We don't care about any error, but we don't want it to throw
-                std::error_code error_code;
-                std::filesystem::remove(fileName->c_str(), error_code);
-#else
                 unlink(fileName->c_str());
-#endif
             }
         } else {
             if (buf)
