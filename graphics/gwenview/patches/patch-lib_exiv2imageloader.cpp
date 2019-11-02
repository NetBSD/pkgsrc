$NetBSD: patch-lib_exiv2imageloader.cpp,v 1.1 2019/11/02 18:39:52 maya Exp $

exiv2 0.27.0 fixes

--- lib/exiv2imageloader.cpp.orig	2014-09-30 09:11:42.000000000 +0000
+++ lib/exiv2imageloader.cpp
@@ -28,8 +28,7 @@ Foundation, Inc., 51 Franklin Street, Fi
 // KDE
 
 // Exiv2
-#include <exiv2/error.hpp>
-#include <exiv2/types.hpp>
+#include <exiv2/exiv2.hpp>
 
 // Local
 
