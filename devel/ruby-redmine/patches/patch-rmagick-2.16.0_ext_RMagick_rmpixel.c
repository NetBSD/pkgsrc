$NetBSD: patch-rmagick-2.16.0_ext_RMagick_rmpixel.c,v 1.1 2020/05/06 08:15:01 taca Exp $

* Fix build problem with newer ImageMagick6.

--- rmagick-2.16.0/ext/RMagick/rmpixel.c.orig	2020-04-28 14:51:55.156006214 +0000
+++ rmagick-2.16.0/ext/RMagick/rmpixel.c
@@ -533,15 +533,6 @@ Pixel_from_hsla(int argc, VALUE *argv, V
         rb_raise(rb_eRangeError, "hue %g out of range [0.0, 360.0)", h);
     }
 
-    // Ugly way of checking for change in ImageMagick 6.5.6-5 to see whether
-    // saturation/lightness should be out of 255 or out of 100.
-    if(MagickLibVersion < 0x656 ||
-        (MagickLibVersion == 0x656 && strcmp(MagickLibSubversion,"-5") <= 0) )
-    {
-      s = s/2.55;
-      l = l/2.55;
-    }
-
     memset(name, 0, sizeof(name));
     if (alpha)
     {
@@ -1041,7 +1032,7 @@ Pixel_to_color(int argc, VALUE *argv, VA
 
     exception = AcquireExceptionInfo();
 
-#if defined(HAVE_NEW_QUERYMAGICKCOLORNAME)
+#if 1
     // Support for hex-format color names moved out of QueryMagickColorname
     // in 6.4.1-9. The 'hex' argument was removed as well.
     if (hex)
