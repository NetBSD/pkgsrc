$NetBSD: patch-ufraw__exiv2.cc,v 1.1 2019/08/20 14:31:03 gdt Exp $

Adjust to newer exiv2.

Not yet sent upstream.

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
 
@@ -67,7 +69,7 @@ extern "C" int ufraw_exif_read_input(ufr
         if (exifData.empty()) {
             std::string error(uf->filename);
             error += ": No Exif data found in the file";
-            throw Exiv2::Error(1, error);
+            throw Exiv2::Error(Exiv2::kerGeneralError, error);
         }
 
         /* List of tag names taken from exiv2's printSummary() in actions.cpp */
