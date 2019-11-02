$NetBSD: patch-lib_jpegcontent.cpp,v 1.1 2019/11/02 18:39:52 maya Exp $

exiv2 0.27.0 fixes

--- lib/jpegcontent.cpp.orig	2014-09-30 09:11:42.000000000 +0000
+++ lib/jpegcontent.cpp
@@ -42,8 +42,7 @@ extern "C" {
 #include <KLocale>
 
 // Exiv2
-#include <exiv2/exif.hpp>
-#include <exiv2/image.hpp>
+#include <exiv2/exiv2.hpp>
 
 // Local
 #include "jpegerrormanager.h"
