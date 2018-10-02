$NetBSD: patch-operations_external_exr-save.cc,v 1.1 2018/10/02 13:13:37 ryoon Exp $

* Fix build with recent graphics/openexr
https://github.com/GNOME/gegl/commit/c1c3541caab485384087bbbcf1c83ef2d5bd4d43#diff-195f645c7a649bfaf41965be02fe86c4

--- operations/external/exr-save.cc.orig	2018-07-11 22:15:19.000000000 +0000
+++ operations/external/exr-save.cc
@@ -145,10 +145,10 @@ write_tiled_exr (const float       *pixe
                           &blue[0], &blue[1],
                           NULL, NULL, NULL);
     {
-    Imf::Chromaticities c1 (Imath_2_2::V2f(red[0],red[1]),
-                            Imath_2_2::V2f(green[0],green[1]),
-                            Imath_2_2::V2f(blue[0],blue[1]),
-                            Imath_2_2::V2f(wp[0],wp[1]));
+    Imf::Chromaticities c1 (Imath::V2f(red[0],red[1]),
+                            Imath::V2f(green[0],green[1]),
+                            Imath::V2f(blue[0],blue[1]),
+                            Imath::V2f(wp[0],wp[1]));
     Imf::addChromaticities (header, c1);
     }
   }
@@ -184,10 +184,10 @@ write_scanline_exr (const float       *p
                            &green[0], &green[1],
                            &blue[0], &blue[1],
                            NULL, NULL, NULL);
-    Imf::Chromaticities c1 (Imath_2_2::V2f(red[0],red[1]),
-                            Imath_2_2::V2f(green[0],green[1]),
-                            Imath_2_2::V2f(blue[0],blue[1]),
-                            Imath_2_2::V2f(wp[0],wp[1]));
+    Imf::Chromaticities c1 (Imath::V2f(red[0],red[1]),
+                            Imath::V2f(green[0],green[1]),
+                            Imath::V2f(blue[0],blue[1]),
+                            Imath::V2f(wp[0],wp[1]));
     Imf::addChromaticities (header, c1);
   }
 
