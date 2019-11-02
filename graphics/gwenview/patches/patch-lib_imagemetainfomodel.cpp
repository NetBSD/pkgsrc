$NetBSD: patch-lib_imagemetainfomodel.cpp,v 1.1 2019/11/02 18:39:52 maya Exp $

Newer exiv2 fixes. (0.27.0)

--- lib/imagemetainfomodel.cpp.orig	2014-09-30 09:11:42.000000000 +0000
+++ lib/imagemetainfomodel.cpp
@@ -30,9 +30,7 @@ Foundation, Inc., 51 Franklin Street, Fi
 #include <KLocale>
 
 // Exiv2
-#include <exiv2/exif.hpp>
-#include <exiv2/image.hpp>
-#include <exiv2/iptc.hpp>
+#include <exiv2/exiv2.hpp>
 
 // Local
 
