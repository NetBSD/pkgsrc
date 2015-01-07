$NetBSD: patch-src_lib_astro_astrolib.h,v 1.1 2015/01/07 13:14:30 jperkin Exp $

Avoid 'sun' definition.

--- src/lib/astro/astrolib.h.orig	2014-10-23 21:53:08.000000000 +0000
+++ src/lib/astro/astrolib.h
@@ -139,7 +139,7 @@ class ASTROLIB_EXPORT Eclipse      // Ec
    int lunar (double jd, double tdut);
 
   private: 
-   Sun200 sun;
+   Sun200 msun;
    Moon200 moon;
    Vec3 rs, rm;   // position of the Sun and the Moon
    Vec3 eshadow;  // unit vector in direction of shadow
