$NetBSD: patch-lib_timeutils.cpp,v 1.1 2019/11/02 18:39:52 maya Exp $

exiv2 0.27.0 fixes

--- lib/timeutils.cpp.orig	2014-09-30 09:11:42.000000000 +0000
+++ lib/timeutils.cpp
@@ -30,8 +30,7 @@ Foundation, Inc., 51 Franklin Street, Fi
 #include <KFileItem>
 
 // Exiv2
-#include <exiv2/exif.hpp>
-#include <exiv2/image.hpp>
+#include <exiv2/exiv2.hpp>
 
 // Local
 #include <lib/exiv2imageloader.h>
