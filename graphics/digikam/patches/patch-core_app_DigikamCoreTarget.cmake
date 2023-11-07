$NetBSD: patch-core_app_DigikamCoreTarget.cmake,v 1.1 2023/11/07 08:40:33 wiz Exp $

Fix build with exiv2 0.28.1.

--- core/app/DigikamCoreTarget.cmake.orig	2023-07-05 15:20:49.000000000 +0000
+++ core/app/DigikamCoreTarget.cmake
@@ -151,7 +151,7 @@ target_link_libraries(digikamcore
                       ${TIFF_LIBRARIES}
                       PNG::PNG
                       ${JPEG_LIBRARIES}
-                      exiv2lib
+                      Exiv2::exiv2lib
 
                       ${OPENMP_LDFLAGS}
 
