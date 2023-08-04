$NetBSD: patch-ufraw__exiv2.cc,v 1.2 2023/08/04 13:11:24 gdt Exp $

Adjust to newer exiv2:
  - Change AutoPtr to UniquePtr.
  - Increase specificity of thrown errors.
  - Adapt from AnyError to the Error class.
  - value() now has fixed-width accessors, and not toLong

Not sent upstream because upstream does not seem to be maintaining
this.


--- ufraw_exiv2.cc.orig	2015-06-16 03:58:38.000000000 +0000
+++ ufraw_exiv2.cc
@@ -17,7 +17,9 @@
 #ifdef HAVE_EXIV2
 #include <exiv2/image.hpp>
 #include <exiv2/easyaccess.hpp>
+#include <exiv2/error.hpp>
 #include <exiv2/exif.hpp>
+#include <iostream>
 #include <sstream>
 #include <cassert>
 
@@ -51,7 +53,7 @@ extern "C" int ufraw_exif_read_input(ufr
         uf->inputExifBuf = NULL;
         uf->inputExifBufLen = 0;
 
-        Exiv2::Image::AutoPtr image;
+        Exiv2::Image::UniquePtr image;
         if (uf->unzippedBuf != NULL) {
             image = Exiv2::ImageFactory::open(
                         (const Exiv2::byte*)uf->unzippedBuf, uf->unzippedBufLen);
@@ -67,7 +69,7 @@ extern "C" int ufraw_exif_read_input(ufr
         if (exifData.empty()) {
             std::string error(uf->filename);
             error += ": No Exif data found in the file";
-            throw Exiv2::Error(1, error);
+            throw Exiv2::Error(Exiv2::ErrorCode::kerGeneralError, error);
         }
 
         /* List of tag names taken from exiv2's printSummary() in actions.cpp */
@@ -132,7 +134,7 @@ extern "C" int ufraw_exif_read_input(ufr
         ufraw_message(UFRAW_SET_LOG, "%s\n", stderror.str().c_str());
 
         return UFRAW_SUCCESS;
-    } catch (Exiv2::AnyError& e) {
+    } catch (Exiv2::Error& e) {
         std::cerr.rdbuf(savecerr);
         std::string s(e.what());
         ufraw_message(UFRAW_SET_WARNING, "%s\n", s.c_str());
@@ -152,8 +154,8 @@ static Exiv2::ExifData ufraw_prepare_exi
         /* Reset orientation tag since UFRaw already rotates the image */
         if ((pos = exifData.findKey(Exiv2::ExifKey("Exif.Image.Orientation")))
                 != exifData.end()) {
-            ufraw_message(UFRAW_SET_LOG, "Resetting %s from '%d' to '1'\n",
-                          pos->key().c_str(), pos->value().toLong());
+            ufraw_message(UFRAW_SET_LOG, "Resetting %s from '%" PRId64 "' to '1'\n",
+                          pos->key().c_str(), pos->value().toInt64());
             pos->setValue("1"); /* 1 = Normal orientation */
         }
     }
@@ -324,7 +326,7 @@ extern "C" int ufraw_exif_prepare_output
         ufraw_message(UFRAW_SET_LOG, "%s\n", stderror.str().c_str());
 
         return UFRAW_SUCCESS;
-    } catch (Exiv2::AnyError& e) {
+    } catch (Exiv2::Error& e) {
         std::cerr.rdbuf(savecerr);
         std::string s(e.what());
         ufraw_message(UFRAW_SET_WARNING, "%s\n", s.c_str());
@@ -344,7 +346,7 @@ extern "C" int ufraw_exif_write(ufraw_da
 
         char *filename =
             uf_win32_locale_filename_from_utf8(uf->conf->outputFilename);
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+        Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(filename);
         uf_win32_locale_filename_free(filename);
         assert(image.get() != 0);
 
@@ -364,7 +366,7 @@ extern "C" int ufraw_exif_write(ufraw_da
         ufraw_message(UFRAW_SET_LOG, "%s\n", stderror.str().c_str());
 
         return UFRAW_SUCCESS;
-    } catch (Exiv2::AnyError& e) {
+    } catch (Exiv2::Error& e) {
         std::cerr.rdbuf(savecerr);
         std::string s(e.what());
         ufraw_message(UFRAW_SET_WARNING, "%s\n", s.c_str());
