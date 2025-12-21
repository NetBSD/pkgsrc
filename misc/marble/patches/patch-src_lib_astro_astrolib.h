$NetBSD: patch-src_lib_astro_astrolib.h,v 1.2 2025/12/21 14:38:39 markd Exp $

Avoid 'sun' definition.

--- src/lib/astro/astrolib.h.orig	2025-10-06 03:25:22.000000000 +0000
+++ src/lib/astro/astrolib.h
@@ -118,7 +118,7 @@ public:
     int lunar(double jd, double tdut);
 
 private:
-    Sun200 sun;
+    Sun200 msun;
     Moon200 moon;
     Vec3 rs, rm; // position of the Sun and the Moon
     Vec3 eshadow; // unit vector in direction of shadow
