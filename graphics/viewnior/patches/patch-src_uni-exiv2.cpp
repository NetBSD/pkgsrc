$NetBSD: patch-src_uni-exiv2.cpp,v 1.1 2023/07/19 07:53:38 wiz Exp $

Fix build with exiv2 0.28.
https://github.com/hellosiyan/Viewnior/pull/130

--- src/uni-exiv2.cpp.orig	2018-05-13 09:40:40.000000000 +0000
+++ src/uni-exiv2.cpp
@@ -22,10 +22,20 @@
 
 #include <exiv2/exiv2.hpp>
 #include <iostream>
+#include <memory>
 
 #include "uni-exiv2.hpp"
 
-static Exiv2::Image::AutoPtr cached_image;
+#define EXIV_ERROR Exiv2::AnyError
+#ifdef EXIV2_VERSION
+    #ifdef EXIV2_TEST_VERSION
+        #if EXIV2_TEST_VERSION(0,28,0)
+            #define EXIV_ERROR Exiv2::Error
+        #endif
+    #endif
+#endif
+
+static std::unique_ptr<Exiv2::Image> cached_image;
 
 extern "C"
 void 
@@ -47,8 +57,8 @@ uni_read_exiv2_map(const char *uri, void
 {
     Exiv2::LogMsg::setLevel(Exiv2::LogMsg::mute);
     try {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(uri);
-        if ( image.get() == 0 ) {
+        std::unique_ptr<Exiv2::Image> image = Exiv2::ImageFactory::open(uri);
+        if (image == nullptr) {
             return;
         }
 
@@ -91,7 +101,7 @@ uni_read_exiv2_map(const char *uri, void
                 }
             }
         }
-    } catch (Exiv2::AnyError& e) {
+    } catch (EXIV_ERROR& e) {
         std::cerr << "Exiv2: '" << e << "'\n";
     }
 }
@@ -102,19 +112,19 @@ uni_read_exiv2_to_cache(const char *uri)
 {
     Exiv2::LogMsg::setLevel(Exiv2::LogMsg::mute);
 
-    if ( cached_image.get() != NULL ) {
+    if (cached_image != nullptr) {
         cached_image->clearMetadata();
-        cached_image.reset(NULL);
+        cached_image.reset(nullptr);
     }
 
     try {
         cached_image = Exiv2::ImageFactory::open(uri);
-        if ( cached_image.get() == 0 ) {
+        if (cached_image == nullptr) {
             return 1;
         }
 
         cached_image->readMetadata();
-    } catch (Exiv2::AnyError& e) {
+    } catch (EXIV_ERROR& e) {
         std::cerr << "Exiv2: '" << e << "'\n";
     }
 
@@ -127,13 +137,13 @@ uni_write_exiv2_from_cache(const char *u
 {
     Exiv2::LogMsg::setLevel(Exiv2::LogMsg::mute);
     
-    if ( cached_image.get() == NULL ) {
+    if (cached_image == nullptr) {
         return 1;
     }
 
     try {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(uri);
-        if ( image.get() == 0 ) {
+        std::unique_ptr<Exiv2::Image> image = Exiv2::ImageFactory::open(uri);
+        if (image == nullptr) {
             return 2;
         }
 
@@ -141,12 +151,12 @@ uni_write_exiv2_from_cache(const char *u
         image->writeMetadata();
         
         cached_image->clearMetadata();
-        cached_image.reset(NULL);
+        cached_image.reset(nullptr);
 
         return 0;
-    } catch (Exiv2::AnyError& e) {
+    } catch (EXIV_ERROR& e) {
         std::cerr << "Exiv2: '" << e << "'\n";
     }
 
     return 0;
-}
\ No newline at end of file
+}
